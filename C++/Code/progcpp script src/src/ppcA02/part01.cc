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

#include "complexnumber10.h"

//[main
int main()
{
    const ComplexNumber cn1;

    assert(cn1.isReal()); // <> Die Zahl (0.0, 0.0) erfüllt beide Prädikate.
    assert(cn1.isImag());


    const ComplexNumber cn2{1.0}; // <> Dies ist eine _reelle_ Zahl.

    assert(cn2.isReal());
    assert(!cn2.isImag());

    const ComplexNumber cn3{0.0, 1.0}; // <> Dies ist die imaginäre Einheit _i_ (oder _j_ für den Elektrotechniker)

    assert(!cn3.isReal());
    assert(cn3.isImag());
}
//]
