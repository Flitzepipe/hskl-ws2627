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

#pragma once

#include <cstddef>
#include <cstdint>

namespace BMCPP {
    namespace Meta {
        template<typename... T> struct List {};
        namespace detail {

            template<typename T> struct front_impl;
            template<template<typename, typename...> typename L, typename F, typename... R>
            struct front_impl<L<F, R...>> { 
                typedef F type;
            };
            
            template<typename T> struct size_impl; 
            template<template<typename...> typename L, typename... I>  
            struct size_impl<L<I...>> { 
                typedef std::integral_constant<size_t, sizeof...(I)> type; 
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
            template<template<typename> typename F, typename L> struct transform_impl;
            template<template<typename> typename F, template<typename...> typename L, typename... I>
            struct transform_impl<F, L<I...>> {
                typedef L<F<I>...> type;                
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
            struct filter_impl<P, L<F, I...>> { // <> Die partielle Spezialisierung für Type-Listen
                typedef typename std::conditional<P<F>::value,  //<> Überprüfung der Bedingung (Meta-Funktion als Prädikat für die Typen der Liste)
                typename push_front_impl<F, typename filter_impl<P, L<I...>>::type>::type, // <> Rekursive Anwendung 
                typename filter_impl<P, L<I...>>::type>::type type; // Rekursive Anwendung
            };
            template<template<typename> typename P, template<typename...> typename L> 
            struct filter_impl<P, L<>> { // <> Wegen der Rekursion (s.o.) ist ein Rekursonsende notwendig: die _leere_ Typ-Liste
                typedef L<> type;  
            };
            //]
            template<size_t, typename L> struct nth_element_impl;
            template<template<typename F, typename...> typename L, typename F, typename... I>
            struct nth_element_impl<0, L<F, I...>> {
                typedef F type;  
            };
            template<size_t N, template<typename F, typename...> typename L, typename F, typename... I>
            struct nth_element_impl<N, L<F, I...>> {
                typedef typename nth_element_impl<N-1, L<I...>>::type type;  
            };
            template<typename List, typename T> struct count_impl {
                template<typename U>
                using p = std::is_same<U, T>;
                using filtered = typename filter_impl<p, List>::type;
                inline static constexpr size_t value = size_impl<filtered>::type::value;
            };
            template<typename List, typename T> struct contains_impl {
                inline static constexpr bool value = (count_impl<List, T>::value > 0);
            };
            template<typename, typename> struct contains_all_impl {};
            template<template<typename...> typename L1, typename... I1, template<typename...> typename L2, typename... I2>
            struct contains_all_impl<L1<I1...>, L2<I2...>> {
                using type = std::integral_constant<bool, (contains_impl<L1<I1...>, I2>::value && ... && true)>;
            };

            template<typename> struct is_set_impl;
            template<template<typename, typename...> typename L, typename F, typename... I>
            struct is_set_impl<L<F, I...>> {
                using type = typename std::conditional<contains_impl<L<I...>, F>::value, 
                                                      std::integral_constant<bool, false>, 
                                                      typename is_set_impl<L<I...>>::type>::type;
            };
            template<template<typename> typename L, typename I>
            struct is_set_impl<L<I>> {
                using type = std::integral_constant<bool, true>;
            };
            
            template<typename, typename> struct all_same_impl;
            template<typename T, template<typename...> typename L, typename... I>
            struct all_same_impl<T, L<I...>> {
                static inline constexpr bool value = (std::is_same<T, I>::value && ... && true);
            };
            
        }
        template<typename L>
        using front = typename detail::front_impl<L>::type;
        
        template<typename L>
        using size = typename detail::size_impl<L>::type;
        
        template<typename L>
        using back = typename detail::back_impl<L>::type;
        
        template<template<typename> typename Func, typename List>
        using transform = typename detail::transform_impl<Func, List>::type;
        
        template<typename F, typename L>
        using push_front = typename detail::push_front_impl<F, L>::type;
        
        template<typename L1, typename L2>
        using concat = typename detail::concat_impl<L1, L2>::type;
        
        //[meta
        template<template<typename> typename F, typename L> // <> Der erste Parameter dieses Alias-Templates ist schon ein Template-Tempate-Parameter, denn es handelt sich ja hier um eine Meta-Funktion
        using filter = typename detail::filter_impl<F, L>::type;
        //]
        
        template<size_t N, typename L>
        using nth_element = typename detail::nth_element_impl<N, L>::type;
        
        template<typename List, typename T>
        struct contains : public std::integral_constant<bool, detail::contains_impl<List, T>::value> {};
        
        template<typename List, typename... T>
        struct containsAll : public std::integral_constant<bool, detail::contains_all_impl<List, BMCPP::Meta::List<T...>>::type::value> {};
        
        template<typename List, typename T>
        struct count: public std::integral_constant<size_t, detail::count_impl<List, T>::value> {};
        
        template<typename List>
        struct is_set : public std::integral_constant<bool, detail::is_set_impl<List>::type::value> {};
    
        template<typename T, typename L>
        struct all_same : public std::integral_constant<bool, detail::all_same_impl<T, L>::value> {};
        
    }
}
