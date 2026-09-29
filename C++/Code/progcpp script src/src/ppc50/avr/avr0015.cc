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

namespace BMCPP {
    namespace AVR {
        struct A {};
        //[ports
        struct B {};
        struct C {};
        //]
        struct D {};
        struct E {};
        //[struct
        struct ATMega328 final {
            ATMega328() = delete;
            struct Port final {
                Port() = delete;
                volatile uint8_t in;                        
                volatile uint8_t ddr;                        
                volatile uint8_t out;    
                template<typename L> struct address; // <> Deklaration der Meta-Funktion zur Address-Bestimmung
            };
        } __attribute__((packed));
        //]
        
        //[meta
        template<> // <> Metafunktion zur Adress-Bestimmung: hier die Spezialisierungen für die möglichen Abbildungen.
        struct ATMega328::Port::address<B> {
            inline static constexpr uintptr_t value = 0x23;
        };
        template<>
        struct ATMega328::Port::address<C> { // <> Die Instanziierung des allgemeinen Templates führt (sinnvollerweise) zu einem Fehler. Es muss eine dieser Spezialisierungen verwendet werden.
            inline static constexpr uintptr_t value = 0x26;
        };
        //]
        template<>
        struct ATMega328::Port::address<D> {
            inline static constexpr uintptr_t value = 0x29;
        };
        template<typename Component, uint8_t N>
        constexpr Component* getAddress() {
            return reinterpret_cast<Component*>(Component::template address<N>::value);
        }
        //[main1
        template<typename Component, typename Letter>
        constexpr Component* getAddress() { // <> Diese `constexpr`-Qualifizierung kann wegen des `reinterpret_cast<>()` nicht umgesetzt werden
            return reinterpret_cast<Component*>(Component::template address<Letter>::value);
        }
        //]
    }
}

using namespace BMCPP::AVR;

int main() {
    //[main1
    auto portb = getAddress<ATMega328::Port, B>(); // <> Hier ist `portb` ein Zeiger auf die Struktur.
    portb->out = 0x00;
    portb->ddr = 0x01;
    portb->out = 0x01;
    //]
    //[main2
    constexpr auto portc = getAddress<ATMega328::Port, C>; // <> Hier ist `portc` eine Zeiger auf die Templatefunktion (und damit `constexpr`).
    auto input = portc()->in;
    //]
}
