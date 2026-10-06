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

#include <cstdint>
#include <type_traits>
#include <limits>

namespace BMCPP {
    namespace Endianness {
        struct Little {};
        struct Big{};
        
        typedef typename std::conditional<(std::endian::native == std::endian::little), 
        Endianness::Little, Endianness::Big>::type endian_type;
    }
    
    namespace Util {
        namespace detail {
            //[typeforbits
            template<size_t Bits>
            struct TypeForBits {
                typedef typename std::conditional<Bits <= 8, uint8_t,
                                      typename std::conditional<Bits <= 16, uint16_t, uint32_t>::type>::type type;
            };
            //]
        }
        //[uintn
        template<size_t Bits>
        class uintN_t {
        public:
            typedef typename detail::TypeForBits<Bits>::type value_type;
            inline static constexpr value_type mask = ((1 << Bits) - 1);
            
            constexpr uintN_t() = default;
            constexpr explicit uintN_t(value_type v) : mValue(v & mask) {}
            
            constexpr operator value_type() const {
                return mValue;
            }
            uintN_t& operator++() {
                ++mValue;
                mValue &= mask;
                return *this;
            }
        private:
            value_type mValue{};
        };
        //]
        template<size_t Bits>
        class bitsN_t {
        public:
            inline static constexpr auto size = Bits;
            typedef typename detail::TypeForBits<Bits>::type value_type;
            inline static constexpr value_type mask = ((1 << Bits) - 1);
            
            constexpr bitsN_t() = default;
            constexpr explicit bitsN_t(value_type v) : mValue(v & mask) {}
            constexpr explicit bitsN_t(std::byte v) : mValue(std::to_integer<value_type>(v) & mask) {}
            constexpr explicit operator value_type() const {
                return mValue;
            }
        private:
            value_type mValue{};
        };

        template<typename C>        
        constexpr bool unique(const C& values) {
            for(const auto& v : values) {
                if (v) {
                    for(const auto& o : values) {
                        if (o && (&v != &o)) {
                            if (*v == *o) {
                                return false;
                            }
                        }
                    }
                }
            }
            return true;
        }   
    }
}

namespace std {
    template<size_t Bits>
    struct numeric_limits<BMCPP::Util::uintN_t<Bits>> {
        static constexpr typename BMCPP::Util::uintN_t<Bits>::value_type max() {
            return BMCPP::Util::uintN_t<Bits>::mask;
        }
    };
}