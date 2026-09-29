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
        //[meta
        template<typename F, typename L> struct push_front_impl;
        template<typename F, template<typename ...> typename L, typename... I>
        struct push_front_impl<F, L<I...>> {
            typedef L<F, I...> type;  
        };
        //]
    }
    template<typename L>
    using front = typename detail::front_impl<L>::type;
    
    template<typename L>
    using size = typename detail::size_impl<L>::type;
    
    template<typename L>
    using back = typename detail::back_impl<L>::type;

    //[meta
    template<typename F, typename L>
    using push_front = typename detail::push_front_impl<F, L>::type;
    //]
    template<typename... T> struct List {};
}

//[test
struct A {};
struct B {};
struct C {};
//]
int main() {
    //[test
    using tl1 = PPC::List<B, C>;
    using tl = PPC::push_front<A, tl1>;
    using f = PPC::front<tl>;
    static_assert(std::is_same<f, A>::value);
    using b = PPC::back<tl>;
    static_assert(std::is_same<b, C>::value);
    //]
}