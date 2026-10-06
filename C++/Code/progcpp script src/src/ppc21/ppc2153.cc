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
    Point(double x = 0.0, double y = 0.0);
    double x() const;
    double y() const;
private:
    double mRadius = 0.0; // <> Änderung: Darstellung als Polarkoordinaten
    double mAngle = 0.0;
};
double distance(const Point& p1, const Point&p2);
//]
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-variable"
int main() {
    Point p1(1, 2);
    Point p2(3, 4);

    double d = distance(p1, p2);
}
#pragma GCC diagnostic pop

//[class
double distance(const Point& p1, const Point& p2)
{
    return std::hypot(p1.x() - p2.x(), p1.y() - p2.y()); // <> Durch Verwendung der öffentlichen Schnittstelle dieser _freien, non-friend Funktion_ ist hier keine Änderung notwendig.
}

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
//]

