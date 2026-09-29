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

#include "templates.h" // <> Inklusion der Template-Definitionen
#include "integer.h" // <> Deklaration der Klasse `Integer`

#ifndef _MSC_VER //-
# pragma GCC diagnostic ignored "-Wunused-variable" //-
# ifndef __clang__ //-
#  pragma GCC diagnostic ignored "-Wunused-but-set-variable" //-
# endif //-
#endif //-

//[main
int main()
{
    Integer i1{1};
    Integer i2{2};

    Integer i3 = maximum(i1, i2); // <> *Implizite* Instanziierung mit der Typableitung: `T` -> `Integer`
    Integer i4 = minimum<Integer>(i1, i2); // <> *Explizite* Instanziierung: `T` -> `Integer`

    double d = maximum<double>(1, 2); // <> Explizite Instanziierung: `T` -> `double`. Beachte: bei der Parameterübergabe findet noch eine Typkonvertierung von `int` -> `double` statt.
}
//]
