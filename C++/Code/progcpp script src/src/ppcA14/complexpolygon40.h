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


#include <vector>
#include <string>
#include <iosfwd>

#include "complexnumberA0.h"
#include "dgeometry.h"
#include "svgshape10.h"
#include "svgconvertible10.h"
#include "color10.h"

class ComplexPolygon final : public SVGShape, public SVGConvertible
{
    friend std::ostream& operator<<(std::ostream& out, const ComplexPolygon& polygon);
    friend ComplexPolygon& operator<<(ComplexPolygon& out, const ComplexNumber& point);
    friend bool operator==(const ComplexPolygon& lhs, const ComplexPolygon& rhs);
public:
    ComplexPolygon(const ComplexNumber& p1, const ComplexNumber& p2, const ComplexNumber& p3);
    ComplexPolygon(const ComplexPolygon& other);

    ComplexPolygon& operator=(const ComplexPolygon& rhs);

    void swap(ComplexPolygon& other);

    std::string toSVG() const override; // <> s.a. `SVGShape`
    DRect svgArea() const override; // <> s.a. `SVGShape`

    SVGElement svg() const override; // <> s.a. `SVGConvertible`

    size_t length() const;

    ComplexNumber& operator[](size_t index);
    const ComplexNumber& operator[](size_t index) const;

    const std::vector<ComplexNumber>& points() const;

    ComplexPolygon& operator+=(const ComplexPolygon& rhs);
    ComplexPolygon& operator+=(const ComplexNumber& rhs);

    const Color& fillColor() const;
    ComplexPolygon& fillColor(const Color& fillColor);

private:
    static int mSvgWidth;
    Color mFillColor = Color::PredefinedColor::Green;

    std::vector<ComplexNumber> mPoints;
};

std::ostream& operator<<(std::ostream& out, const ComplexPolygon& polygon);
ComplexPolygon& operator<<(ComplexPolygon& out, const ComplexNumber& point);
ComplexPolygon operator+(const ComplexPolygon& cp1, const ComplexPolygon& cp2);

bool operator==(const ComplexPolygon& lhs, const ComplexPolygon& rhs);
bool operator!=(const ComplexPolygon& lhs, const ComplexPolygon& rhs);
