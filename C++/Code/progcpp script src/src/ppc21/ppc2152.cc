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

#include <cmath>

//[class
class Point {
public:
    Point(double x = 0.0, double y = 0.0); //-
    double x() const; //-
    double y() const; //-
    double distance(const Point& p) const;
private:
    double mX = 0; //-
    double mY = 0; //-
};
//]
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-variable"
int main() {
    Point p1(1, 2);
    Point p2(3, 4);

    double d = p1.distance(p2);
}
#pragma GCC diagnostic pop
//[class
double Point::distance(const Point& p) const
{
    return std::hypot(p.mX - mX, p.mY - mY);
}
//]

Point::Point(double x, double y) :
    mX(x), mY(y)
{
}

double Point::x() const
{
    return mX;
}

double Point::y() const
{
    return mY;
}

