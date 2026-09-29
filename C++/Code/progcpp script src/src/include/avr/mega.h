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

#if __has_include(<avr/io.h>)
# include <avr/io.h>
# undef _MMIO_BYTE
# define _MMIO_BYTE(adr) ((uintptr_t)(adr))
#endif

#if __has_include(<avr/pgmspace.h>)
# include <avr/pgmspace.h>
#endif

#include "bitmask.h"
#include "register.h"

namespace BMCPP {
    namespace AVR {
        struct A {};
        struct B {};
        struct C {};
        struct D {};
        struct E {};
        struct ATMega328 final {
            ATMega328() = delete;
            //[port
            struct Port final {
                Port() = delete;
                DataRegister<Port, ReadWrite, std::byte> in; 
                DataRegister<Port, ReadWrite, std::byte> ddr; 
                DataRegister<Port, ReadWrite, std::byte> out;    
                template<typename L> struct address; 
            };     
            //]
            struct Status final {
                enum class Bits : uint8_t {
                    globalIntEnable = (1 << 7), 
                    bitCopy = (1 << 6) 
                };
                ControlRegister<Status, Bits> value;
                static constexpr uint8_t address = 0x5f;
            };
        } __attribute__((packed));
        //[addresses
        template<>
        struct ATMega328::Port::address<B> {
//            inline static constexpr uintptr_t value = 0x23;
            inline static constexpr uintptr_t value = PINB;
        };
        template<>
        struct ATMega328::Port::address<C> {
            inline static constexpr uintptr_t value = 0x26;
        };
        template<>
        struct ATMega328::Port::address<D> {
            inline static constexpr uintptr_t value = 0x29;
        };
        //]
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

template<>
struct std::enable_bitmask_operators<BMCPP::AVR::ATMega328::Status::Bits> {
    inline static constexpr bool enable = true;
};

