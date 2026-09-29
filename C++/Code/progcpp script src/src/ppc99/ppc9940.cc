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
#include <type_traits>

template<typename T>
struct F {
    F(const T& f) : mf{f} {
        std::cout << __PRETTY_FUNCTION__ << '\n';
    }
    void test() {
        std::cout << __PRETTY_FUNCTION__ << '\n';
        mf();
    }
    std::decay_t<T> mf;
//    const T& mf;
};

//template<typename T>
//struct F<T*> {
//    F(T f) : mf{f} {
//        std::cout << __PRETTY_FUNCTION__ << '\n';
//    }
//    void test() {
//        std::cout << __PRETTY_FUNCTION__ << '\n';
//        mf();
//    }
//    T* mf;
//};

void g() {
    std::cout << __PRETTY_FUNCTION__ << '\n';
}

int main() {
    F<void(void)> f1(g);
    f1.test();
    
    auto g1 = g; // decay to function pointer
    
    F f2(g1);
    f2.test();
    
    F f3([](){ // lifetime?
        std::cout << __PRETTY_FUNCTION__ << '\n';
    });
    f3.test();

    auto l1 = [](){
        std::cout << __PRETTY_FUNCTION__ << '\n';
    };
    F f4(l1);
    f4.test();
}
