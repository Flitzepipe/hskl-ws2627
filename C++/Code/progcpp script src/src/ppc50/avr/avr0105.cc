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
#include <cstddef>
#include <type_traits>

// concept
template<typename T, typename U>
concept /*bool */Same = std::is_same<T, U>::value;

struct A {};
struct B {};
struct C {};

volatile A a1;

volatile uint8_t x;

namespace {
    void e() { // internal linkage, damit nicht instanziiert wenn nicht benötigt (wie static in C)
        x = 0;
    }
}

template<typename T>
void f(T);

template<>
void f<A>(A) { // ungeeignet für Header-only, da wie konkrete freie Funktion im exe verbleibt, auch wenn nicht genutzt.
    x = 1;
}
template<>
void f<B>(B) {
    x = 2;
}

template<typename T>
void g();
template<>
void g<A>() {
    x = 3;
}
template<>
void g<B>() {
    x = 4;
}

template<typename T>
void h() {      
    x = 5;
}

// concept

template<typename T>
requires std::is_same<T, A>::value // type-trait 
void k() {
    x = 6;
}
template<typename T>
requires Same<T, B> // variable-concept
void k() {
    x = 7;
}

// SFINAE enable_if

template<typename T>
typename std::enable_if<std::is_same<T, A>::value, void>::type
m() {
    x = 8;
}
template<typename T>
typename std::enable_if<std::is_same<T, B>::value, void>::type
m() {
    x = 9;
}

int main() {
    e();
    
    f(A());
    f(B());
    //    f(C()); // schlechte Fehlermeldung
    g<A>();
    g<B>();
    //    g<C>(); // schlechte Fehlermeldung
    h<A>();
    
    k<A>();
    k<B>();
    //    k<C>(); // bessere Fehlermeldung
    
    m<A>();
    m<B>();
    //    m<C>(); // schlechte Fehlermeldung
}
