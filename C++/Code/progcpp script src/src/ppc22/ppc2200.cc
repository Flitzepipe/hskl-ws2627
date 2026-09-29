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
#include <memory>

int main() {
    //[static
    const int length = 3;
    int staticArray[length] = {1, 2, 3}; // <> `a` ist der Bezeichner eines _statischen, rohen_ Arrays

    const int* iterator1 = &staticArray[0]; // <> `iterator1` wird mit der Adresse des ersten Array-Elementes initialisiert
    for(size_t i = 0; i < length; ++i) { // <> Mit Hilfe der Längenangabe `length` kann die Zählschleife formuliert werden
        std::cout << *iterator1++ << std::endl; // <> Durch die _Zeigerarithmetik_ erhält `iterator1` jeweils die Adresse des nächsten Elementes
    }
    //]
    //[dynamic
    std::unique_ptr<int[]> dynamicArray = std::make_unique<int[]>(2 * length); // <> Die Erzeugung eines _dynamischen_ Arrays: natürlich verwenden wir einen intelligenten Zeiger (*UP*), um eine korrekte Speicherverwaltung zu erreichen. Zudem verwendet {stdmake_unique} ein _value-initialization_.
    const int* iterator2 = &dynamicArray[0]; // <> `iterator2` wird mit der Adresse des ersten Array-Elementes initialisiert
    for(size_t i = 0; i < 2 * length; ++i) { // <> Achtung: die richtige Länge verwenden!
        std::cout << *iterator2++ << std::endl;
    }

    //]
    //[iterator1
    const int* beginIter1 = &staticArray[0]; // <> `beginIter1` wird mit der Adresse des ersten Array-Elementes initialisiert.
    const int* endIter1 = &staticArray[length - 1]; // <> `endIter1` wird mit der Adresse des letzten Array-Elementes initialisiert.

    for(const int* iterator = beginIter1; iterator <= endIter1; ++iterator) {
        std::cout << *iterator << std::endl;
    }
    //]
    //[iterator2
    const int* beginIter2 = &staticArray[0]; // <> `beginIter2` wird mit der Adresse des ersten Array-Elementes initialisiert.
    const int* endIter2 = &staticArray[length - 1] + 1; // <> `endIter2` wird mit der Adresse des nicht-existierenden eins-nach-dem-letzten Array-Elementes initialisiert.

    for(const int* iterator = beginIter2; iterator != endIter2; ++iterator) {
        std::cout << *iterator << std::endl;
    }
    //]
}
