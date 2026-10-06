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

//[sum
template<typename P>
P sum(P v) { // <> Rekursionsende
    return v;  
}
template<typename First, typename... P> 
First sum(First f, P... tail) {
    return f + sum(tail...); //<> Compilezeit-Rekursion
}
//]
volatile uint8_t x1;
volatile uint8_t x2;
volatile uint8_t x3;
volatile uint8_t x4;

int main() {
    return sum(x1, x2, x3, x4);
}
