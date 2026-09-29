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

#include "point100.h" // <> Inklusion der Defintion des Klassentemplates
#include "double.h"

int main()
{
    Point<float> p1(1.0, 2.0); // <> _Explizite_ Instanziierung mit dem DT `float`
    std::cout << p1 << std::endl;

    Point<double> p2(1.0, 2.0); // <> _Explizite_ Instanziierung mit dem DT `double`
    std::cout << p2 << std::endl;

    Point<Double> p3(1.0, 2.0); // <> _Explizite_ Instanziierung mit dem DT `Double` (s.a. `double.h`)
    std::cout << p3 << std::endl;
}
