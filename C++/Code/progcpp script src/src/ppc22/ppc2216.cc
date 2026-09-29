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

#include <cstdint>
#include <iostream>

//[classa
class A {};
//]
//[meta
template<typename T>
struct toSigned; // <> Weil es keinen immer gültigen allgemeinen Fall gibt, entfällt die Definition, und es bleibt nur bei der _Deklaration_

template<>
struct toSigned<char> { // <> Vollständige Spezialisierung für den DT `char`
    typedef unsigned char type;
};
template<>
struct toSigned<unsigned char> {
    typedef unsigned char type;
};
template<>
struct toSigned<signed char> {
    typedef unsigned char type;
};
template<>
struct toSigned<int> { // <> Vollständige Spezialisierung für den DT `int`
    typedef unsigned int type;
};
// <> Die weiteren Spezialisierungen fehlen hier ...
//]
//[foo
template<typename T>
void foo() {
    std::cout << __PRETTY_FUNCTION__ << '\n';
}
//]
int main() {
    //[main
    toSigned<char>::type x;
    foo<decltype(x)>();
    toSigned<unsigned char>::type y;
    foo<decltype(y)>();
    toSigned<int>::type z;
    foo<decltype(z)>();
#if 0 //-
    toSigned<A>::type z; // <> Dies führt sinnvollerweise zu einem Kompilationsfehler
#endif //-
    //]
}
