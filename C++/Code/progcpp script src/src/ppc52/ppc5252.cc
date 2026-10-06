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

//[con1
template<typename T>
concept StrictOrdered = requires(T a, T b) { // <> Hier steht `requires` für einen `requires`-Ausdruck
        a > b; //<> Ausdrucks-Anforderung: dieser Audruck muss _wohlgeformt_ sein, damit diese Anforderung erfüllt ist.
    };

//]
#if 0
//[max1
template<typename First, typename... P> 
requires StrictOrdered<First> // <> Die Anforderung der _strengen Ordnung_  an den Parameter `First`
&& (StrictOrdered<P> && ...) // <> Expansion des Parameter-Packs `P` in einem Faltungsausdruck
constexpr First maximum(First f, P... tail) { 
    if constexpr(sizeof...(tail) == 0) {         
        return f;
    }
    else {
        return f > maximum(tail...) ? f : maximum(tail...);
    }
}
//]
#else
//[max2
template<StrictOrdered First, StrictOrdered... P> // <> Die Anforderungen an die Template-Typ-Parameter oder die Elemente des Paramter-Packs stehen unmittelbat in der Template-Präambel
constexpr First maximum(First f, P... tail) { 
    if constexpr(sizeof...(tail) == 0) {         
        return f;
    }
    else {
        return f > maximum(tail...) ? f : maximum(tail...);
    }
}
//]
#endif
struct A {
    int mValue = 0;
};

int main() {
    constexpr auto max = maximum(1, 3, 5);
    static_assert(max == 5);
#if 0 //-    
    auto max2 = maximum(A{1}, A{2});
#endif //-
}
