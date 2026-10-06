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

#include <string>
#include <algorithm>
#include <iostream>

namespace PPC {
    //[trait1
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
    //]
    //[trait2
    template<typename T> struct isUnsigned {
        inline static constexpr bool value = (T(-1) > T{0});  // <> Durch `T(-1)` wird ein _narrowing_ zugelassen
    };
    //]
    //[itoa1 -a
    //[itoa
    template<typename T>
    std::string itoa(T value) { // <> Das Funktionstemplate ist nur für vorzeichenlose, ganzzahlige Typen sinnvoll
        //[a
        static_assert(isInteger<T>::value, "value must be of type integer");
        static_assert(isUnsigned<T>::value, "value must be of type unsigned");
        //]
        std::string s;
        while(value > 0) {
            char digit = static_cast<char>(value % 10 + '0');
            value /= 10;
            s.push_back(digit);
        }
        std::reverse(begin(s), end(s));
        return s;
    }
    //]
    //]
}

int main() {
    //[main
    auto s1 = PPC::itoa(42u);
    std::cout << s1 << '\n';    
    //]
#if 0
    auto s2 = PPC::itoa(42.0); // <> Soll nicht möglich sein
#endif
}
