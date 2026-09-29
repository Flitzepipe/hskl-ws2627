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

#ifndef _MSC_VER
# pragma GCC diagnostic ignored "-Wunused-variable"
#endif

//[example
int maximum(int a, int b) { // <> Der Algorithmus zur Maximum-Bestimmung für den Datentyp `int`
    if (a > b) { // <> Zur Bestimmung des Maximums zweier Werte ist die `>`-Relation für den Datentyp (hier `int`) notwendig.
        return a;
    }
    return b;
}

double maximum(double a, double b) { // <> Der Algorithmus zur Maximumbestimmung für den Datentyp `double` ist strukturell identisch mit dem für den Datentyp `int`.
    if (a > b) {
        return a;
    }
    return b;
}

int main()
{
    int x = maximum(1, 2);
    double y = maximum(1.1, 2.2);
}
//]
