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

//[template 
template<typename T>
T maximum(const T a, const T b) { // <> implizite Anforderung: Kopierbarkeit
    std::cout << __PRETTY_FUNCTION__ << '\n';
    if (a > b) { // <> implizite Anforderung: `>`-Operation.
        return a; // <> implizite Anforderung: Kopierbarkeit
    }
    return b; // <> implizite Anforderung: Kopierbarkeit
}
template<> // <> Eine (vollständige) Spezialisierung für `std::string`
std::string maximum<std::string>(const std::string a, const std::string b) {
    std::cout << __PRETTY_FUNCTION__ << '\n';
    if (std::size(a) > std::size(b)) { // <> Vergleich der Länge
        return a;
    }    
    return b;
}
template<> // <> Eine (vollständige) Spezialisierung für `const char*`
const char* maximum<const char*>(const char* const a, const char* const b) {
    std::cout << __PRETTY_FUNCTION__ << '\n';
    if (size_t la = strlen(a), lb = strlen(b); la > lb) { // <> Vergleich der Länge
        return a;
    }    
    return b;
}
//]
//[main
int main() {
    std::string a = maximum("aaa", "b"); // <> *Achtung*: keine impliziten Typwandlungen für Template-Typ-Parameter
    std::string b = maximum(std::string{"aaa"}, std::string{"b"});
    
    std::cout << "a: " << a << ", b: " << b << '\n';
}
//]
