/*
 * ++C - C++ introduction
 * Copyright (C) 2013, 2014, 2015, 2016, 2017, 2018 - 2022 Wilhelm Meier <wilhelm.meier@hs-kl.de>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include "mega.h"
#include "util.h"
#include "meta.h"
#include "concepts.h"
#include "interrupts.h"

#include <specials.h>
#include <scoped.h>
#include <array>
#include <cassert>

namespace BMCPP {
    namespace AVR {
        struct Output final {
            Output() = delete;
            template<typename Port, std::byte mask>
            static inline void set() {
                Port::dir() |= mask;
            }
        };
        struct Input final {
            Input() = delete;
            template<typename Port, std::byte mask>
            static inline void set() {
                Port::dir() &= ~mask;
            }
        };
        //[port -port1
        template<typename MCUPort, typename Name>
        struct Port final {
            typedef MCUPort mcuport_type;
            typedef Name name_type;
            Port() = delete;
            static inline void set(std::byte v) {
                *getAddress<MCUPort, Name>()->out = v;
            }
            //[port1
            template<std::byte V>
            static inline void set() {
                *getAddress<MCUPort, Name>()->out = V;
            }
            //]
            [[nodiscard]] static inline volatile std::byte& get() {
                return *getAddress<MCUPort, Name>()->out;
            }
            static inline void dir(std::byte v) {
                *getAddress<MCUPort, Name>()->ddr = v;
            }
            //[port1
            template<uint8_t V>
            static inline void dir() {
                *getAddress<MCUPort, Name>()->ddr = V;
            }
            static inline volatile std::byte& dir() {
                return *getAddress<MCUPort, Name>()->ddr;
            }
            //]
            [[nodiscard]] static inline std::byte read() {
                return *getAddress<MCUPort, Name>()->in;
            }
            template<uint8_t Bit>
            static  __attribute__((always_inline)) void toggle() { // <> AVR specific toggle mechanism: write "1" to PortInputRegister
                *getAddress<MCUPort, Name>()->in |= std::byte{(1 << Bit)};
            }
            static inline void toggle(std::byte v) __attribute__((always_inline)){
                *getAddress<MCUPort, Name>()->in = v; // <> AVR specific toggle mechanism: write "1" to PortInputRegister
            }
            //[port1
            [[nodiscard]] static inline constexpr uintptr_t address() {
                return reinterpret_cast<uintptr_t>(&getAddress<MCUPort, Name>()->out);
            }
            //]
        };
        
        //]
        //[pinset -pinset1
        template<typename... Pins>
//        template<BMCPP::AVR::isPin... Pins> // <> Ergibt leider internen Compiler error (ICE).
        requires (BMCPP::AVR::isPin<Pins> && ... && true) // <> Ermöglicht dieselbe Anforderung für alle Typen des Parameter-Packs `Pins`
        class PinSet final {
        public:
            static_assert(sizeof... (Pins) <= 8, "too much pins in PinSet");
            static constexpr uint8_t size = sizeof...(Pins);
            static constexpr uint8_t pinNumbers[] = {Pins::number...};
            static constexpr std::byte pinMasks[] = {Pins::pinMask...};
            
            static constexpr std::byte setMask = (Pins::pinMask | ... | std::byte{0});
            
            using pinlist = Meta::List<Pins...>; // <> List der Pins im PinSet
            static_assert(Meta::is_set<pinlist>::value, "must use different pins in set"); // <> alle Pins sind unterschiedlich
            
            template<typename P> using port_from = typename P::port; // <> Meta-Funktion, um aus einem Pin den Port zu erhalten 
            using portlist = Meta::transform<port_from, pinlist>; // <> Die Liste der Ports als Transformation aus der Liste der Pins
            typedef typename Meta::nth_element<0, portlist> port_type; // <> Der Port des ersten Pins soll ... 
            static_assert(Meta::all_same<Meta::nth_element<0, portlist>, portlist>::value, "must use same port"); // <> ... identisch mit den Ports der anderen Pins sein
            
            static constexpr auto valueBits = [](){ // <> `constexpr`-Kontext: `valueBits` ist `constexpr`
                constexpr uint16_t numberOfPatterns = (1 << size); // <> 2^size different patterns 
                std::array<std::byte, numberOfPatterns> data;
                for(uint8_t value = 0; value < numberOfPatterns; ++value) {
                    std::byte pattern{0};
                    std::byte vv{value};
                    for(uint8_t bit = 0; bit < size; ++bit) {
                        if (std::any(vv & std::byte{0x01})) {
                            pattern |= pinMasks[bit];
                        }
                        vv >>= 1;
                    }
                    data[value] = pattern;
                }
                return data;
            }(); // <> IIFE
            
            static inline void allOn() { // <> race-free for non-overlapping PinSets
                auto v = (port_type::get() & setMask) ^ setMask;
                port_type::toggle(v);
            }
            static inline void allPullup() {
                Scoped<DisableInterrupt<RestoreState>> di;
                port_type::get() |= setMask;
            }
            static inline void allOff() { // <> race-free for non-overlapping PinSets
                auto v = port_type::get() & setMask;
                port_type::toggle(v);
            }
            static inline std::byte read() {
                return port_type::read() & setMask;
            }
            template<typename... PP>
            static inline void on() {
                static_assert(Meta::containsAll<pinlist, PP...>::value);
                constexpr std::byte mask = (PP::pinMask | ... | std::byte{0});
                if constexpr(sizeof...(PP) == 1) {
                    port_type::get() |= mask; // <> single-bit set -> sbi-instruction
                }
                else {
                    auto v = (port_type::get() & mask) ^ mask; // <> race-free for non-overlapping PinSets
                    port_type::toggle(v);
                }
            }    
            template<typename... PP>
            static inline void pullup() {
                static_assert(Meta::containsAll<pinlist, PP...>::value);
                constexpr std::byte mask = (PP::pinMask | ... | std::byte{0});
                Scoped<DisableInterrupt<RestoreState>> di;
                port_type::get() |= mask;
            }
            template<typename... PP>
            static inline void off() {
                static_assert(Meta::containsAll<pinlist, PP...>::value);
                constexpr std::byte mask = (PP::pinMask | ... | std::byte{0});
                if constexpr(sizeof...(PP) == 1) {
                    port_type::get() &= ~mask; // <> single-bit clear -> cbi
                }
                else {
                    auto v = port_type::get() & mask; // <> race-free for non-overlapping PinSets
                    port_type::toggle(v);
                }
            }  
            template<typename Dir>
            static inline void dir() {
                (Pins::template dir<Dir>(),...);
            }
            // interprets value as bits corresponding to the (not adjacent) Pins
            // Pin1 = Pin<PortB,7>
            // Pin0 = Pin<PortB,1>
            // 0b00 -> Pin1(0) Pin0(0)
            // 0b01 -> Pin1(0) Pin0(1)
            // 0b10 -> Pin1(1) Pin0(0)
            // 0b11 -> Pin1(1) Pin0(1)
#if 0 //-
            static inline void set(uint8_t value) {
                assert(value < valueBits.size); // <> Schlecht, da Laufzeitprüfung notwendig 
                auto v = (port_type::get() & setMask) ^ valueBits[value]; // <> race-free for non-overlapping PinSets
                port_type::toggle(v);
            }
#endif //-
            typedef BMCPP::Util::bitsN_t<size> bits_type;
            static inline void set(bits_type value) {
                auto v = (port_type::get() & setMask) ^ valueBits[static_cast<typename bits_type::value_type>(value)]; // <> race-free for non-overlapping PinSets
                port_type::toggle(v);
            }
            typedef BMCPP::Util::uintN_t<size> index_type;
            static inline void set(index_type value) {
                static_assert(std::numeric_limits<index_type>::max() < valueBits.size);
                auto v = (port_type::get() & setMask) ^ valueBits[value]; // <> race-free for non-overlapping PinSets
                port_type::toggle(v);
            }
            template<uint8_t V>
            static inline void set() {
                static_assert(V < valueBits.size); // <> Gut, Compilezeit-Prüfung
                auto v = (port_type::get() & setMask) ^ valueBits[V]; // <> race-free for non-overlapping PinSets
                port_type::toggle(v);
            }
        private:
            PinSet() = delete;
        };
        //]
        //[pin
        template<BMCPP::AVR::isPort Port, uint8_t PinNumber> // <> Contraint `isPort`
        struct Pin final {
            static_assert(PinNumber < 8, "wrong pin number");
            Pin() = delete;
            typedef Port port;
            static constexpr uint8_t number = PinNumber;
            static constexpr std::byte pinMask{(1 << PinNumber)};
            static inline void on() __attribute__((always_inline)) {
                Port::get() |= pinMask; // <> single bit instruction sbi
            }
            static constexpr auto& high = on;
            static constexpr auto& pullup = on;
            static inline void off() __attribute__((always_inline)) { // <> single bit instruction cbi
                Port::get() &= ~pinMask;
            }
            [[nodiscard]] static inline bool get() __attribute__((always_inline)) {
                return std::any(Port::get() & ~pinMask);
            }
            static constexpr auto& low = off;
            static inline void toggle() __attribute__((always_inline)){
                Port::template toggle<PinNumber>();
            }
            template<typename Dir>
            static inline void dir() {        
                Dir::template set<Port, pinMask>();
            }
            [[nodiscard]] static inline bool read() __attribute__((always_inline)){
                return (Port::read() & pinMask) != std::byte{0};
            }
            static constexpr auto& isHigh = read;
        };
        //]
    }
    
    template<BMCPP::AVR::isPin Pin>
    struct Set {
        static void input() {
            Pin::template dir<AVR::Input>();
        }
        static void output() {
            Pin::template dir<AVR::Output>();
        }
    };
    
}
