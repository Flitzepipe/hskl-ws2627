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

#include "point70.h"

#include "../lib/simpletest.h"
#include "math.h"

#include <cassert>
#include <cmath>
#include <sstream>
#include <algorithm>

bool operator==(const Point& p1, const Point& p2)
{
    return (Math::equal(p1.mX, p2.mX) && Math::equal(p1.mY, p2.mY));
}
bool operator!=(const Point& p1, const Point& p2)
{
    return !(p1 == p2);
}

std::ostream& operator<<(std::ostream& outputStream, const Point& p)
{
    outputStream << "Point[" << p.mSNR << "," << p.mX << "," << p.mY << "," << p.mColor << "]";
    return outputStream;
}

double operator-(const Point& a, const Point& b)
{
    return std::hypot(a.mX - b.mX, a.mY - b.mY);
}

double distance(const Point& a, const Point& b)
{
    return a - b;
}

Point::Point(const double x, const double y, const std::string& color) : 
    mX{x}, mY{y}, mColor{color}, mSNR{++mObjectCounter}
{
}

Point::Point(const XCoor x, const YCoor y) : Point{x.mValue, y.mValue}
{
}

Point::Point(const Radius r, const Angle phi) : 
    Point{r.mValue * std::cos(phi.mRadiant), r.mValue * std::sin(phi.mRadiant)}
{
}

Point::Point(const Point& other) : Point{other.mX, other.mY, other.mColor}
{
}

Point::~Point()
{
}

Point& Point::operator=(const Point& rhs)
{
    if (&rhs != this) {
        mX = rhs.mX;
        mY = rhs.mY;
        mColor = rhs.mColor;
    }
    return *this;
}

double Point::getX() const
{
    return mX;
}

double Point::getY() const
{
    return mY;
}

const std::string& Point::getColor() const
{
    return mColor;
}

std::string Point::toSVG() const
{
    std::string svgString = "<circle ";
    svgString += "cx=\"" + std::to_string(Math::toInt(mX)) + "\" ";
    svgString += "cy=\"" + std::to_string(Math::toInt(mY)) + "\" ";
    svgString += "r=\"" + std::to_string(mSVGRadius) + "\" ";
    svgString += "stroke=\"" + mColor + "\" ";
    svgString += "fill=\"" + mColor + "\" ";
    svgString +=  "/>";
    return svgString;
}

DRect Point::svgArea() const
{
    return DRect{DPoint{Math::toInt(mX) - mSVGRadius, Math::toInt(mY) + mSVGRadius}, DPoint{Math::toInt(mX) + mSVGRadius, Math::toInt(mY) - mSVGRadius}};
}

int Point::svgRadius()
{
    return mSVGRadius;
}

Point& Point::setX(const double x)
{
    mX = x;
    return *this;
}

Point& Point::setY(const double y)
{
    mY = y;
    return *this;
}

Point& Point::move(const double dx, const double dy)
{
    mX += dx;
    mY += dy;
    return *this;
}

int Point::getSNR() const
{
    return mSNR;
}

Point& Point::setColor(const std::string& color)
{
    mColor = color;
    return *this;
}

Point& Point::setColor(const unsigned char r, const unsigned char g, const unsigned char b)
{
    mColor = "rgb(" + std::to_string(r) + "," + std::to_string(g) + "," + std::to_string(b) + ")";
    return *this;
}

Radius operator*(const Radius a, const Radius b)
{
    return Radius{a.mValue * b.mValue};
}

Radius operator*(const double a, const Radius b)
{
    return Radius{a * b.mValue};
}

Radius operator*(const Radius a, const double b)
{
    return Radius{a.mValue * b};
}

Radius::Radius(const double r) : mValue{r}
{
    assert(r >= 0.0);
}

Angle operator+(const Angle a, const Angle b)
{
    return {a.mRadiant + b.mRadiant};
}

SIMPLETEST("Point ctor1") {
    Point p;

    if (!Math::equal(p.getX(), 0.0)) return false;
    if (!Math::equal(p.getY(), 0.0)) return false;

    return true;
};

