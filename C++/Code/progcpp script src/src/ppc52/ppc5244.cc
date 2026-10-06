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

//[data
struct A {};

template<typename T> struct X {};
//]

//[meta1
template<template<typename T> typename TTP> //<> Deklaration des Template-Template-Parameters `TTP` (mit dem Template-Typ-Parameter `T`, hier nicht benötigt)
struct S {
    using i = TTP<A>;
};
//]
//[meta2
template<template<typename> typename TTP, typename P> //<> Deklaration des Template-Template-Parameters `TTP` und des Template-Typ-Parameters `P`
struct R {
    using i = TTP<P>; //<> Das Template des Template-Template-Parameters `TTP` wird instanziiert mit dem Typ von `P`
};
//]
int main()
{
    //[main
    using x = X<A>;
    using y = S<X>;
    using z = R<X, A>; // <> Innerhalb von `R` wird der Typ `A` verwendet, um das Template `X` zu instanziieren.
    //]
}
