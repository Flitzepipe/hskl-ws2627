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

namespace BMCPP {
    namespace AVR {
        struct A {};
        //[ports
        struct B {};
        struct C {};
        //]
        struct D {};
        struct E {};
        struct ATMega328 final {
            ATMega328() = delete;
            //[struct
            struct Port final {
                Port() = delete;
                volatile uint8_t in; // <> Der arithmetische Datentyp `uint8_t` ist hier sehr zweifelhaft                        
                volatile std::byte ddr; // <> Der Datentyp `std::byte` repräsentiert ein Byte, d.h. eine Zusammenfassung von 8-Bit _ohne_ eine arithmetische Interpretation
                volatile uint8_t out;    
                template<typename L> struct address; // <> Metafunktion
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
    }//! AVR
}//! BMCPP

using namespace BMCPP::AVR;

using namespace std::literals;

int main() {
    //[main
    constexpr auto portb = getAddress<ATMega328::Port, B>; // <> Funktionszeiger auf Templatefunktion
    constexpr auto portc = getAddress<ATMega328::Port, C>; // <> Funktionszeiger auf Templatefunktion
    portb()->out = 0x00; // <> Zweifelhaft: `0x00` hat den Typ `int` und wird hier implizit zu `uint8_t` gewandelt
    portb()->ddr = 0x03_byte; // <> Der Literal-Operator `byte` liefert direkt den Datentyp `std::byte`
    portb()->out = 2 * portc()->in; // <> Arithmetik möglich: eher zweifelhaft!
#if 0 //-
    portb()->ddr = 2 * portc()->in; // <> Dies ist nicht compilierbar (gut)! 
#endif //-
    //]
}
