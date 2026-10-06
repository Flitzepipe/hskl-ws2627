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
#include <array>

int main() {
    //[l1
    auto generate = []{ // <> Das Funktionsobjekt wird der Variablen `generate` zugewiesen.
        std::array<int, 10> a{};
        for(size_t i = 0; i < a.size(); ++i) {
            a[i] = 2 * (int)i + 1;
        }        
        return a;
    };
    constexpr auto a1 = generate(); // <> Das Funktionsobjekt erfüllt die Anforderungen, um in einem `constexpr`-Kontext verwendet werden zu können.
    //]

    //[out1
    for(const auto& x : a1) {
        std::cout << x << std::endl;
    }
    //]
    
    //[iife    
    constexpr auto a2 = []{ // <> Der Lambda-Ausdruck liefert das anonyme Funktionsobjekt ... 
        std::array<int, 10> a{};
        for(size_t i = 0; i < a.size(); ++i) {
            a[i] = 2 * (int)i + 1;
        }        
        return a;
    }(); // <> ... das hier unmittelbar aufgerufen wird.
    //]

    //[out2
    for(const auto& x : a2) {
        std::cout << x << std::endl;
    }
    //]
}
