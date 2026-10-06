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
#include <cassert>
#include <cstdlib>

#include "complexnumber80.h"
#include "complexvector50.h"
#include "complexpolygon10.h"
#include "trace10.h" // <> Diese _include_-Datei wird für die Seriennummernverwaltung benötigt.

int main()
{
    ComplexNumber cn1{0, 0};
    ComplexNumber cn2{10, 0};
    ComplexNumber cn3{10, 10};
    ComplexNumber cn4{0, 10};

    ComplexPolygon cp{cn1, cn2, cn3};

    if (trace) {
        std::cout << cp << std::endl;

        cp << cn4; // <> Anfügen mittels des `<<`-Operators

        std::cout << cp << std::endl;

        std::cout << cp.toSVG() << std::endl;
    }

    return EXIT_SUCCESS;
}
