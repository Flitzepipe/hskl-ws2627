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
#include <array>
#include <utility>
#include <cassert>

void foo(const int* const array)
{
    assert(array);
    std::cout << __PRETTY_FUNCTION__ << " array: " << array << std::endl;
//    for(const int& x: array) { // <> Nicht möglich wegen fehlender Längeninformation, denn `array` ist lediglich eine Zeigerparametervariable
//        std::cout << x << std::endl;
//    }
    for(size_t i = 0; i < 5; ++i) {
        std::cout << array[i] << std::endl;
    }
}

void foo(const std::array<int,5>& array)
{
    std::cout << __PRETTY_FUNCTION__ << " array: " << &array << std::endl;
    for(const int& x: array) {
        std::cout << x << std::endl;
    }

}

void bar(const std::array<int,5> array)
{
    std::cout << __PRETTY_FUNCTION__ << " array: " << &array << std::endl;
    for(const int& x: array) {
        std::cout << x << std::endl;
    }

}

void foo(const int* const array, const size_t size)
{
    assert(array);
    assert(size > 0);
    std::cout << __PRETTY_FUNCTION__ << " array: " << array << std::endl;
    for(size_t i = 0; i < size; ++i) {
        std::cout << array[i] << std::endl;
    }
}

void foo(const std::pair<const int* const, size_t>& arrayPair)
{
    assert(arrayPair.first);
    assert(arrayPair.second > 0);
    std::cout << __PRETTY_FUNCTION__ << " array: " << arrayPair.first << std::endl;
    for(size_t i = 0; i < arrayPair.second; ++i) {
        std::cout << arrayPair.first[i] << std::endl;
    }
}

void foo(const char* const cstring)
{
    assert(cstring);
    for(size_t i = 0; cstring[i] != '\0'; ++i) {
        std::cout << *(cstring + i);
    }
    std::cout << std::endl;
}

void foo(const char* const * cstrings)
{
    assert(cstrings);
    while(*cstrings) {
        std::cout << __PRETTY_FUNCTION__ << *cstrings << std::endl;
        ++cstrings;
    }
}

int main() {
    const int array1[5] = {0, 1, 2, 3, 4};
    const std::array<int, 5> array2 = {};

    std::cout << __PRETTY_FUNCTION__ << " array1: " << array1 << std::endl;
    std::cout << __PRETTY_FUNCTION__ << " array2: " << &array2 << std::endl;

    foo(array1);

    foo(array2);

    foo({array1, 5});

    foo(array1, 5);

    bar(array2);

    foo("abc");

    const char* array3[] = {"abc", "def", nullptr};
    foo(array3);
}
