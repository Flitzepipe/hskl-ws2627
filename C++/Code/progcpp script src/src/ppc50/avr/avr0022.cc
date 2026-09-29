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

#include <cstdint>
#include <cstddef>

#include <avr/register.h>

namespace BMCPP {
    namespace AVR {
        struct A {};
        struct B {};
        struct C {};
        struct D {};
        struct E {};
        struct ATMega328 final {
            ATMega328() = delete;
            struct Port final {
                Port() = delete;
                DataRegister<Port, ReadOnly, std::byte> in; 
                DataRegister<Port, ReadWrite, std::byte> ddr; 
                DataRegister<Port, ReadWrite, std::byte> out;    
                template<typename L> struct address; 
            };
            //[fictional -fictional1 -fictional2
            struct Fictional final { // <> So eine Komponente gibt es im {atmega328} nicht, nur zu Demonstrationszwecken
                //[fictional1
                enum class Bits : uint8_t {
                    enablef1 = (1 << 0),
                    enablef2 = (1 << 3)
                };
                //]
                //[fictional2
                enum class Bats : uint8_t {
                    bla = (1 << 7)
                };
                //]
                Fictional() = delete;
                ControlRegister<Fictional, Bits> r;
                ControlRegister<Fictional, Bats> s;
                inline static constexpr uintptr_t address = 0x20; // <> Dies Adresse ist laut Datenblatt ungültig
            };
            //]
            
            
        } __attribute__((packed));
        
        template<>
        struct ATMega328::Port::address<B> {
            inline static constexpr uintptr_t value = 0x23;
        };
        template<>
        struct ATMega328::Port::address<C> {
            inline static constexpr uintptr_t value = 0x26;
        };
        template<>
        struct ATMega328::Port::address<D> {
            inline static constexpr uintptr_t value = 0x29;
        };
        template<typename Component, uint8_t N>
        constexpr Component* getAddress() {
            return reinterpret_cast<Component*>(Component::template address<N>::value);
        }
        template<typename Component, typename Letter>
        constexpr Component* getAddress() {
            return reinterpret_cast<Component*>(Component::template address<Letter>::value);
        }
        template<typename Component>
        constexpr Component* getAddress() {
            return reinterpret_cast<Component*>(Component::address);
        }
    }//! AVR
}//! BMCPP

using namespace BMCPP::AVR;
using namespace std::literals;

int main() {
    //[main1
    constexpr auto fictional = getAddress<ATMega328::Fictional>;
    fictional()->r.set(ATMega328::Fictional::Bits::enablef1);
    fictional()->r.clear<ATMega328::Fictional::Bits::enablef2>();
    //]
    //[main2
    fictional()->s.set(ATMega328::Fictional::Bats::bla);
#if 0 //-
    fictional()->s.set(ATMega328::Fictional::Bits::enablef1); // <> Nicht möglich -> Fehler zur Kompilezeit!!!
#endif //-
    //]
    while(true){}
}
