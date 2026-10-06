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

#include "list11.h"

#include "../lib/simpletest.h"

SIMPLETEST("std ctor") {
    List<int> l1;

    if (l1.size() != 0) return false;

    return true;
};

SIMPLETEST("ilist") {
    List<int> l1 = {1, 2, 3};

    if (l1.size() != 3) return false;

    return true;
};

SIMPLETEST("op+=") {
    List<int> l1 = {1, 2, 3};

    l1 += 4;

    if (l1.size() != 4) return false;

    return true;
};

SIMPLETEST("swap1") {
    List<int> l1 = {1, 2, 3};
    List<int> l2;

    l1.swap(l2);

    if (l2.size() != 3) return false;

    return true;
};

SIMPLETEST("swap2") {
    List<int> l1 = {1, 2, 3};
    List<int> l2;

    swap(l1, l2);

    if (l2.size() != 3) return false;

    return true;
};

SIMPLETEST("cctor") {
    List<int> l1 = {1, 2, 3};
    List<int> l2(l1);

    if (l2.size() != 3) return false;

    return true;
};

SIMPLETEST("mctor") {
    List<int> l1(List<int>() += 1);

    if (l1.size() != 1) return false;

    return true;
};

SIMPLETEST("copy=") {
    List<int> l1 = {1, 2, 3};
    List<int> l2;

    l2 = l1;

    if (l2.size() != 3) return false;

    return true;
};

SIMPLETEST("move=") {
    List<int> l1;
    List<int> l2;

    l2 = (List<int>() += 1);

    if (l2.size() != 1) return false;

    return true;
};

SIMPLETEST("empty") {
    List<int> l1;

    if (!l1.empty()) return false;

    l1 += 1;

    if (l1.empty()) return false;

    l1.pop_front();

    if (!l1.empty()) return false;
    return true;
};

SIMPLETEST("clear") {
    List<int> l1;

    l1 += 1;
    l1 += 2;

    if (l1.size() != 2) return false;

    l1.clear();

    if (!l1.empty()) return false;
    return true;
};

SIMPLETEST("front") {
    List<int> l1;

    l1 += 1;
    l1 += 2;

    if (l1.front() != 1) return false;
    return true;
};
