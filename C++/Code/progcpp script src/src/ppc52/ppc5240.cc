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

#include <cassert>
#include <type_traits>

namespace PPC {
//[meta
    namespace detail {
        template<typename T> struct front_impl; // <> Das allg. Template ist wie immer notwendig
        template<template<typename, typename...> typename L, typename F, typename... R>
        struct front_impl<L<F, R...>> { // <> Partielle Spezialisierung für ein variadisches Template `L` mit mindestens _einem_ Typ `F` und einer beliebigen Anzahl weiterer Typen (im Parameter-Pack `R`)
            typedef F type;
        };
    }
    template<typename L> // <> Alias-Template als _Meta-Funktion_
    using front = typename detail::front_impl<L>::type;
//]
    template<typename... T> struct List {}; // <> Typ-Liste
}

//[max1
template<typename First, typename... P> 
constexpr First maximum(First f, P... tail) { 
    if constexpr(sizeof...(tail) == 0) { // <> Explizites Rekursionsende durch eine Berechnung zur Compilezeit
        return f;
    }
    else {
        using typeList = PPC::List<P...>; // <> Erzeugung einer Typ-Liste
        using front = PPC::front<typeList>; // <> Das erste Element der Typ-Liste
        static_assert(std::is_same<First, front>::value, "not the same type"); // <> Zusicherung, dass `First` und das erste Element vo `typeList` identisch sind.
        
        return f > maximum(tail...) ? f : maximum(tail...);
    }
}
//]
//[test
struct A {};
struct B {};
struct C {};
//]
int main() {
    //[test
    using tl = PPC::List<A, B, C>;
    using f = PPC::front<tl>;
    static_assert(std::is_same<f, A>::value);
    //]
    //[main
    constexpr auto max = maximum(1, 3, 5);
    static_assert(max == 5);
    //]
#ifdef WITH_ERROR
    constexpr auto max2 = maximum(1, 3, 5.0);
#endif
}