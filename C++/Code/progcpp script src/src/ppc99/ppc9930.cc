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

#include <malloc.h>

#include <iostream>
#include <chrono>
#include <vector>
#include <memory>

template <typename T>
struct fooBase {
   void test1() { std::cout << __PRETTY_FUNCTION__ << std::endl; }
   void test2() { std::cout << __PRETTY_FUNCTION__ << std::endl; }

};

template<typename T>
struct foo : fooBase<T> {};

template <>
struct foo<int> : fooBase<int> {

   // Hier soll test1() von foo<T> verwendet werden ohne es explizit zu sagen
   void test2() { std::cout << __PRETTY_FUNCTION__ << std::endl; } // test2 wurde "überschrieben"
};


int main() {
    foo<int> f1;
    foo<float> f2;
    
    f1.test1();
    f1.test2();

    f2.test1();
    f2.test2();
    
}
