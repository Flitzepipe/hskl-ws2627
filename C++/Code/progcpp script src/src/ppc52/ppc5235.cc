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

#include <cstddef>
#include <cstdint>
#include <limits>
#include <type_traits>

namespace PPC {
    //[itype
    template<typename T, T Value>
    struct integral_type {
        typedef T type;
        inline static constexpr T value  = Value;
    };
    //]
    //[tf
    typedef integral_type<bool, false> false_type;
    typedef integral_type<bool, true> true_type;
    //]
    //[cond
    template<bool V, typename T, typename F>
    struct conditional { // <> Das allgemeine template deckt den Fall `V == true` ab.
        typedef T type;
    };
    template<typename T, typename F>
    struct conditional<false, T, F> { // <> Die Spezialisierung wird für `V == false` ausgewählt
        typedef F type;
    };
    //]
    //[mintype
    namespace detail {
        template<size_t N>
        struct minimalType {
            typedef typename conditional<N <= std::numeric_limits<uint8_t>::max(), uint8_t, 
                                         typename conditional<N <= std::numeric_limits<uint16_t>::max(), uint16_t,
                                                    typename conditional<N <= std::numeric_limits<uint32_t>::max(), uint32_t, uint64_t>::type
                                                    >::type
                                         >::type type;
        };
    }
    template<size_t N>
    using minimalType = typename detail::minimalType<N>::type;
    //]
    //[array2 -r
    //[array
    template<typename T, size_t Size>
    struct array {
        //[r
        typedef minimalType<Size> size_type; // <> Die Meta-Funktion `minimalType<>` bestimmt `size_type` aus der Elementanzahl `size`.
        //]
        constexpr T& operator[](size_type index) { // <> In der Parameterliste kann nun der kleinste mögliche Datentyp verwendet werden.
            return mData[index];
        }
        constexpr size_type size() const { // <> Auch hier wird der Rückgabetyp an die Elementanzahl angepasst.
            return Size;
        }
        T mData[Size] = {};
    };
    //]
    //]
}

int main() {
    //[main
    PPC::array<char, 127>  a1;
    PPC::array<char, 1024> a2;
    PPC::array<char, 1024 * 1024> a3;
    
    static_assert(std::is_same<decltype(a1)::size_type, uint8_t>::value);
    static_assert(std::is_same<decltype(a2)::size_type, uint16_t>::value);
    static_assert(std::is_same<decltype(a3)::size_type, uint32_t>::value);
    //]
    //[cond
    typedef typename PPC::conditional<true, uint8_t, uint16_t>::type test1; // <> Hier ist `test1` ein Typ-Alias für `uint8_t`
    typedef typename PPC::conditional<false, uint8_t, uint16_t>::type test2; // <> Hier ist `test2` ein Typ-Alias für `uint16_t`
    static_assert(std::is_same<test1, uint8_t>::value);
    static_assert(std::is_same<test2, uint16_t>::value);
    //]
}
