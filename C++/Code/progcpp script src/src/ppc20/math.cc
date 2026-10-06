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

#include "math.h"

#include "../lib/simpletest.h"

//[tests
SIMPLETEST("equal1") {
    double a = 1.0;
    double b = 1.1;

    if (Math::equal(a, b)) return false;
    return true;
};

SIMPLETEST("equal2") {
    long double a = 1.0;
    long double b = 1.1;

    if (Math::equal(a, b)) return false;
    return true;
};

SIMPLETEST("equal3") {
    int a = 1;
    int b = 2;

    if (Math::equal(a, b)) return false;
    return true;
};

SIMPLETEST("equal4") {
    int a = 1;
    int b = 1;

    if (!Math::equal(a, b)) return false;
    return true;
};

SIMPLETEST("toInt1") {
    if (Math::toInt(1.1) != 1) return false;
    return true;
};

SIMPLETEST("toInt2") {
    if (Math::toInt(1.1L) != 1) return false;
    return true;
};

SIMPLETEST("toFixed1") {
    if (Math::toFixed<int>(1.1L) != 1) return false;
    return true;
};

SIMPLETEST("toFixed2") {
    if (Math::toFixed<unsigned short>(1.1) != 1) return false;
    return true;
};

//]

//[members
const double& Math::pi()
{
    static double v = 2.0 * std::acos(0.0);
    return v;
}
//]
