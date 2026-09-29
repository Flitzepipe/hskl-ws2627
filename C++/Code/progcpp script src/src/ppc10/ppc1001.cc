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

#include <cstdlib> // <> Notwendig für den Datentyp (Typalias) `size_t`
#include <iostream>

int main()
{
    const double array1[5] = {1.0, 2.0, 3.0, 4.0, 5.0}; // <> Vollständige Initialisierung eines _statischen_ rohen Arrays.
    const double array2[5] = {1.0}; // <> Partielle Initialisierung, die restlichen Werte werden mit dem _numerischen Standardwert_ `0.0` initialisiert
    const double array3[5] = {}; // <> Dies ist auch eine _partielle_ Initialisierung -> alle Array-Elemente werden mit `0.0` initialisiert.
    double array4[5]; // <> *Ohne Initialisierung* ist eine *Fehler*. Dieser Fehler fällt allerdings auf, wenn das Array wie oben auch als _read-only_ mit `const` qualifiziert wird.

    for(size_t i = 0; i < 5; i += 1) { // <> *Schlecht*: Weil ein _rohes_ Array kein _first-class-object_ ist, gibt es keine direkte Möglichkeit, die Länge zu bestimmen.
        std::cout << "i: " << i << "\tarray1: " << array1[i] << "\tarray2: " << array2[i] << "\tarray3: " << array3[i] << "\tarray4: " << array4[i] << std::endl;
    }
}
