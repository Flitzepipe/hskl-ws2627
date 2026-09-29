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

//[meta
template<typename T>
struct remove_const { // <> Das allgemeine Template (passt generell auf jeden Typ `T`)
    typedef T type;
};
template<typename T>
struct remove_const<const T> { // <> Die partielle Spezialisierung passt nur auf `const T`-Typen
    typedef T type;
};
//]
//[foo
template<typename T>
void foo() {
    std::cout << __PRETTY_FUNCTION__ << '\n';
}
//]
int main() 
{
    //[main
    int x1 = 0;
    const int x2 = 0;
    foo<remove_const<decltype(x1)>::type>();
    foo<remove_const<decltype(x2)>::type>();
    //]
}
