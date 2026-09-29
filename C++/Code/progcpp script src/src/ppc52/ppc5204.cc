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

//[sum
template<typename F>
F sum(F v) { //<> Überladenes Template als Rekursionsende
    return v;  
}
template<typename First, typename... P> 
First sum(First f, P... tail) {
    return f + sum(tail...); // <> Ende der Rekursion bei Aufruf `sum(tail#1)`, da dann die überladene Variante `sum(F v)` aufgerufen wird (_tie-break_)
}
//]

//[sumR
namespace detail {
    template<typename IT>
    auto sum(IT start, IT end) -> typename std::iterator_traits<IT>::value_type {
        if (start == end) {
            return 0;
        }
        else {
            return *start + sum(start + 1, end);
        }
    }
}
template<typename T>
T sum(const std::initializer_list<T>& values) {
    return detail::sum(values.begin(), values.end());
}
//]
//[max1
template<typename First, typename... P> 
First maximum(First f, P... tail) { 
    First max = f;
    if constexpr(sizeof...(tail) == 0) { // <> Explizites Rekursionsende durch eine Berechnung zur Compilezeit
        return f;
    }
    else {
        return f > maximum(tail...) ? f : maximum(tail...);
    }
}
//]
int main() {
    //[main
    auto max = maximum(1, 3, 5);
    assert(max == 5);
    //]
    //[sum
    auto s = sum(1, 3, 5);
    assert(s == 9);
    //]
    
    auto s2 = sum({2, 3, 4});
    assert(s2 == 9);
    auto s3 = sum({2});
    assert(s3 == 2);
}
