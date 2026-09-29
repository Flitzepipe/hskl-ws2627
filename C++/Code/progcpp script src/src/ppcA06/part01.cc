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

#include "complexnumber50.h"
#include "complexvector20.h"

int main()
{
    ComplexNumber cn1{42, 24};
    cn1.name("Eine Zahl");
    cn1.color("blue");

    std::cout << cn1 << std::endl;

    ComplexNumber cn2 = 1.0; // <> Dies ist ein sinnvoller Einsatz des _Typumwandlungskonstruktors_: die _reelle_ Zahl `1.0` wird in *diesselbe* Zahl in komplexer Darstellung umgewandelt.

    cn2 = cn1 + 3; // <> Auch hier wird die _reelle_ Zahl `3` in den Typ `ComplexNumber` _gewandelt_ und anschließend mit `cn1` addiert. Zusätzlich findet eine _implizite_ Konversion von `int` -> `double` statt.

    std::cout << cn2 << std::endl;
}
