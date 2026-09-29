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

int main()
{
    const size_t length = 5;
    int array[length] = {}; // <> Zur Dimensionierung sind zur Compilezeit konstante Ausdrücke zugelassen.

    array[0] = 42; // <> Elementzugriff über den _Subscript_-Operator.
    array[1] = 43;

    std::cout << "*array: " << *array << std::endl; // <> Elementzugriff über den Zeiger auf das erste Element: der Bezeichners evaluiert zu der Adresse des ersten Elements.
    std::cout << "*(array + 1): " << *(array + 1) << std::endl; // <> Elementzugriff mit Hilfe von Zeigerarithmetik: es wird _nicht_ ein Byte, sondern `sizeof(int)` Bytes addiert.

    const int* const ptr = array; // <> Für die Zielelemente ein `const` hinzugefügt.

    std::cout << "ptr[0]: " << ptr[0] << std::endl; // <> Der _Subscript_-Operator kann bei jedem Zeiger angewendet werden!
    std::cout << "ptr[1]: " << ptr[1] << std::endl;
}
