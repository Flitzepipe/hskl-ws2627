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

//[sum1
template<typename First, typename... P> 
First sum1(First f, P... tail) { // <> Problematisch, da ggf. ein _leerer_ Parameter-Pack resultiert
    auto tailSum = (tail + ...); // <> Rechsseitige Faltung = `(t#1 + ... + (t#N-2 + (t#N-1 + t#N)))`
    return f + tailSum;
}
//]
//[sum2
template<typename First, typename... P> 
First sum2(First f, P... tail) { // <> Problematisch, da ggf. ein _leerer_ Parameter-Pack resultiert
    auto tailSum = (... + tail); // <> Linksseitige Faltung = `(((t#1 + t#2) + t#3) + ... + t#N)`
    return f + tailSum;
}
//]
//[sum3
template<typename First, typename... P> 
First sum3(First f, P... tail) { 
    return (f + ... + tail); // <> Linksseitige Faltung mit Initialisierung, dadurch ist auch ein _leerer_ Parameter-Pack möglich
}
//]

//[max1
template<typename First, typename... P> 
First maximum(First f, P... tail) { 
    First maxSoFar = f;
    ((maxSoFar = maxSoFar > tail ? maxSoFar : tail),...); //<> Rechtsseitige Faltung mit dem Komma-Operator
    return maxSoFar;
}
//]
//[max2
template<typename First, typename... P> 
First maximum2(First f, P... tail) { 
    First maxSoFar = f;
    ((maxSoFar = std::max(maxSoFar, tail)),...); //<> Rechtsseitige Faltung mit dem Komma-Operator
    return maxSoFar;
}
//]
//[last
template<typename First, typename... P>
First last(First f, P... tail) {
    return (f, ... , tail); //<> Linksseitige Faltung über den Komma-Operator ergibt das letzte Element der Expansion (Achtung: Warnungen vom Compiler)
}
//]
int main() {
    //[main
    auto max = maximum(1, 3, 5);
    assert(max == 5);
    //]
    auto max1 = maximum(1);
    assert(max1 == 1);
    
    auto max2 = maximum2(1, 3, 5);
    assert(max2 == 5);
    max2 = maximum2(1);
    //[sum
    auto s = sum1(1, 3, 5);
    assert(s == 9);
    //]
    //[error
#if 0 //-
    sum1(1); // <> nicht möglich, da hier ein _leerer_ Parameter-Pack entsteht, über den nicht gefaltet werden kann
    sum2(1); //-
#endif //-
    auto x = sum3(1); // <> besser
    //]
    
    auto s2 = sum2(1, 3, 5);
    assert(s2 == 9);
    auto s3 = sum3(1, 3, 5, 3, 1);
    assert(s3 == 13);

    auto l1 = last(1, 3, 5, 4);
    assert(l1 == 4);
    auto l2 = last(1);
    assert(l2 == 1);
}
