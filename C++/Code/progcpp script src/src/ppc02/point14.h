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

#include <string>

//[PointColor -data -ctor -coor
//[Pointsetter -getter -data -ctor
//[Point -getter -data -setter
class Point
{
public:
    //[ctor
    Point(double x = 0.0, double y = 0.0);
    //]
    //[coor
    double getX() const;
    double getY() const;
    //]
    //[getter
    std::string getColor() const;
    //]
    //[coor
    void setX(double x);
    void setY(double y);
    void move(double dx, double dy);
    //]
    //[setter
    void setColor(std::string color);
    //]
private:
    //[data
    double mX{0.0};
    double mY{0.0};
    //]
    std::string mColor; // <> Standardkonstruktor -> _leerer_ String in `mColor`
};
//]
//]
//]
