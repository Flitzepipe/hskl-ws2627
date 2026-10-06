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

#include "point40.h"

#include "../lib/simpletest.h"
#include "math.h"

#include <cassert>

Point::Point(const double x, const double y) : mX{x}, mY{y}
{
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
    return svgString; // <> Ergebnisrückgabe als Wertkopie *notwendig*
}

int Point::svgRadius()
{
    return mSVGRadius;
}

void Point::setX(const double x)
{
    mX = x;
}

void Point::setY(const double y)
{
    mY = y;
}

void Point::move(const double dx, const double dy)
{
    mX += dx;
    mY += dy;
}

void Point::setColor(const std::string& color)
{
    mColor = color;
}

void Point::setColor(unsigned char r, unsigned char g, unsigned char b)
{
    mColor = "rgb(" + std::to_string(r) + "," + std::to_string(g) + "," + std::to_string(b) + ")";
}

SIMPLETEST("Point ctor1") {
    Point p;

    if (!Math::equal(p.getX(), 0.0)) return false;
    if (!Math::equal(p.getY(), 0.0)) return false;

    return true;
};

SIMPLETEST("Point ctor2") {
    Point p{1.0, 2.0};

    if (!Math::equal(p.getX(), 1.0)) return false;
    if (!Math::equal(p.getY(), 2.0)) return false;

    return true;
};

SIMPLETEST("Point ctor3") {
    Point p{1.0};

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
    Point p = {1.1, 2.9};
    p.setColor("red");
    if (p.toSVG() != "<circle cx=\"1\" cy=\"3\" r=\"10\" stroke=\"red\" fill=\"red\" />") return false;
    return true;
};
