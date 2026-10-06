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

int main()
{
    //[a
    std::vector<int> v1 = {1, 2, 3, 4, 5}; // <> Definition und Initialisierung mit den Werten der Initialisierungsliste
    std::vector<int> v2(5, 42); // <> *Achtung*: Definition und Konstruktion mit 5 Elementen mit dem Wert 42

    std::cout << "v1 size: " << v1.size() << std::endl; // <> Elementfunktion `std::vector<T>::size_type std::vector<T>::size()`
    std::cout << "v2 size: " << v2.size() << std::endl;

    std::cout << "v1[3]: " << v1[3] << std::endl; // <> Subscript-Operator `const T& std::vector::operator[] const`
    std::cout << "v2[3]: " << v2[3] << std::endl;

    v1.push_back(6); // <> Elementfunktion `std::vector<T>::push_back(const T&)` zum Einfügen am Ende
    v2.push_back(6);

    for(size_t i = 0; i < v1.size(); ++i) { // <> `for`-Schleife mit Iterationsvariable com Typ `size_t`
        std::cout << "v1[" << i << "]: " << v1[i] << std::endl;
    }
    for(const int& element: v2) { // <> `range-for`-Schleife: `element` ist iterativ eine `const`-Referenz für die Elemente des Containers `v2`
        std::cout << "v2[]: " << element << std::endl;
    }
    //]
    //[b
    for(std::vector<int>::size_type i = 0; i < v1.size(); ++i) { // <> Der Ergebnistyp von `std::vector<T>::size()` ist _implementierungsabhängig_
        std::clog << "v1[" << i << "]: " << v1[i] << std::endl;
    }
    for(decltype(v1.size()) i = 0; i < v1.size(); ++i) { // <> Automatische Typinferenz für den Ergebnistyp von `size()`
        std::clog << "v1[" << i << "]: " << v1[i] << std::endl;
    }
    for(const auto& element: v2) { // <> Automatische Typinferenz für den Elementtyp von `v2`
        std::clog << "v2[]: " << element << std::endl;
    }
    //]
}
