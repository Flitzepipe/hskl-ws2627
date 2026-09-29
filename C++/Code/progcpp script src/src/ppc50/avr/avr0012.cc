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
        struct ATMega328 final {
            ATMega328() = delete;
            struct Port final {
                Port() = delete;
                volatile uint8_t in;                        
                volatile uint8_t ddr;                        
                volatile uint8_t out;    
                inline static constexpr uintptr_t address[] = {0x23, 0x26, 0x29};
            };
        } __attribute__((packed));
    }
}

template<typename Component, uint8_t N>
Component* getAddress() {
    return reinterpret_cast<Component*>(Component::address[N]);
}
template<typename Component>
Component* getAddress(uint8_t n) {
    return reinterpret_cast<Component*>(Component::address[n]);
}

using namespace BMCPP::AVR;

int main() {
    auto portb = reinterpret_cast<ATMega328::Port*>(ATMega328::Port::address[0]);
    portb->out = 0x00;
    portb->ddr = 0x01;
    portb->out = 0x01;
    auto portc = getAddress<ATMega328::Port, 1>();
    portc->out = 0x00;
    portc->ddr = 0x01;
    portc->out = 0x02;
    auto portd = getAddress<ATMega328::Port>(2);
    portd->out = 0x00;
    portd->ddr = 0x01;
    portd->out = 0x03;
}
