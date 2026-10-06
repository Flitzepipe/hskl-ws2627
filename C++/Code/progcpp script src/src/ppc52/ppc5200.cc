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

#if __has_include("../ppc.h") //-
# include "../ppc.h" //-
#endif //-

#ifndef _MSC_VER
# pragma GCC diagnostic ignored "-Wunused-variable"
#endif

#include <vector>
#include <array>
#include <algorithm>
#include <limits>
#include <cassert>
#include <iostream>

//[min1 -ret
template<typename... T> //<> Deklariert ein sog. _parameter pack_ `T`
auto maximum(T... vs) { //<> _Expansion_ des Parameter-Packs `T` 
    //[out
    std::cout << __PRETTY_FUNCTION__ << '\n';
    //]    
    //[ret
    return 0;
    //]
}
//]
int main() {
    //[array
    std::array<int, 5> array = {1, 3, 5, 3, 1};
    auto maximum1 = std::max_element(begin(array), end(array)); // <> Liefert einen _Iterator_ für das Maximum-Objekt zurück ...
    assert(*maximum1 == 5); // <> ... daher hier die explizite Dereferenzierung
    //]
    //[vector
    std::vector<int> vector = {1, 3, 5, 3, 1};
    auto maximum2 = std::max_element(begin(vector), end(vector)); // <> Auch hier ist das Ergebnis ein Iterator
    assert(*maximum2 == 5);
    //]
    //[ilist
    auto maximum3 = std::max({1, 3, 5, 3, 1}); // <> Dem Algorithmus {stdmax} wird eine {stdinitlist} übergeben
    assert(maximum3 == 5);
    //]
    //[var1
    auto maximum4 = maximum(1, 3, 5, 3, 1); // <> Aufruf des _variadische_ Funktions-Templates `maximum<>()`
    //]
    //[var2
    auto maximum5 = maximum(1, 3.0, 'a'); // <> Aufruf mit _unterschiedlichen_ Typen
    //]
}
