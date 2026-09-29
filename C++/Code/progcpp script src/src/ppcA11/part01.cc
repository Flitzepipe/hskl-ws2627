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

#include <cstdlib>

#include <iostream>

#include "svgfile.h"
#include "complexnumber90.h"
#include "complexvector60.h"
#include "complexpolygon30.h"

int main()
{
    SVGFile svgFile("test.svg");

    ComplexNumber cn1{10, 20};
    svgFile.add(cn1);

    ComplexVector cv1{{20, 20}, {30, 30}};
    svgFile.add(cv1);

    ComplexPolygon cp1{{40, 40}, {60, 40}, {50, 60}};
    svgFile.add(cp1);


    svgFile.add(cn1.svg()); // <> Eine Möglichkeit, die Schnittstelle zu vereinfachen
    svgFile.add(cv1.svg());
    return EXIT_SUCCESS;
}
