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

//[friend -a
class Point
{
    friend std::ostream& operator<<(std::ostream& outputStream, const Point& p); // <> Die `friend`-Deklaration kann an beliebiger Stelle *in* der Klasse vorgenommen werden
    friend double operator-(const Point&, const Point&); // <> Als Alternative zur Funktion `distance` wird der Operator `-` überladen
public:
    //[a
    Point(double x = 0.0, double y = 0.0);
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

double distance(const Point&, const Point&);

std::ostream& operator<<(std::ostream& outputStream, const Point& p);
double operator-(const Point&, const Point&); // <> Deklaration des Operators `-`
//]
