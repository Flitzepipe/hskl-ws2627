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
#include <memory> // <> Header-Datei für `std::unique_ptr` und `std::make_unique`
#include <algorithm> // <> Header-Datei für `std::move`

#ifdef __clang__
# pragma clang diagnostic ignored "-Wpessimizing-move"
#endif

#include "point60.h"

std::vector<std::unique_ptr<Point>> createPoints()
{
    std::vector<std::unique_ptr<Point>> points;

    std::unique_ptr<Point> p1{std::make_unique<Point>(XCoor{0.0}, YCoor{0.0})};
    std::unique_ptr<Point> p2{std::make_unique<Point>(XCoor{10.0}, YCoor{10.0})};
    std::unique_ptr<Point> p3{std::make_unique<Point>(XCoor{20.0}, YCoor{20.0})};

    std::cout << *p1 << std::endl;
    std::cout << *p2 << std::endl;
    std::cout << *p3 << std::endl;

    points.push_back(std::move(p1));
    points.push_back(std::move(p2));
    points.push_back(std::move(p3));

    return points; // <> Durch die *UP* ist der Container _nicht kopierbar_ sondern nur noch verschiebbar. Hier wird jedoch _guaranteed copy elison_ vom Compiler angewendet.
}

int main()
{
    const std::vector<std::unique_ptr<Point>> points{createPoints()};

    for(const std::unique_ptr<Point>& p: points) {
        if (p) {
            std::cout << *p << std::endl;
        }
    }

//    std::vector<std::unique_ptr<Point>> points2 = points; // <> Eine Kopie kann wegen der *UP* nicht erzeugt werden.
}
