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

//[f
class X; // <> Unvollständige Deklaration des Typs `X`: ein Ausdruck, der `X` enthält, kann daher nicht instanziiert werden.

template<bool B, typename T>
void f() {
    if constexpr(B) { // <> Ist `B` == `false`, dann wird der Körper des `if` nicht _instanziiert_ 
        T::a(); // <> Wohlgeformter Ausdruck, der jedoch nicht instanziiert wird, wenn `B` == `false`
    }
}
//]
//[g
template<typename T>
void g(bool b) {
    if (b) { // <> Ein `constexpr-if` ist hier nicht möglich, weil `b` nicht `constexpr` ist.
#if WITH_ERROR //-
        T::a(); // <> Dies ist nicht möglich, denn die Instanziierung dieser Anweisung schlägt fehl.
#endif //-
    }
}
//]

int main() {
    //[main1
    f<false, X>(); 
    //]
    //[main2
    g<X>(false); // <> Dieser Aufruf von `g()` kann nicht übersezt werden (s.o.)
    //]
}
