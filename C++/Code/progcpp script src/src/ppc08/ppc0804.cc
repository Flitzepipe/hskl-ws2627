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

#include "pointlist04.h"

int main() {
    PointList pl;
    pl += Point{XCoor{1.0}, YCoor{2.0}}.setColor("red");
    pl += Point{XCoor{3.0}, YCoor{4.0}}.setColor("cyan");

    PointList pl2;

    swap(pl, pl2);

    std::cout << "front: " << pl2.front() << std::endl;
    pl2.pop_front();
    std::cout << "front: " << pl2.front() << std::endl;
    pl2.pop_front();
}
