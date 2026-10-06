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
    namespace detail {
        template<typename T> struct front_impl;
        template<template<typename, typename...> typename L, typename F, typename... R>
        struct front_impl<L<F, R...>> { 
            typedef F type;
        };
        
        template<typename T> struct size_impl; 
        template<template<typename...> typename L, typename... I>  
        struct size_impl<L<I...>> { 
            typedef std::integral_constant<std::size_t, sizeof...(I)> type; 
        };
        template<typename L> struct back_impl; 
        template<template<typename, typename...> typename L, typename F, typename... I>
        struct back_impl<L<F, I...>> { 
            typedef typename back_impl<L<I...>>::type type;
        };
        template<template<typename> typename L, typename B>
        struct back_impl<L<B>> { 
            typedef B type;
        };
        template<typename F, typename L> struct push_front_impl;
        template<typename F, template<typename ...> typename L, typename... I>
        struct push_front_impl<F, L<I...>> {
            typedef L<F, I...> type;  
        };

        template<typename L1, typename L2> struct concat_impl;
        template<template<typename...> typename L1, typename... I1, template<typename...> typename L2, typename...I2>
        struct concat_impl<L1<I1...>, L2<I2...>> {
            typedef L1<I1..., I2...> type;  
        };
        //[meta    
        template<template<typename> typename P, typename L> struct filter_impl; // <> Das allg. Template 
        template<template<typename> typename P, template<typename, typename...> typename L, typename F, typename... I>
        struct filter_impl<P, L<F, I...>> { // <> Die partielle Spezialisierung für Typ-Listen
            typedef typename std::conditional<P<F>::value,  //<> Überprüfung der Bedingung (Meta-Funktion als Prädikat für die Typen der Liste)
            typename push_front_impl<F, typename filter_impl<P, L<I...>>::type>::type, // <> Rekursive Anwendung 
            typename filter_impl<P, L<I...>>::type>::type type; // <> Rekursive Anwendung
        };
        template<template<typename> typename P, template<typename...> typename L> 
        struct filter_impl<P, L<>> { // <> Wegen der Rekursion (s.o.) ist ein Rekursonsende notwendig: die _leere_ Typ-Liste
            typedef L<> type;  
        };
        //]
    }
    template<typename L>
    using front = typename detail::front_impl<L>::type;
    
    template<typename L>
    using size = typename detail::size_impl<L>::type;
    
    template<typename L>
    using back = typename detail::back_impl<L>::type;

    template<typename F, typename L>
    using push_front = typename detail::push_front_impl<F, L>::type;

    template<typename L1, typename L2>
    using concat = typename detail::concat_impl<L1, L2>::type;

    //[meta
    template<template<typename> typename P, typename L> // <> Der erste Parameter `P` dieses Alias-Templates ist schon ein Template-Tempate-Parameter, denn es handelt sich ja hier um eine Meta-Funktion
    using filter = typename detail::filter_impl<P, L>::type;
    //]
    
    template<typename... T> struct List {};
}

//[test2
template<typename T>
using is_void = std::is_same<T, void>; // <> Meta-Prädikatsfunktion
//]
//[test
struct A {};
struct B {};
struct C {};

template<typename T>
struct nonVoid : public std::true_type {}; // <> Eine Meta-Funktion, die prüft, ob der Typ `T` gleich dem Typ `void` ist.
template<>
struct nonVoid<void> : public std::false_type{};

//]
int main() {
    //[test
    using tl1 = PPC::List<A, void>;
    using tl2 = PPC::List<B, C>;
    using tl3 = PPC::concat<tl1, tl2>; // <> Die Typ-Liste `tl3` besteht aus `A`, `void`, `B`, `C`
    using tl = PPC::filter<nonVoid, tl3>; // <> Die Meta-Prädikatsfuntion filtert alle `T != void` heraus --> die Typ-Liste `tl` besteht also aus `A`, `B`, `C`.
    static_assert(PPC::size<tl>::value == 3); // <> Testfall: Länge
    using f = PPC::front<tl>; // <> Testfall: erstes Element
    static_assert(std::is_same<f, A>::value);
    static_assert(std::is_same<PPC::back<tl>, C>::value); // <> Testfall: letztes Element
    //]
    //[test2
    using tl10 = PPC::filter<is_void, tl3>; // <> Die Meta-Prädikationsfunktion `is_void<>` wird angewendet.
    static_assert(PPC::size<tl10>::value == 1); // <> Testfall: Länge
    static_assert(std::is_same<PPC::front<tl10>, void>::value); // <> Testfall: erstes Element
    //]
}
