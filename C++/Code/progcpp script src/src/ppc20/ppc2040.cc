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
#include <iostream>

//[main
#include "heaparray.h"
#include "point90.h"

int main()
{
    HeapArray<Point> ha(5); // <> Erzeugen eines Containers des Typs `HeapArray` _parametriert_ mit dem Elementttyp `Point` und der Größe von 5 Elementen. Die Elemente werden mit Hilfe des Standard-Konstruktors initialisiert (_value_initialization_);

    for(size_t i = 0; i < ha.size(); ++i) {
        std::cout << ha[i] << std::endl; // <> _subscript_-Operator für den Elementzugriff.
    }
}
//]
