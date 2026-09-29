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

//[meta1
template<typename T> 
struct unsigned_type; // <> Allg. template: eine Instanziierung führt zu einem Compilezeit-Fehler.
//]

//[meta2
template<> 
struct unsigned_type<char> {
    typedef unsigned char type; // <> Abbildung: `char` -> `unsigned char`
};
template<> 
struct unsigned_type<int> {
    typedef unsigned int type; // <> Abbildung: `int` -> `unsigned int` 
};
//]
//[meta3
template<> 
struct unsigned_type<double> { 
    typedef double type; // <> Abbildung: `double` -> `double` 
};
//]
//[ abs
template<typename T>
typename unsigned_type<T>::type absolute(T value) { // <> Typ-Abbilung mit der Meta-Funktion `unsigned_type<>`
    typedef typename unsigned_type<T>::type U; // <> Typ-Alias für den `unsigned`-Typ
    if (value < T{0}) {
        return U{-value};
    }
    return U{value};
}
//]
int main() {
    //[main
    auto uv = absolute(-2.1); // <> Berechnung des Betrags
    std::cout << PPC::demangle(uv) << std::endl; // <> Ausgabe der Typinformation als _un-mangled_ Name
    //]
}
