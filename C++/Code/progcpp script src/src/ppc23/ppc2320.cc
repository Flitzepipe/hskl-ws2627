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

#if __has_include("../ppc.h") //-
# include "../ppc.h" //-
#endif //-

#include <iostream>
#include <cstring>

#ifndef _MSC_VER
# pragma GCC diagnostic ignored "-Wunused-variable"
#endif

//[AB
struct A {
    const int value{};
};

struct B {
    const int value{};
};

bool operator>(const B& lhs, const B& rhs) { // <> Operator `>` für DT `B`
    return lhs.value > rhs.value;
}
//]

//[size
//template<typename T>
size_t size(const char* const str) {
    return strlen(str);
}
//]

//[concept
template<typename T>
concept Sized = requires(T c) {
                size(c);
};
//]

//[template 
template<typename T>
T maximum(const T a, const T b) 
{
    std::cout << __PRETTY_FUNCTION__ << '\n';
    if (a > b) { 
        return a; 
    }
    return b; 
}
template<typename T>
T maximum(const T a, const T b) // <> Überladung mit anderen (stärkeren) Anforderungen (_more restricted_)
requires Sized<T>
{
    std::cout << __PRETTY_FUNCTION__ << '\n';
    if (size(a) > size(b)) { // <> Vergleich der Länge
        return a;
    }    
    return b;
}
template<>// <> Eine (vollständige) Spezialisierung für `std::string`
A maximum<A>(const A a, const A b) {
    std::cout << __PRETTY_FUNCTION__ << '\n';
    if (a.value > b.value) {
        return a;
    }
    return b;
}
//]
//[main
int main() {
    A r = maximum(A{1}, A{2}); 
    std::string a = maximum("aaa", "b"); // <> *Achtung*: keine impliziten Typwandlungen für Template-Typ-Parameter
    std::string b = maximum(std::string{"aaa"}, std::string{"b"});
    
    std::cout << "a: " << a << ", b: " << b << '\n';
}
//]
