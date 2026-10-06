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

#pragma once

#if __has_include("../ppc.h")
# include "../ppc.h"
#endif

#include <iosfwd>
#include <string>

//[cartesian
class XCoor // <> Diese Klasse ist ein _POD_ (plain old datatype) zur typsicheren Verwendung von `double`-Werten als x-Koordinatenwerte
{
public:
#ifdef _MSC_VER //-
    XCoor(double v) : mValue(v) {} //-
#endif //-
    double mValue{0.0};
};

class YCoor // <> Diese Klasse ist ein _POD_ (plain old datatype) zur typsicheren Verwendung von `double`-Werten als y-Koordinatenwerte
{
public:
#ifdef _MSC_VER //-
    YCoor(double v) : mValue(v) {} //-
#endif //-
    double mValue{0.0};
};
//]
//[polar
class Radius // <> Diese Klasse ist *kein* _POD_, da es einen allgemeinen Konstruktor gibt, der einen validen Zustand sicherstellt
{
    friend class Point; // <> Als Alternative zu einem _getter_ für `mValue` erhält die _Klasse_  Zugriff auf die privaten Datenelemente.
    friend Radius operator*(Radius a, Radius b);
    friend Radius operator*(double a, Radius b); // <> Diese überladene Variante ermöglicht die Multiplikation mit einem Faktor
    friend Radius operator*(Radius a, double b);
    // <> Evtl. sind weitere Operatoren sinnvoll wie `+`, `-`
public:
    explicit Radius(double r); // <> Dieser Konstruktor stellt einen validen Zustand sicher mit `r >= 0.0`
private:
    double mValue{0.0}; // <> Hier muss das Datenelement _privat_ sein, um den Zustand sicherstellen zu können.
};

class Angle // <> Diese Klasse ist ein _POD_ (plain old datatype) zur typsicheren Verwendung von `double`-Werten als Winkel in _Radiant_
{
    friend Angle operator+(Angle a, Angle b); // <> es ist nur möglich, Winkel zu addieren
    // <> Evtl. wäre der Operator `-` noch sinnvoll
public:
#ifdef _MSC_VER //-
    Angle(double a) : mRadiant(a) {} //-
#endif //-
    double mRadiant{0.0};
};
//]
//[Point -a
class Point
{
    //[a
    friend std::ostream& operator<<(std::ostream& outputStream, const Point& p);
    friend double operator-(const Point&, const Point&);
    //[opcomp
    friend bool operator==(const Point&, const Point&);
    friend bool operator!=(const Point&, const Point&);
    //]
    //]
public:
    Point(XCoor x = XCoor{0.0}, YCoor y = YCoor{0.0});
    Point(Radius r, Angle phi);
    //[a
    double getX() const;
    double getY() const;
    const std::string& getColor() const;
    std::string toSVG() const;
    static int svgRadius();
    void setX(double x);
    void setY(double y);
    void setColor(const std::string& color);
    void setColor(unsigned char r, unsigned char g, unsigned char b);
    void move(double dx, double dy);
private:
    double mX{0.0};
    double mY{0.0};
    std::string mColor{"black"};
    inline static int mSVGRadius{10};
    //]
};
//]
double distance(const Point&, const Point&);

std::ostream& operator<<(std::ostream& outputStream, const Point& p);
double operator-(const Point&, const Point&);
//[opcomp
bool operator==(const Point&, const Point&);
bool operator!=(const Point&, const Point&);
//]
