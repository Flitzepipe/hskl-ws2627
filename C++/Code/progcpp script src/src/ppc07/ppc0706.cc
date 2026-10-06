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
#include <vector>
#include <memory> // <> Header-Datei für `std::shared_ptr` und `std::make_shared`
#include "point60.h"

std::vector<std::shared_ptr<Point>> createPoints()
{
    std::vector<std::shared_ptr<Point>> points;

    const std::shared_ptr<Point> p1{std::make_shared<Point>(XCoor{0.0}, YCoor{0.0})};
    const std::shared_ptr<Point> p2{std::make_shared<Point>(XCoor{10.0}, YCoor{10.0})};
    const std::shared_ptr<Point> p3{std::make_shared<Point>(XCoor{20.0}, YCoor{20.0})};

    std::cout << *p1 << std::endl;
    std::cout << *p2 << std::endl;
    std::cout << *p3 << std::endl;

    points.push_back(p1);
    points.push_back(p2);
    points.push_back(p3);

    return points; // <> Ergebnisrückgabe des Containers per _Kopie_
}

int main()
{
    const std::vector<std::shared_ptr<Point>> points{createPoints()};

    for(const std::shared_ptr<Point>& p: points) {
        if (p) { // <> checked-pointer idiom
            std::cout << *p << std::endl;
        }
    }
}
