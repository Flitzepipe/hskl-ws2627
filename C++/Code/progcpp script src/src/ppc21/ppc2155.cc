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
#include <string>
#include <iostream>
#include <sstream>

size_t nextSerialNumber()
{
    static size_t counter = 0;
    return ++counter;
}

//[class1 -a
class Point {
    friend std::istream& operator>>(std::istream& in, Point& p); // <> gemischte Operation mit Seiteneffekt: Mutatoren sind nicht ausreichend
public:
    //[a
    Point(double x = 0.0, double y = 0.0);
    double x() const;
    double y() const;
    //]
    const std::string& name() const; // <> reine Beobachterfunktion
    Point& name(const std::string& name); // <> reine Mutatorfunktion
private:
    //[a
    double mRadius = 0.0;
    double mAngle = 0.0;
    //]
    std::string mName; // <> Änderung: neues Datenelement
    const size_t mSerialNumber = nextSerialNumber(); // <> Änderung: neues Datenelement
};
std::ostream& operator<<(std::ostream& out, const Point& p) // <> gemischte Operation mit Seiteneffekt: Observatoren reichen aus.
{
    return out << "Point[" << p.x() << "," << p.y() << "]";
}

std::istream& operator>>(std::istream& in, Point& p) // <> gemischte Operation mit Seiteneffekt: es gibt keine Mutatoren für _Radius_ und _Winkel_.
{
    return in >> p.mRadius >> p.mAngle;
}

double distance(const Point& p1, const Point&p2); // <> allgemeine Operation des Typs `Point`

//]
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused"
int main() {
    Point p1(1, 2);
    Point p2(3, 4);

    std::cout << p1 << std::endl;

    std::istringstream ss{"1.0 3.14"};
    ss >> p1;


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

const std::string& Point::name() const
{
    return mName;
}

Point& Point::name(const std::string& name)
{
    mName = name;
    return *this;
}
//]

