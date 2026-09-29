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

class XCoor
{
public:
#ifdef _MSC_VER //-
    XCoor(double v) : mValue{v} {} //-
#endif //-
    double mValue{0.0};
};

class YCoor
{
public:
#ifdef _MSC_VER //-
    YCoor(double v) : mValue{v} {} //-
#endif //-
    double mValue{0.0};
};

class Radius {
    friend class Point;
    friend Radius operator*(Radius a, Radius b);
    friend Radius operator*(double a, Radius b);
    friend Radius operator*(Radius a, double b);
public:
    explicit Radius(double r);
private:
    double mValue{0.0};
};

class Angle
{
    friend Angle operator+(Angle a, Angle b);
public:
#ifdef _MSC_VER //-
    Angle(double r) : mRadiant{r} {} //-
#endif //-
    double mRadiant{0.0};
};

//[DPoint
class DPoint { // <> Die Klasse ist wieder ein `POD`
public:
#ifdef _MSC_VER //-
    DPoint(int x, int y) : mX{x}, mY{y} {} //-
#endif //-
    int mX{0};
    int mY{0};
};
//]
//[DRect
class DRect
{
public:
    DRect(DPoint upperLeft = DPoint{0,0}, DPoint bottomRight = DPoint{0,0});
    int width() const;
    int height() const;
    int area() const;
    explicit operator bool() const; // <> Dies ist ein _Typumwandlungsoperator_: `DRect` -> `bool`
    DPoint upperLeft() const;
    DPoint bottomRight() const;
    DRect& operator+=(const DRect& rhs); // <> Die Addition bedeutet die Vereinigung zu einem umschreibenden Rechteck.
private:
    DPoint mUpperLeft{0, 0};
    DPoint mBottomRight{0, 0};
};
//]
DRect operator+(const DRect& a, const DRect& b);

class Point
{
    friend std::ostream& operator<<(std::ostream& outputStream, const Point& p);
    friend double operator-(const Point&, const Point&);
    friend bool operator==(const Point&, const Point&);
    friend bool operator!=(const Point&, const Point&);
public:
    Point(XCoor x = XCoor{0.0}, YCoor y = YCoor{0.0});
    Point(Radius r, Angle phi);
    double getX() const;
    double getY() const;
    const std::string& getColor() const;
    std::string toSVG() const;
    DRect svgArea() const;
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
};
double distance(const Point&, const Point&);

std::ostream& operator<<(std::ostream& outputStream, const Point& p);
double operator-(const Point&, const Point&);
bool operator==(const Point&, const Point&);
bool operator!=(const Point&, const Point&);
