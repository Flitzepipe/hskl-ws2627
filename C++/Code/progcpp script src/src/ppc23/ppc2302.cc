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

#include <type_traits>

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

bool operator>(const B& lhs, const B& rhs) {
    return lhs.value > rhs.value;
}
//]

//[trait
template<typename T>
using true_t = std::integral_constant<bool, true>;
//]

//[foo
template<typename T>
requires true_t<T>::value // <> Die `requires`-Klausel ist immer wahr.
void foo(T) {
}
//]
//[bar
template<typename T>
requires false // <> Die `requires`-Klausel ist immer falsch.
void bar(T) {
}
//]
//[max
template<typename T>
requires // <> Die `requires`-Klausel spezifiziert `constraints` an die Template-Parameter.
requires(T& a, T& b) { // <> ad-hoc Anforderung durch einen `requires`-Ausdruck
    a > b; // <> explizite Anforderung für die `>`-Operation
    T{a}; // <> explizite Anforderung für die Kopierbarkeit
}
T maximum(T a, T b) { // <> implizite Anforderung: Kopierbarkeit
    if (a > b) { // <> implizite Anforderung: `>`-Operation.
        return a; // <> implizite Anforderung: Kopierbarkeit
    }
    return b; // <> implizite Anforderung: Kopierbarkeit
}
//]

//[min
template<typename T>
requires // <> Die `requires`-Klausel spezifiziert `constraints` an die Template-Parameter.
requires(T& a, T& b) { // <> explizite Anforderung für die `>`-Operation in eigenem `requires`-Ausdruck
    a > b;
} &&
requires(T& a, T& b) { // <> explizite Anforderung für die Kopierbarkeit in eigenem `requires`-Ausdruck
    T{a};
}
T minimum(T a, T b) { // <> implizite Anforderung: Kopierbarkeit
    if (a > b) { // <> implizite Anforderung: `>`-Operation.
        return b; // <> implizite Anforderung: Kopierbarkeit
    }
    return a; // <> implizite Anforderung: Kopierbarkeit
}
//]

//[main
int main() {
    int x = maximum(1, 2);
//    A a = maximum(A{1}, A{2}); // <> Der DT `A` ist kopierbar, aber nicht anordbar.
    B b1 = maximum(B{1}, B{2}); // <> Der DT `B` unterstützt _alle_ Anforderungen des Funktionstemplates `maximum()`
    B b2 = minimum(B{1}, B{2}); // <> Der DT `B` unterstützt _alle_ Anforderungen des Funktionstemplates `maximum()`
    
    foo(0); // <> Die Requirements sind immer `true`
//    bar(0); // <> Die Requirements sind immer `false`
    
    return b1.value + b2.value; //-
}
//]
