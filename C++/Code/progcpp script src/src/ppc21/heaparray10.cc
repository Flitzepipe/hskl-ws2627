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

#include "heaparray10.h"

#include "../lib/simpletest.h"

#include "math.h"

//[traits
#include <type_traits>

static_assert(!std::is_default_constructible<HeapArray<int>>::value, "HeapArray<T> must not be default-constructible");

static_assert(!std::is_copy_constructible<HeapArray<int>>::value, "HeapArray<T> must not be copy-constructible");
static_assert(!std::is_copy_assignable<HeapArray<int>>::value, "HeapArray<T> must not be copy-assignable");

static_assert(std::is_move_constructible<HeapArray<int>>::value, "HeapArray<T> should be move-constructible");
static_assert(std::is_move_assignable<HeapArray<int>>::value, "HeapArray<T> should be move-assignable");
//]

//[tests
SIMPLETEST("ctor1") {
    const int size = 100;
    HeapArray<int> ha{size};

    if (ha.size() != size) return false;
    return true;
};

SIMPLETEST("ctor2") {
    const int size = 100;
    HeapArray<int> ha{size};

    for(size_t i = 0; i < ha.size(); ++i) {
        if (ha[i] != 0) return false;
    }
    return true;
};

SIMPLETEST("ctor3") {
    const int size = 100;
    HeapArray<int> ha{size};

    for(size_t i = 0; i < ha.size(); ++i) {
        ha[i] = 42;
    }
    const HeapArray<int>& ha2 = ha;
    for(size_t i = 0; i < ha.size(); ++i) {
        if (ha2[i] != 42) return false;
    }

    return true;
};

SIMPLETEST("ctor4") {
    const int size = 100;
    HeapArray<long double> ha{size};

    for(size_t i = 0; i < ha.size(); ++i) {
        if (!Math::equal(ha[i], 0.0L)) return false;
    }
    return true;
};

SIMPLETEST("move assign") {
    HeapArray<int> ha{100};

    ha = HeapArray<int>(2);

    if (ha.size() != 2) return false;

    return true;
};

SIMPLETEST("move construct") {
    HeapArray<int> ha = HeapArray<int>(2);

    if (ha.size() != 2) return false;

    return true;
};

SIMPLETEST("move construct2") {
    HeapArray<int> hx = HeapArray<int>(2);
    hx[1] = 42;

    HeapArray<int> ha = std::move(hx);

    if (ha.size() != 2) return false;
    if (ha[1] != 42) return false;

//    if (hx.size() != 0) return false;

    return true;
};

SIMPLETEST("swap1") {
    HeapArray<long double> ha1{10};
    HeapArray<long double> ha2{20};

    ha1.swap(ha2);

    if (ha1.size() != 20) return false;
    if (ha2.size() != 10) return false;

    return true;
};


//]
