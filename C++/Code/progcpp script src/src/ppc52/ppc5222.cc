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

#include <iostream>
#include "demangler.h"

//[impl -impl2
namespace detail {
    template<typename T> 
    struct unsigned_type_impl; 
    template<> 
    struct unsigned_type_impl<char> {
        typedef unsigned char type; 
    };
    //[impl2
    template<> 
    struct unsigned_type_impl<int> {
        typedef unsigned int type;  
    };
    template<> 
    struct unsigned_type_impl<double> { 
        typedef double type; 
    };
    //]
}
//]
//[alias
template<typename T> 
using unsigned_type = typename detail::unsigned_type_impl<T>::type; //<> Die (öffentliche) Metafunktion ist nun dieses Alias-Template
//]
//[ abs
template<typename T>
unsigned_type<T> absolute(T value) { // <> Typ-Abbilung mit der Meta-Funktion `unsigned_type<>`
    if (value < T{0}) {
        return -value; // <> ggf. Compiler-Warnung (`-Wconversion`)
    }
    return value;
}
//]
int main() {
    //[main
    auto uv = absolute((char)-2); // <> Berechnung des Betrags
    std::cout << PPC::demangle(uv) << std::endl; // <> Ausgabe der Typinformation als _un-mangled_ Name
    //]
}
