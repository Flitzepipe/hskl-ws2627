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
#include "bitmask.h"

#if __has_include(<avr/interrupt.h>)
# include <avr/interrupt.h>
#endif

namespace BMCPP {
    namespace AVR {
        //[tags
        struct RestoreState {}; // <> end() soll die Interrupts nur dann wieder zulassen, wenn sie auch vorher schon zugelassen waren.
        struct ForceOn {}; // <> end() soll in jedem Fall die Interrupts wieder einschalten
        //]
        //[di
        template<typename T>
        class DisableInterrupt {
            static constexpr auto sreg = getAddress<ATMega328::Status>; // <> statt fest `ATMega328` besser über eine globale Typ-Deklaration für die aktuelle MCU
        public:
            typedef ATMega328::Status::Bits value_type;
            static value_type begin() {
                if constexpr(std::is_same<T, RestoreState>::value) {
                    auto v = sreg()->value.value();
                    cli();
                    return v;
                }
                else {
                    cli();
                    return value_type{0};
                }
            }
            static void end(value_type v) {
                if constexpr(std::is_same<T, RestoreState>::value) {
                    if (std::toBool(v & ATMega328::Status::Bits::globalIntEnable)) {
                        sei();
                    }
                }          
                else {
                    sei();
                }
            }
        };
        //]
        //[ei
        template<typename T>
        class EnableInterrupt {
            static constexpr auto sreg = getAddress<ATMega328::Status>;
        public:
            typedef ATMega328::Status::Bits value_type;
            
            static value_type begin() {
                if constexpr(std::is_same<T, RestoreState>::value) {
                    auto v = sreg()->value.value();
                    sei();
                    return v;
                }
                else {
                    sei();
                    return value_type{0};
                }
            }
            static void end(value_type v) {
                if constexpr(std::is_same<T, RestoreState>::value) {
                    if (!std::toBool(v & ATMega328::Status::Bits::globalIntEnable)) {
                        cli();
                    }
                }         
                else {
                    (void)v;
                    cli();
                }
            }
        };
        //]
    }
}
