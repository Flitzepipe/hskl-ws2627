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
#include "point42.h"

int main()
{
    const Point p1;
    std::cout << p1 << std::endl; // <> Verkettung und links-assoziative Auswertung

    Point p2{1.0, 2.0};
    p2.setColor("red");
    operator<<(std::cout, p2); // <> Da der Ausgabe-Operator als freie Funktion realisiert wurde, kann man ihn bzw. die Funktion auch so aufrufen (sehr ungebräuchlich!)
    operator<<(std::cout, '\n');
}

