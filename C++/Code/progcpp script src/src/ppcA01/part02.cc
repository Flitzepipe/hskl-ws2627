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

#include "complexnumber02.h" // <> *Achtung*: veränderte Version der Klasse

int main()
{
    const ComplexNumber cn1; // <> Definition einer lokalen Variable `cn1` vom Typ `ComplexNumber`
    std::cout << "cn1[" << cn1.mReal << "," << cn1.mImag << "]" << std::endl;

    const ComplexNumber cn2 = {3.0, 4.0};
    std::cout << "cn2[" << cn2.mReal << "," << cn2.mImag << "]" << std::endl;

    const ComplexNumber cn3{4.0, 5.0};
    std::cout << "cn3[" << cn3.mReal << "," << cn3.mImag << "]" << std::endl;
}
