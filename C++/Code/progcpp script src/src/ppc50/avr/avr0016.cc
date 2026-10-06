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
#include <type_traits>

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
                volatile uint8_t in;                        
                volatile uint8_t ddr;                        
                volatile uint8_t out;
                template<typename L>
                static constexpr uintptr_t address() { // `constexpr`-Funktion zur Adress-Bestimmung
                    if constexpr(std::is_same<L, B>::value) {
                        return 0x23;
                    }
                    else if constexpr(std::is_same<L, C>::value) {
                        return 0x26;
                    }
                    else if constexpr(std::is_same<L, D>::value) {
                        return 0x29;
                    }
                    else {
                        static_assert(L::value, "bla");
                        return 0x00;
                    }
                }
            };
        } __attribute__((packed));
        
        template<typename Component, uint8_t N>
        constexpr Component* getAddress() {
            return reinterpret_cast<Component*>(Component::template address<N>());
        }
        template<typename Component, typename Letter>
        constexpr Component* getAddress() {
            return reinterpret_cast<Component*>(Component::template address<Letter>());
        }
    } //! AVR
} //! BMCPP

using namespace BMCPP::AVR;

int main() {
    auto portb = getAddress<ATMega328::Port, B>();
    portb->out = 0x00;
    portb->ddr = 0x01;
    portb->out = 0x01;
}
