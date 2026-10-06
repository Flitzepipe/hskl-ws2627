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

volatile uint8_t x;

//[l1
//[count
constexpr size_t count = 18; //<> Maximale Anzahl bis zu der noch unrolled wird ist 17
//]
//]
#pragma GCC push_options
#pragma GCC optimize ("O3") // <> triggert loop-unrolling, ohne unrolling (count > 17) wird mit unsigned int gerechnet
//[l1
void l1() {
    asm(";=l1"); //-
    for(size_t i = 0; i < count; ++i) { 
        x = i / 2;            
    }
}
//]
#pragma GCC pop_options
template<typename T, T... I>
void l2(std::integer_sequence<T, I...>) __attribute__((noinline));
//[l2
template<typename T, T... I>
void l2(std::integer_sequence<T, I...>) { // <> Wertetabelle im data-segment
    asm(";=l2"); //-
    for(const auto& i : {I...,}) { // <> Erzeugung der Initialisierungsliste durch die Parameter-Pack-Expansion
        x = i / 2;
    }
}
//]
//[l3
void l3() {
    asm(";=l3");//-
    using loopType = minimalType<count>; // <> Typ-Alias
    for(loopType i = 0; i < loopType{count}; ++i) { // <> optimale Variante
        x = i / 2;            
    }
}
//]
//[loop
template<typename> struct Loop; // <> Allgemeines Template
template<typename T, T... I> // <> Partielle Spezialisierung
struct Loop<std::integer_sequence<T, I...>> { // <> unbegrenzte lineare Folge
    static void loop() __attribute__((noinline)){
        asm(";=loop");//-
        ((x = T{I / 2}),...);
    }
};
//]
//[l4
namespace  {
    constexpr auto range = []() {
        std::array<minimalType<count>, count> a;
        for(size_t i = 0; i < count; ++i) {
            a[i] = i / 2;
        }
        return a;
    }();
}
void l4() {
    asm(";=l4");//-
    for(const auto& i : range) {
        x = i / 2;
    }
}
//]
//[l5
template<typename C, typename F>
void visit(const C& c, const F& f) {
    [&]<auto... II>(std::index_sequence<II...>){
        (f(c[II]),...);
    }(std::make_index_sequence<C::size>{});
}
void l5() {
    asm(";=l5");//-
    visit(range, [](auto v){
        x = v / 2;
    });
}
//]
int main() {
    asm(";=mmmm"); //-
    //[main
    l1();
    //[l2
    l2(std::make_integer_sequence<uint8_t, count>{}); // <> generiert ein `std::integer_sequence<uint8_t, 0, 1, 2, 3, 4 ,..., 18>` Object
    //]
    l3();
    //[l4
    Loop<std::make_integer_sequence<size_t, count>>::loop();
    l4();
    //]    
    //]
    l5();
}
