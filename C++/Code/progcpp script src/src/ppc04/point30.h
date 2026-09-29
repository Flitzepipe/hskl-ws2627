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

#include "../ppc.h"

#include <string>

//[getter -b
//[Point -a
class Point
{
public:
    //[a
    //[b
    Point(double x = 0.0, double y = 0.0);
    //]
    double getX() const; // <> Observator ist *const*, primitive Typen werden _per-value_ zurückgegeben
    double getY() const;
    const std::string& getColor() const; // <> Ergebnis dieses _Observators_ ist eine `const`-Referenz auf das Datenelement `mColor`
    std::string toSVG() const; // <> Ergebnisrückgabe als Kopie
    static int svgRadius(); // <> statische Elementfunktionen können nicht `const`-qualifiziert werden, denn sie haben keinen Zugriff auf einen _Objektzustand_
    //[b
    void setX(double x);
    void setY(double y);
    //]
    //]
    //[b
    void setColor(const std::string& color);
    void setColor(unsigned char r, unsigned char g, unsigned char b);
    //[a
    void move(double dx, double dy);
private:
    double mX{0.0};
    double mY{0.0};
    std::string mColor{"black"};
    inline static int mSVGRadius{10};
    //]
    //]
};
//]
//]
