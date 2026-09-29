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

#include "../ppc.h"

#include <iostream>
#include <string>

#ifndef _MSC_VER
# pragma GCC diagnostic ignored "-Wunused-variable"
# ifndef __clang__
#  pragma GCC diagnostic ignored "-Wunused-but-set-variable"
# endif
#endif
//[A -udl
class A
{
public:
    A(const std::string&) {
        std::cout << __PRETTY_FUNCTION__ << std::endl; //-
    }
};

int main()
{
    std::string s = "abc"; // <> Hier kommt der Typumwandlungskonstruktor `std::string(const char*)` zum Einsatz.

    A a1{"abc"}; // <> Auch hier findet eine _implizite_ Typumwandlung von `const char*` nach `std::string` statt.
//    A a2 = "abc"; // <> Nicht möglich, weil nur *einstufige*, implizite Typwandlungen ausgeführt werden;

#ifndef _MSC_VER //-
    //[udl
    using namespace std::literals::string_literals; // <> Spezialfall: Einbinden der Typumwandlungen für _user defined literals_, in diesem Fall `"abc"s` -> `std::string`
    A a3 = "abc"s;
    //]
#endif //-
}
//]
