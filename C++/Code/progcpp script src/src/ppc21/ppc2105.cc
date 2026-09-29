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
#include <vector>

#include "heaparray15.h"

#pragma GCC diagnostic ignored "-Wunused-variable"
#pragma GCC diagnostic ignored "-Wmissing-braces"

int main()
{
    //[std1
    int i1{0}; // <> scalare Initialisierung
    int ca1[]{1, 2}; // <> Statisches _rohes_ Array
    std::array<int, 3> a1{1, 2, 3}; // <> {stdarray}-template der Länge 3
    std::vector<int> v1{1, 2, 3}; // <> {stdvector}-template der Länge 3
    //]
    //[std2
    int ca2[] = {1, 2}; // <> Kopierinitialisierungen
    std::array<int, 3> a2 = {1, 2, 3};
    std::vector<int> v2 = {1, 2, 3};
    //]
    //[ilist
    HeapArray<int> ha1({1, 2, 3, 4, 5, 6}); // <> Dies ist bei _jedem_  Funktionsaufruf möglich
    HeapArray<int> ha2{1, 2, 3, 4, 5, 6}; // <> Dies geht nur bei Konstruktoren (Initialisierung).
    HeapArray<int> ha3{10}; // <> Konstruktoren mit `std::initializer_list<T>` als Parameter haben _Vorrang_!
    HeapArray<int> ha4(10); // <> Aufruf des Konstruktors `HeapArray(size_t)`
    //]

    std::cout << ha1.size() << std::endl;
    std::cout << ha2.size() << std::endl;
    std::cout << ha3.size() << std::endl;
    std::cout << ha4.size() << std::endl;
}
