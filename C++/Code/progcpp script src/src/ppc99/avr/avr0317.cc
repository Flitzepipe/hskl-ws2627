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
#include <string.h>
#include <cassert>
#include <type_traits>
typedef uint32_t utype;

constexpr utype value = 0x01020304;

////constexpr auto x = 900'000; // long int bei AVR, sonst int
////constexpr auto x = 15 * 60 * 1000; // int bei AVR -> Overflow -17504 
//constexpr auto x{15 * 60 * 1000uz}; // unsigned int
////constexpr auto x = 15 * 60 * 1000; // unsigned long int
//std::integral_constant<decltype(x), x>::_;


int main() {
    utype a{value};
    utype b{0};
    uint8_t s[sizeof(utype)]{};

#if 1    // first     
    memcpy(s, (char*)&a, sizeof(utype));
//    assert(s[0] == (value & 0xff));
        
    memcpy(&b, s, sizeof(utype));
//    assert(b == value);

    return b;
#else
    // second    

    const uint8_t* ap = reinterpret_cast<const uint8_t*>(&a);
    s[0] = ap[0]; // explicitly legal in C++
    s[1] = ap[1];
    s[2] = ap[2];
    s[3] = ap[3];
//    assert(s[0] == (value & 0xff));

    uint8_t* bp = reinterpret_cast<uint8_t*>(&b);
    bp[0] = s[0]; // same as memcpy or ist this UB ?
    bp[1] = s[1];
    bp[2] = s[2];
    bp[3] = s[3];
    return b;
//    assert(b == value);
#endif
}