SIMPLETEST("Point ctor2") {
    Point p{XCoor{1.0}, YCoor{2.0}};

    if (!Math::equal(p.getX(), 1.0)) return false;
    if (!Math::equal(p.getY(), 2.0)) return false;

    return true;
};

SIMPLETEST("Point ctor3") {
    Point p{XCoor{1.0}};

    if (!Math::equal(p.getX(), 1.0)) return false;
    if (!Math::equal(p.getY(), 0.0)) return false;

    return true;
};

SIMPLETEST("Point setX") {
    Point p;

    p.setX(1.0);
    if (!Math::equal(p.getX(), 1.0)) return false;
    if (!Math::equal(p.getY(), 0.0)) return false;

    return true;
};

SIMPLETEST("Point setY") {
    Point p;

    p.setY(1.0);
    if (!Math::equal(p.getX(), 0.0)) return false;
    if (!Math::equal(p.getY(), 1.0)) return false;

    return true;
};

SIMPLETEST("Point move") {
    Point p;

    p.move(1.1, 2.2);
    if (!Math::equal(p.getX(), 1.1)) return false;
    if (!Math::equal(p.getY(), 2.2)) return false;

    return true;
};

SIMPLETEST("Point color") {
    Point p;

    if (p.getColor() != "black") return false;

    p.setColor("red");
    if (p.getColor() != "red") return false;

    return true;
};

SIMPLETEST("Point color2") {
    Point p;

    if (p.getColor() != "black") return false;

    p.setColor(100, 101, 102);
    if (p.getColor() != "rgb(100,101,102)") return false;

    return true;
};

SIMPLETEST("Point toSVG") {
    Point p;
    if (p.toSVG() != "<circle cx=\"0\" cy=\"0\" r=\"10\" stroke=\"black\" fill=\"black\" />") return false;
    return true;
};

SIMPLETEST("Point toSVG2") {
    Point p = {XCoor{1.1}, YCoor{2.9}};
    p.setColor("red");
    if (p.toSVG() != "<circle cx=\"1\" cy=\"3\" r=\"10\" stroke=\"red\" fill=\"red\" />") return false;
    return true;
};

SIMPLETEST("Point distance") {
    Point p1;
    Point p2 = {XCoor{1.0}, YCoor{1.0}};

    if (!Math::equal(distance(p1, p1), 0.0)) return false;
    if (!Math::equal(distance(p2, p2), 0.0)) return false;
    if (!Math::equal(distance(p1, p2), std::sqrt(2.0))) return false;
    return true;
};

SIMPLETEST("Point <<") {
    Point p1;
    std::stringstream ss;

    ss << p1;

    std::string expected = "Point[" + std::to_string(p1.getSNR()) + ",0,0,black]";

    if (ss.str() != expected) return false;
    return true;
};

SIMPLETEST("Point op-") {
    Point p1;
    Point p2 = {XCoor{1.0}, YCoor{1.0}};

    if (!Math::equal(p1 - p1, 0.0)) return false;
    if (!Math::equal(p2 - p2, 0.0)) return false;
    if (!Math::equal(p1 - p2, std::sqrt(2.0))) return false;
    return true;
};

SIMPLETEST("Point op==") {
    Point p1;
    Point p2 = {XCoor{1.0}, YCoor{1.0}};

    if (p1 == p2) return false;
    if (!(p1 != p2)) return false;
    return true;
};

SIMPLETEST("Point op== 2") {
    Point p1;
    Point p2 = p1;

    if (!(p1 == p2)) return false;
    if (p1 != p2) return false;

    return true;
};

SIMPLETEST("Point ctor4") {
    Point p = {Radius{1.0}, Angle{0.0}};

    if (!Math::equal(p.getX(), 1.0)) return false;
    if (!Math::equal(p.getY(), 0.0)) return false;
    return true;
};

SIMPLETEST("Point ctor5") {
    Point p = {Radius{1.0}, Angle{Math::pi() / 2.0}};

    if (!Math::equal(p.getX(), 0.0)) return false;
    if (!Math::equal(p.getY(), 1.0)) return false;
    return true;
};

