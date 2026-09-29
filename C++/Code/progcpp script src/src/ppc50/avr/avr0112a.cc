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
#include <type_traits>

struct A {
    uint8_t m1{0};
};

volatile uint8_t v;

template<typename T>
void f(const T& x) __attribute__((noinline));
template<typename T>
void f(const T& x) { // <> ipa-sra Optimierung für kleine Objekte (Achtung: gcc bug 81248) : sra: scalar replacement for aggregates
    if constexpr(std::is_same<T, A>::value) {
        v = x.m1;
    }
    else {
        v = x;
    }
}

uint8_t n1;
A n2;
uint16_t n3;

int main() {
    f(n1);
    f(n2);
    f(n3);
}
