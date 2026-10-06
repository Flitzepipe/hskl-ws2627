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
//[A
struct A {
    const int value{};
};
//]
//[B
struct B {
    const int value{};
};

bool operator>(const B& lhs, const B& rhs) { // <> Operator `>` für DT `B`
    return lhs.value > rhs.value;
}
//]
//]

//[template
template<typename T>
T maximum(T a, T b) { // <> implizite Anforderung: Kopierbarkeit
    if (a > b) { // <> implizite Anforderung: `>`-Operation.
        return a; // <> implizite Anforderung: Kopierbarkeit
    }
    return b; // <> implizite Anforderung: Kopierbarkeit
}
//]
//[main
int main() {
    int x = maximum(1, 2);
#if 0 //-
    A a = maximum(A{1}, A{2}); // <> Der DT `A` ist kopierbar, aber nicht anordbar. Der führt die Instanziierung des Templates zu einem Fehler.
#endif //-
    B b = maximum(B{1}, B{2}); // <> Der DT `B` unterstützt _alle_ Anforderungen des Funktionstemplates `maximum()`
    return b.value;
}
//]
