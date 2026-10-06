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

#include <cstdlib>
#include <cassert>
#include <cmath>
#include <vector>
#include <list>
#include <array>
#include <cassert>
#include <iostream>

//[class
class Point {
public:
    Point(double x = 0.0, double y = 0.0);
    double x() const;
    double y() const;
private:
    double mRadius = 0.0;
    double mAngle = 0.0;
};
double distance(const Point& p1, const Point&p2);
//]

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-variable"

//[pathlength
template<typename T>
double pathLength(const std::vector<T>& path)
{
    double length = 0.0;
    for(size_t i = 1; i < path.size(); ++i) {
        length += distance(path[i-1], path[i]);
    }
    return length;
}
//]
//[pathlength2
template<typename C>
auto pathLength2(const C& path) // <> Der Container-Typ ist generisch: Template-Typ-Parameter C. Der Rückgabetype ist derselbe, der auch von `distance` geliefert wird.
{
    assert(std::size(path) > 1); // <> Die Verwendung der des _freien_ Funktionstemplates {stdsize} macht den Code generisch.
    auto it1 = std::cbegin(path); // <> Alle Container der {stdlib} unterstützen _Iteratoren_, aber nicht alle den _subscript_-Operator.
    auto it2 = it1;
    ++it2; // <> Alternativ könnte man hier das freie Funktionstemplate {stdadvance} einsetzen.
    decltype(distance(*it1, *it1)) length = 0; // <> Die lokale Variable sollte _denselben_ Typ besitzen wie die freie Funktion `distance()`.
    while(it2 != std::cend(path)) { // <> Eine Schleife über den gesamten Container ohne Verwendung des _subscript_-Operators `operator[]`.
        length += distance(*it2++, *it1++);
    }
    return length; // <> Der Typ der Variablen `length` bestimmt den Rückgabetyp dieses Funktionstemplates.
}
//]
//[main
int main() {
    //[m1
    std::vector<Point> points = {{0.0, 0.0}, {1.0, 1.0}, {2.0, 2.0}};
    double l1 = pathLength(points);
    //]
    //[m2
    std::vector<double> values = {0.0, 1.0, 2.0};
    double l2 = pathLength(values);
    //]
    double l11 = pathLength2(points);
    double l21 = pathLength2(values);

    //[mg
    //[m3
    std::list<int> values2 = {0, 0};
    double l3 = pathLength2(values2);
    //]

    //[m4
    std::array<float, 3> values3 = {{1, 2, 3}};
    double l4 = pathLength2(values3);
    //]

    //[m5
    double values4[4] = {0, 1, 2, 10};
    double l5 = pathLength2(values4);
    //]
    //]
}
//]

#pragma GCC diagnostic pop

//[class
double distance(const Point& p1, const Point& p2)
{
    return std::hypot(p1.x() - p2.x(), p1.y() - p2.y());
}
//]

Point::Point(double x, double y) :
    mRadius(std::hypot(x, y)), mAngle(std::atan2(y, x))
{
}

double Point::x() const
{
    return mRadius * std::cos(mAngle);
}

double Point::y() const
{
    return mRadius * std::sin(mAngle);
}