SIMPLETEST("Point area") {
    Point p;

    DRect r = p.svgArea();
    int d = 2 * p.svgRadius();
    if (r.area() != (d * d)) return false;
    return true;
};

SIMPLETEST("Point cctor") {
    Point p = {Radius{1.0}, Angle{Math::pi() / 2.0}};

    if (!Math::equal(p.getX(), 0.0)) return false;
    if (!Math::equal(p.getY(), 1.0)) return false;

    Point p2 = p;
    if (!Math::equal(p2.getX(), 0.0)) return false;
    if (!Math::equal(p2.getY(), 1.0)) return false;

    if (p2.getSNR() == p.getSNR()) return false;
    return true;
};

SIMPLETEST("Point assignment") {
    Point p1 = {Radius{1.0}, Angle{Math::pi() / 2.0}};
    Point p2;

    p1 = p2;

    if (p1.getColor() != p2.getColor()) return false;
    if (p1.getX() != p2.getX()) return false;
    if (p1.getY() != p2.getY()) return false;

    if (p1.getSNR() == p2.getSNR()) return false;

    return true;
};

SIMPLETEST("Point assignment2") {
    Point p1 = {Radius{1.0}, Angle{Math::pi() / 2.0}};
    Point p2;
    Point p3;

    p3 = p2 = p1;

    if (p1.getColor() != p3.getColor()) return false;
    if (p1.getX() != p3.getX()) return false;
    if (p1.getY() != p3.getY()) return false;

    if (p1.getSNR() == p3.getSNR()) return false;

    return true;
};

DRect::DRect(DPoint upperLeft, DPoint bottomRight) : mUpperLeft(upperLeft), mBottomRight(bottomRight)
{
}

int DRect::width() const
{
    int w = mBottomRight.mX - mUpperLeft.mX;
    assert(w >= 0);
    return w;
}

int DRect::height() const
{
    int h = mUpperLeft.mY - mBottomRight.mY;
    assert(h >= 0);
    return h;
}

int DRect::area() const
{
    return width() * height();
}

DRect::operator bool() const
{
    return area() != 0;
}

DPoint DRect::upperLeft() const
{
    return mUpperLeft;
}

DPoint DRect::bottomRight() const
{
    return mBottomRight;
}

DRect& DRect::operator+=(const DRect& rhs)
{
    if (rhs) {
        mUpperLeft.mX   = std::min(mUpperLeft.mX, rhs.mUpperLeft.mX);
        mBottomRight.mX = std::max(mBottomRight.mX, rhs.mBottomRight.mX);
        mBottomRight.mY = std::min(mBottomRight.mY, rhs.mBottomRight.mY);
        mUpperLeft.mY = std::max(mUpperLeft.mY, rhs.mUpperLeft.mY);
    }
    return *this;
}

DRect operator+(const DRect& a, const DRect& b)
{
    return DRect(a) += b;
}

SIMPLETEST("DG std-ctor") {
    DRect dr;
    if (dr) return false;
    return true;
};

SIMPLETEST("DG ctor1") {
    DRect dr{{0, 1}, {1, 0}};
    if (!dr) return false;
    if (dr.area() != 1) return false;
    return true;
};

SIMPLETEST("DG attr1") {
    DRect dr{{0, 2}, {2, 0}};
    if (!dr) return false;
    if (dr.height() != 2) return false;
    if (dr.width() != 2) return false;
    if (dr.area() != 4) return false;
    return true;
};

SIMPLETEST("DG op+=1") {
    DRect dr1{{0, 2}, {2, 0}};
    DRect dr2;
    
    dr1 += dr2;
    
    if (!dr1) return false;
    if (dr1.area() != 4) return false;
    
    return true;
};

SIMPLETEST("DG op+=2") {
    DRect dr1{{0, 2}, {2, 0}};
    DRect dr2{{1, 3}, {3, 1}};
    
    dr1 += dr2;
    
    if (!dr1) return false;
    if (dr1.area() != 9) return false;
    
    return true;
};
