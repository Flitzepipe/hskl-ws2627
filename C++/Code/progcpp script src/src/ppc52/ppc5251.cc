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
#include <type_traits>

//[con1
template<typename T>
concept Integral = std::is_integral<T>::value; // <> Hier ist statt eines `requires`-Ausdrucks nach dem `return` ein `constexpr`-Ausdruck.

//]
//[con2
template<typename T>
concept Float = std::is_floating_point<T>::value; // <> Definition eine Variablen-Concepts
//]
//[req1
template<typename T>
requires Integral<T> // <> Definition einer Anforderung mit Hilfe eines Funktions-Concepts (man beachte die Klammern `()`)
void h() {
}
//]
//[req2
template<Integral T> // <> In einer kürzeren Schreibweise kann die Anforderung auch direkt in die Template-Präambel geschrieben werden.
void g() {
}
//]
//[req3
void f(Integral auto /* i */) { // <> In einer noch kürzeren Schreibweise kann die Anforderung auch als _Platzhalter_ in eine Parameterliste geschrieben werden: damit wird ein Template-Typ-Parameter mit dieser Anforderung implizit eingeführt. Damit ist `f()` auch ein Funktionstemplate.
}
//]
//[req4
template<typename T>
requires Float<T> // <> Hier eine ein Variablen-Concept verwendet. Achtung: es fehlen die runden Klammern `()`.
void k() {
}
//]
//[req5
template<Float T> // <> Auch hier wieder die kürzere Schreibweise
void l() {
}
//]

int main() {
    //[test1
    h<int>();
    h<short>();
    g<char>();
    k<double>();
    l<double>();
    f(42);
#if ERROR //-
    h<float>(); // <> `float` erfüllt _nicht_ die Anforderungen an den Template-Parameter
#endif //-
    //]
}
