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
        struct B {};
        struct C {};
        struct D {};
        struct E {};
        
        inline static constexpr uintptr_t ioOffset = 0x20;
        
        struct ATMega328 final {
            ATMega328() = delete;
            struct Port final {
                Port() = delete;
                volatile uint8_t in;                        
                volatile std::byte ddr;                        
                volatile uint8_t out;    
                template<typename L> struct address; // Metafunktion
            };
            struct GPIOR final {
                template<uint8_t N> struct address; // Metafunktion
            };
        } __attribute__((packed));
        
        // Metafunktion
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
        template<>
        struct ATMega328::GPIOR::address<0> {
            inline static constexpr uintptr_t value = 0x3e;
        };
        template<>
        struct ATMega328::GPIOR::address<1> {
            inline static constexpr uintptr_t value = 0x4a;
        };
        template<>
        struct ATMega328::GPIOR::address<2> {
            inline static constexpr uintptr_t value = 0x4b;
        };
        template<typename Component, uint8_t N>
        constexpr Component* getAddress() {
            return reinterpret_cast<Component*>(Component::template address<N>::value);
        }
        template<typename Component, typename Letter>
        constexpr Component* getAddress() {
            return reinterpret_cast<Component*>(Component::template address<Letter>::value);
        }
        template<typename Component, uint8_t N>
        constexpr uintptr_t getAddressValue() {
            return Component::template address<N>::value - ioOffset;
        }
    }//! AVR
}//! BMCPP

using namespace BMCPP::AVR;

template<typename Register, uint8_t N, typename FieldType>
class atomic_flags {
    inline static constexpr auto reg = getAddress<Register, N>; // Funktionszeiger
    static_assert(getAddressValue<Register, N>() < 32);
    inline static FieldType* bitField() {
        return reinterpret_cast<FieldType*>(reg());
    }
public:    
    static FieldType& get() {
        return *bitField();
    }
};

struct AppFlags final {
    bool initialized : 1;
    bool overheated  : 1;
} __attribute__((packed));

using flagsType = atomic_flags<ATMega328::GPIOR, 0, volatile AppFlags>;
static constexpr auto flags = flagsType::get;

int main() {
    flags().initialized = false;
    flags().initialized = true;
    if (flags().initialized) {
        return 2;
    }
}
