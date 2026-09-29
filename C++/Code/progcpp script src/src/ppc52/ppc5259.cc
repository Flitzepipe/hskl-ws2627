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

        template<template<typename> typename P, typename L> struct filter_impl; // <> Das allg. Template 
        template<template<typename> typename P, template<typename, typename...> typename L, typename F, typename... I>
        struct filter_impl<P, L<F, I...>> { // <> Die partielle Spezialisierung für Type-Listen
            typedef typename std::conditional<P<F>::value,  //<> Überprüfung der Bedingung (Meta-Funktion als Prädikat für die Typen der Liste)
            typename push_front_impl<F, typename filter_impl<P, L<I...>>::type>::type, // <> Rekursive Anwendung 
            typename filter_impl<P, L<I...>>::type>::type type; // Rekursive Anwendung
        };
        template<template<typename> typename P, template<typename...> typename L> 
        struct filter_impl<P, L<>> { // <> Wegen der Rekursion (s.o.) ist ein Rekursonsende notwendig: die _leere_ Typ-Liste
            typedef L<> type;  
        };
        
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

    template<template<typename> typename F, typename L> // <> Der erste Parameter dieses Alias-Templates ist schon ein Template-Tempate-Parameter, denn es handelt sich ja hier um eine Meta-Funktion
    using filter = typename detail::filter_impl<F, L>::type;
    
    template<typename... T> struct List {}; 

    template<typename T, typename L>
    struct allOfList {
        template<typename U> using Pred = std::is_same<U, T>;
        using fl = filter<Pred, L>;
        inline static constexpr bool value = std::is_same<size<L>, size<fl>>::value;
    };
    template<typename T, typename L>
    constexpr bool allOfList_v = allOfList<T, L>::value;

    template<typename T, typename... II>
    struct allOf {
        template<typename U> using Pred = std::is_same<U, T>;
        using fl = filter<Pred, List<II...>>;
        inline static constexpr bool value = std::is_same<size<List<II...>>, size<fl>>::value;
    };
    template<typename T, typename... II>
    constexpr bool allOf_v = allOf<T, II...>::value; 
    
    //[itoa
    template<typename T, typename C>
    requires std::is_integral<T>::value
    void itoa(T value, C& container) {
        size_t position = 0;
        while(value > 0) {
            container[position++] = static_cast<char>(value % 10 + '0');
            value /= 10;
        }
        std::reverse(std::begin(container), std::begin(container) + position);
    }
    //]
}

namespace std {
    template<size_t N>
    std::ostream& operator<<(std::ostream& out, const std::array<char, N>& values) {
        for(size_t i = 0; (i < N) && (values[i] != '\0'); ++i) {
            out << values[i];
        }
        return out;
    }
}

template<typename First, typename... P> 
//requires PPC::allOfList<First, PPC::List<P...>>::value
requires PPC::allOf_v<First, P...>
constexpr First maximum(First f, P... tail) { 
    if constexpr(sizeof...(tail) == 0) {         
        return f;
    }
    else {
        return f > maximum(tail...) ? f : maximum(tail...);
    }
}

//[req1
template<typename T>
requires true //<> Das einfachste _constraint_: eine `requires`-Klausel mit einem `constexpr`-Wert `true`.
void f() {
}
//]
//[req2
template<typename T>
requires std::is_same_v<T, int>// <> Ein `constexpr`-Ausdruck als `requires`-Klausel
void g() {
}
//]
//[req3
template<typename T>
requires std::is_same_v<T, int> || std::is_same_v<T, short> // <> Ebenfalls ein zusammengesetzter `constexpr`-Ausdruck
void h() {
}
//]

int main() {
    //[test1
    f<int>();
    g<int>();
    h<int>();
    h<short>();
#if ERROR //-
    h<float>(); // <> `float` erfüllt _nicht_ die Anforderungen an den Template-Parameter
#endif //-
    //]
    
    using l1 = PPC::List<int, int>;
    static_assert(PPC::allOfList_v<int, l1>);    
    
    //[main -i

    constexpr auto max = maximum(1, 3, 5);
    static_assert(max == 5);
    
    //[i
    std::array<char, 11> s{};
    PPC::itoa(-42, s);
    std::cout << s << '\n';    
#if 0 //-
    PPC::itoa(42.0, s);
#endif //-
    std::cout << s << '\n';    
    //]
    //]
}
