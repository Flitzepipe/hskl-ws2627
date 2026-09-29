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
            //[struct
            struct Port final {
                Port() = delete;
                DataRegister<Port, ReadOnly, std::byte> in; // <> Nur zu Demonstrationszwecken: auf der AVR-Plattform muss ein Schreiben möglich sein, denn damit wird der Ausgangpegel eines Pins _umgeschaltet_.
                DataRegister<Port, ReadWrite, std::byte> ddr; 
                DataRegister<Port, ReadWrite, std::byte> out;    
                template<typename L> struct address; 
            };
            //]
            //[fictional
            struct Fictional final { // <> So eine Komponente gibt es im {atmega328} nicht, nur zu Demonstrationszwecken
                Fictional() = delete;
                DataRegister<Fictional, ReadOnly, std::byte, std::byte{0xf}> a; // <> Nur die unteren 4 Bits können sinnvoll gelesen werden
                DataRegister<Fictional, UnUsed> b; // <> Kann weder gelesen noch geschrieben werden
                volatile const std::byte c; // <> Mit `const` lässt sich nur die _read-only_ Eigenschaft modellieren.
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
    //[main
    constexpr auto portb = getAddress<ATMega328::Port, B>; // <> Funktionszeiger auf Templatefunktion
    *portb()->out = 0x00_byte;
    auto x = *portb()->in;
#if 0 //-
    *portb()->in = 0x00_byte; // <> Das ist nun nicht mehr möglich.
#endif //-
    //]
    
#if 0
    //[main2
    constexpr auto fictional = getAddress<ATMega328::Fictional>;
    
    auto y = *fictional()->a; // <> `a` ist `ReadOnly`
#if 0 //-
    *fictional()->a = 0x00_byte; // <> Eine Zuweisung ist nicht möglich
#endif //-
#if 0 //-
    auto z1 = *fictional()->b; // <> nicht möglich: `b` ist `UnUsed`
    *fictional()->b = 0x03_byte ; // <> nicht möglich: `b` ist `UnUsed`
#endif //-
    auto z3 = fictional()->c; // <> Durch `volatile const` ist `c` ebenfalls `readOnly`
#if 0 //-
    fictional()->c = 0x01_byte; // <> Nicht möglich, da `readOnly`
#endif //-
    //]
#endif
    while(true){}
}
