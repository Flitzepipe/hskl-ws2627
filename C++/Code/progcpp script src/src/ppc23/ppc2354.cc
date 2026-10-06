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
#include <vector>
#include <list>
#include <array>

#ifndef _MSC_VER
# pragma GCC diagnostic ignored "-Wunused-variable"
#endif

template<template<typename> typename C, typename ItemType>
struct Database { // <> Allgemeines Template
    using container_t = C<ItemType>;
    Database& operator+=(const ItemType& v) {
        container.push_back(v);
        return *this;
    }
private:
    container_t container;
};

template<typename T>
using a_t = std::array<T, 100>; // <> Dieses Alias-Template ist notwendig, damit die folgende Spezialisierung funktioniert

template<typename ItemType>
struct Database<a_t, ItemType> { // <> Der erste Parameter muss weiterhin ein Template mit einem Typ-Parameter sein, daher ist das obenstehende Alias-Template notwendig
    using container_t = a_t<ItemType>;
    Database& operator+=(const ItemType& v) {
        if (index < container.size()) {
            container[index++] = v;
        }
        return *this;
    }
private:
    size_t index{0};
    container_t container;
};

struct A {
};


int main() {
    Database<std::vector, A> db1;
    db1 += A{};
    
    Database<std::list, A> db2;
    db2 += A{};

    Database<a_t, A> db3;
    db3 += A{};
}
