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

#include <array>
#include <algorithm>
#include <iostream>
#include <cassert>
#include <cstdint>

namespace PPC {
    template<typename T> struct isInteger {
        inline static constexpr bool value = false;
    };
    template<> struct isInteger<char> {
        inline static constexpr bool value = true;
    };
    template<> struct isInteger<unsigned char> {
        inline static constexpr bool value = true;
    };
    template<> struct isInteger<int> {
        inline static constexpr bool value = true;
    };
    template<> struct isInteger<unsigned int> {
        inline static constexpr bool value = true;
    };
    template<typename T> struct isUnsigned {
        inline static constexpr bool value = (T(-1) > T{0}); // <> Durch `T(-1)` wird ein _narrowing_ zugelassen
    };
    //[num1 -num2
    namespace detail {
        template<typename T>
        struct numberOfDigits;
        template<> struct numberOfDigits<int8_t> {
            inline static constexpr size_t value = 4;
        };
        template<> struct numberOfDigits<uint8_t> {
            inline static constexpr size_t value = 3;
        };
        template<> struct numberOfDigits<int16_t> {
            inline static constexpr size_t value = 6;
        };
        //[num2
        template<> struct numberOfDigits<uint16_t> {
            inline static constexpr size_t value = 5;
        };
        template<> struct numberOfDigits<int32_t> {
            inline static constexpr size_t value = 11;
        };
        template<> struct numberOfDigits<uint32_t> {
            inline static constexpr size_t value = 10;
        };
        //]
    }
    //]
    //[itoa
    template<typename T, typename C>
    void itoa(T value, C& container) {
        static_assert(isInteger<T>::value, "value must be of type integer");
        static_assert(isUnsigned<T>::value, "value must be of type unsigned");
        static_assert(std::tuple_size<C>::value >= (detail::numberOfDigits<T>::value + 1), "length of container not sufficient");
        size_t p = 0;
        while(value > 0) {
            container[p++] = static_cast<char>(value % 10 + '0');
            value /= 10;
        }
        std::reverse(begin(container), begin(container) + p);
    }
    //]
}
namespace std {
    template<size_t N>
    std::ostream& operator<<(std::ostream& out, const std::array<char, N>& values) {
        for(size_t i = 0; (i < N) && (values[i] != '\0'); ++i) {
            out << values[i];
        }
        return out;
    }
}
int main() {
    //[main
    std::array<char, 11> s{};
    PPC::itoa(42u, s);
    std::cout << s << '\n';    
    //]
}
