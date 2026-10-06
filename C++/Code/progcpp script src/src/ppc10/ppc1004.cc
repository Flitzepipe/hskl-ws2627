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
#include <cassert>
#include <cstdlib>

class IntegerArray // <> POD-Typ um die Informationen _Anfangszeiger_ und _Länge_ zu kapseln
{
public:
#ifdef _MSC_VER //-
    IntegerArray(const int* const array, const size_t size) : items(array), size(size) {} //-
#endif //-
    const int* const items{nullptr};
    const size_t size{0};
};

int absoluteSum(const IntegerArray& array)
{
    assert(array.items); // <> Zusicherung für einen gültigen Anfangszeiger
    int sum = 0;
    for(size_t i = 0; i < array.size; ++i) {
        sum += std::abs(array.items[i]);
    }
    return sum;
}

int main()
{
    const size_t length = 5;
    const int array[length] = {1, 2, -3, -4, 5};

    std::cout << absoluteSum({array, length}) << std::endl;
}
