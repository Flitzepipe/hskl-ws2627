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
#include <cstdint>

namespace PPC {
    namespace detail {
        template<typename T> struct front_impl; // <> Das allg. Template
        template<template<typename, typename...> typename L, typename F, typename... R>
        struct front_impl<L<F, R...>> { // <> Partielle Spezialisierung 
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
        
        //[filter
        template<template<typename> typename P, typename L> struct filter_impl; // <> Das allg. Template 
        template<template<typename> typename P, template<typename, typename...> typename L, typename F, typename... I>
        struct filter_impl<P, L<F, I...>> { // <> Die partielle Spezialisierung für Type-Listen
            typedef typename std::conditional<P<F>::value,  //<> Überprüfung der Bedingung (Meta-Funktion als Prädikat für die Typen der Liste)
            typename push_front_impl<F, typename filter_impl<P, L<I...>>::type>::type, // <> Rekursive Anwendung 
            typename filter_impl<P, L<I...>>::type>::type type; // <> Rekursive Anwendung
        };
        template<template<typename> typename P, template<typename...> typename L> 
        struct filter_impl<P, L<>> { // <> Wegen der Rekursion (s.o.) ist ein Rekursonsende notwendig: die _leere_ Typ-Liste
            typedef L<> type;  
        };
        //]
        template<typename T>
        struct numberOfDigits;
        template<> struct numberOfDigits<int8_t> {
            inline static constexpr size_t value = 4;
        };
        template<> struct numberOfDigits<uint8_t> {
            inline static constexpr size_t value = 3;
        };
        template<> struct numberOfDigits<int16_t> {
            inline static constexpr size_t value = 6;
        };
        template<> struct numberOfDigits<uint16_t> {
            inline static constexpr size_t value = 5;
        };
        template<> struct numberOfDigits<int32_t> {
            inline static constexpr size_t value = 11;
        };
        template<> struct numberOfDigits<uint32_t> {
            inline static constexpr size_t value = 10;
        };
    }
    template<typename T> struct isInteger {
        inline static constexpr bool value = false;
    };
    template<> struct isInteger<char> {
        inline static constexpr bool value = true;
    };
    template<> struct isInteger<unsigned char> {
        inline static constexpr bool value = true;
    };
    template<> struct isInteger<int> {
        inline static constexpr bool value = true;
    };
    template<> struct isInteger<unsigned int> {
        inline static constexpr bool value = true;
    };
    template<typename T> struct isUnsigned {
        inline static constexpr bool value = (T(-1) > T{0}); // <> Durch `T(-1)` wird ein _narrowing_ zugelassen
    };
    
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

    //[filter
    template<template<typename> typename F, typename L> // <> Der erste Parameter dieses Alias-Templates ist schon ein Template-Tempate-Parameter, denn es handelt sich ja hier um eine Meta-Funktion
    using filter = typename detail::filter_impl<F, L>::type;
    //]
    
    template<typename... T> struct List {}; 

    //[alloflist
    template<typename T, typename L>
    struct allOfList { // <> Eine Meta-Funktion, die prüft, ob alle Elemente von `L` identisch zu `T` sind
        template<typename U> using Pred = std::is_same<U, T>; // <> Ein Alias-Template (als Meta-Funktion `Pred<X>` zu verwenden)
        using fl = filter<Pred, L>; // <> `fl` ist die Typ-Liste, die alle die Typen aus `L` enthält, die das Prädikat `Pred<X>` erfüllen.
        inline static constexpr bool value = std::is_same<size<L>, size<fl>>::value; // <> Ist die ursprüngliche Liste genauso lang wie die gefilterte Liste, so erfüllen alle(!) Typen das Prädikat `Pred<X>`.
    };
    template<typename T, typename L>
    constexpr bool allOfList_v = allOfList<T, L>::value;
    //]
    //[allof
    template<typename T, typename... II>
    struct allOf { // <> Eine Meta-Funktion, die prüft, ob alle Elemente des Parameter-Packs `II` identisch zu `T` sind.
        template<typename U> using Pred = std::is_same<U, T>; // <> Ein Alias-Template (als Meta-Funktion `Pred<X>` zu verwenden)
        using fl = filter<Pred, List<II...>>; // <> `fl` ist die Typ-Liste, die alle die Typen aus dem Parameter-Pack `II` enthält, die das Prädikat `Pred<X>` erfüllen.
        inline static constexpr bool value = std::is_same<size<List<II...>>, size<fl>>::value; // <> Ist die Größe des Parameterpacks identisch zur gefilterten Liste, so haben alle(!) Typen das Prädikat erfüllt.
    };
    template<typename T, typename... II>
    constexpr bool allOf_v = allOf<T, II...>::value; 
    //]
}

template<typename T>
concept StrictOrdered = requires(T a, T b) { // <> Hier steht `requires` für einen `requires`-Ausdruck
        a > b; //<> Ausdrucks-Anforderung: dieser Audruck muss _wohlgeformt_ sein, damit diese Anforderung erfüllt ist.
    };

//[max
template<StrictOrdered First, StrictOrdered... P> //<> Unmittelbare Anforderungen können einfach in die Template-Präambel geschrieben werden
requires PPC::allOf_v<First, P...> // <> Für verknüpfende Anforderungen benötigt man eine `requires`-Klausel
constexpr First maximum(First f, P... tail) { 
    if constexpr(sizeof...(tail) == 0) {         
        return f;
    }
    else {
        return f > maximum(tail...) ? f : maximum(tail...);
    }
}
//]
int main() {
    //[test1
    static_assert(PPC::allOf_v<int, int, int>);    
    //]
    //[test
    using l1 = PPC::List<int, int>;
    static_assert(PPC::allOfList_v<int, l1>);    
    //]
    //[main
    constexpr auto max = maximum(1, 3, 5);
    static_assert(max == 5);
    //]
    //[error
#if ERROR //-
    maximum(1.0, 2, 3);
#endif //-
    //]
}
