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

#include <list>
#include <vector>
#include <iostream>

#include <experimental/source_location>

struct A {
    A() = default;
    A(const A&) = delete;
    A(A&&) = default;
    
    static void test() {
        auto sl = std::experimental::source_location::current(__FILE__, __PRETTY_FUNCTION__);
        std::cout << sl.function_name() << std::endl;
        
    }
};

int main() {
    A a;
    std::list<A> l;    
    l.push_back(A());
//    l.push_back(a);
    std::vector<A> v;    
    v.push_back(A());
    v.push_back(A());
    v.push_back(A());
    
    auto sl = std::experimental::source_location::current();
    std::cout << sl.function_name()<< std::endl;
    
    A::test();
}
