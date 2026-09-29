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

#include "line00.h"

#include "math.h"

//[Line
Line::Line(const Point& point1, const Point& point2) :
    mPoint1{point1}, // <> Initialisierung der Endpunkte der Linie
    mPoint2{point2}
{
}
//]
std::string Line::toSVG() const
{
    std::string svgString = "<line ";
    svgString += "x1=\"" + std::to_string(Math::toInt(mPoint1.getX())) + "\" ";
    svgString += "y1=\"" + std::to_string(Math::toInt(mPoint1.getY())) + "\" ";
    svgString += "x2=\"" + std::to_string(Math::toInt(mPoint2.getX())) + "\" ";
    svgString += "y2=\"" + std::to_string(Math::toInt(mPoint2.getY())) + "\" ";
    svgString += "stroke-width=\"" + std::to_string(mSVGWidth) + "\" ";
    svgString += "stroke=\"" + mColor + "\" ";
    svgString +=  "/>";
    return svgString;
}
//[Line
DRect Line::svgArea() const
{
    return mPoint1.svgArea() + mPoint2.svgArea(); // <> Die umschreibende Rechteck der Linie kann durch die Vereinigung der Endpunktflächen erreicht werden.
}
//]
Line& Line::setColor(const std::string& color)
{
    mColor = color;
    return *this;
}

const std::string& Line::getColor() const
{
    return mColor;
}
