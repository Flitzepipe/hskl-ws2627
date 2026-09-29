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
#include <vector>
#include <algorithm>

int main()
{
    //[main
    std::vector<int> v{1, -1, 2, -2, 3, -3, 4, -4, 5, -5}; // <> Ein Container mit _positivien_ und _negativen_ Werten.

    auto it = std::remove_if(std::begin(v), std::end(v), [](int v) {return v <= 0;}); // <> Das Ergebnis von `std::remove_if` ist eine Iterator, der auf das erste zu entfernende Element zeigt.
    std::cout <<*it << std::endl;
    v.erase(it, std::end(v)); // <> Ab dem Element, auf das `it` verweist, bis zum Ende des Containers werden alle Elemente entfernt.

    for(const auto& e: v) { // <> Ausgabe zur Kontrolle
        if (&e != &v[0]) {
            std::cout << ',';
        }
        std::cout << e;
    }
    std::cout << std::endl;
    //]
}
