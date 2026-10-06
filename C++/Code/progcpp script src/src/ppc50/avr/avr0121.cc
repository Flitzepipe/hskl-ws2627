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

#include <stdint.h>
#include <stddef.h>
#include <initializer_list>
#include <utility>
#include <type_traits>
#include <limits>
#include <array>

//[meta
namespace detail {
    template<size_t N>
    struct minimalType { // <> Meta-Funktion, um zu einer Konstanten den minimal notwendigen Datentyp zu bestimmen
        typedef typename std::conditional<N <= std::numeric_limits<uint8_t>::max(), uint_fast8_t, 
        typename std::conditional<N <= std::numeric_limits<uint16_t>::max(), uint_fast16_t,
        typename std::conditional<N <= std::numeric_limits<uint32_t>::max(), uint_fast32_t, uint_fast64_t>::type
        >::type
        >::type type;
    };
}
//[alt
template<size_t N>
using minimalType = typename detail::minimalType<N>::type; // <> Alias-Template
//]
//]

template<typename C, typename F>
void visit(const C& c, const F& f) {
    [&]<auto... II>(std::index_sequence<II...>){
        (f(c[II]),...);
    }(std::make_index_sequence<C::size>{});
}

volatile uint8_t x;

constexpr uint8_t l = 10;
std::array<uint8_t, l> array;

int main() {
    
    asm(";=l1");//-
    visit(array, [](auto v){
        x = v / 2;
    });
    asm(";=l2");//-
    for(auto& v : array) {
        x = v / 2;
    }
}
