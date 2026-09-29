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
//[concept
template<typename T>
concept Comparable = requires(T& a, T& b) { // <> Das Schlüsselwort `concept` leitet die Deklaration ein.
    a > b; // <> explizite Anforderung für die `>`-Operation    
};
//]
//[foo
bool foo(const Comparable auto& lhs, const Comparable auto& rhs) {
    return lhs > rhs;
}
//]
//[max
template<typename T>
requires Comparable<T> // <> Die `requires`-Klausel spezifiziert `constraints` an die Template-Parameter.
const T& maximum(const T& a, const T& b) { 
    if (a > b) { // <> Anforderung: `>`-Operation.
        return a; 
    }
    return b; 
}
//]

//[min
template<Comparable T>
const T& minimum(const T& a, const T& b) { 
    if (a > b) { // <> Anforderung: `>`-Operation.
        return b; 
    }
    return a; 
}
//]

//[main
int main() {
    int x = maximum(1, 2);
//    A a = maximum(A{1}, A{2}); // <> Der DT `A` ist kopierbar, aber nicht anordbar.
    B b1 = maximum(B{1}, B{2}); // <> Der DT `B` unterstützt _alle_ Anforderungen des Funktionstemplates `maximum()`
    B b2 = minimum(B{1}, B{2}); // <> Der DT `B` unterstützt _alle_ Anforderungen des Funktionstemplates `maximum()`

    foo(b1, b2); // <> `B` erfüllt die Requirements
    
    return b1.value + b2.value; //-
}
//]
