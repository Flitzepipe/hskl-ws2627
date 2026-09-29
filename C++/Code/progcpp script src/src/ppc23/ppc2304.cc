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
//[comp1
template<typename T>
concept ComparableGT = requires(T& a, T& b) { // <> Das Schlüsselwort `concept` leitet die Deklaration ein.
    a > b; // <> explizite Anforderung für die `>`-Operation    
};
//]
//[comp2
template<typename T>
concept ComparableLT = requires(T& a, T& b) { // <> Das Schlüsselwort `concept` leitet die Deklaration ein.
    a < b; // <> explizite Anforderung für die `<`-Operation    
};
//]
//[max1
template<typename T>
requires ComparableGT<T> // <> Überladen des Funktionstemplates mit Hilfe des _Contraint_ `ComparableGT`  
const T& maximum(const T& a, const T& b) { 
    if (a > b) { // <> Anforderung: `>`-Operation.
        return a; 
    }
    return b; 
}
//]
//[max2
template<typename T>
requires ComparableLT<T> // <> // <> Überladen des Funktionstemplates mit Hilfe des _Contraint_ `ComparableLT` 
const T& maximum(const T& a, const T& b) { 
    if (a < b) { // <> Anforderung: `>`-Operation.
        return b; 
    }
    return a; 
}
//]

//[main
int main() {
//    int x = maximum(1, 2); // <> Dies ist nicht möglich, da der DT `int` beide Requirements erfüllt. Somit ergibt sich ein _overload-set_ indem zwei gleich priorisierte gemäß _partial ordering_ enthalten sind.
    B b1 = maximum(B{1}, B{2}); // <> Im Gegensatz zum Obigen ist dies sehr wohl möglich, da der DT `B` nur _eins_ der beiden Requirements (`ComparableGT`) erfüllt. Damit enthält das _overload set_ nur eine Variante und ist eindeutig.

    return b1.value; //-
}
//]
