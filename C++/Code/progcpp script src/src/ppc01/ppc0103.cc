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
//[mainerror
//[main -error
#include <iostream>
#include "point03.h" // <> Bindet die nochmals verbesserte Deklaration des Typs `Point` ein

int main()
{
    double x{1.0};  // <> Definition und Initialisierung der Variable `x` vom Typ `double`
    double y{2.0};  // <> Definition und Initialisierung der Variable `y` vom Typ `double`
    Point p1{x, y}; // <> Definition und Initialisierung der Variable `p1` vom Typ `Point` mit dem allgemeinen *Konstruktor*
    std::cout << "x=" << p1.getX() << "\ty=" << p1.getY() << std::endl;
    //[error
#ifdef WITH_ERROR   // <> Um die Fehlermeldung zu sehen, muss mit dem Schalter -DWITH_ERROR kompiliert werden
    Point p2;       // <> Das geht nun leider nicht mehr
#endif
    //]
}
//]
//]
