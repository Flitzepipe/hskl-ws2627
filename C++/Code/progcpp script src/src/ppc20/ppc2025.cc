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
#include <memory>

//[ex -t
template<typename T, int N = 10> // <> Hier hat der _nicht-Typ_-Parameter `N` den Vorgabewert `10` 
std::unique_ptr<T[]> foo() {
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    return std::make_unique<T[]>(N); // <> Überladene Variante von {stdmake_unique}
}

int main()
{
    auto array = foo<int, 100>();
    //[t
    array[0]  = 0;
    array[99] = 99;

    std::cout << "array[0]: " << array[0] << std::endl;
    std::cout << "array[99]: " << array[99] << std::endl;
    //]
}
//]
