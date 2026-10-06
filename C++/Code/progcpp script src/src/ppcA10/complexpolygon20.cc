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

//[CP -tests
#include "complexpolygon20.h"
#include "trace10.h"
#include "math.h"
#include "../lib/simpletest.h"

//[tests
#include <sstream>

SIMPLETEST("ctor") {
    ComplexNumber cn1{0, 0};
    ComplexNumber cn2{10, 0};
    ComplexNumber cn3{10, 10};
    ComplexPolygon cp{cn1, cn2, cn3};

    if (cp.length() != 3) return false;

    return true;
};

SIMPLETEST("toSVG") {
    ComplexNumber cn1{0, 0};
    ComplexNumber cn2{10, 0};
    ComplexNumber cn3{10, 10};
    ComplexPolygon cp{cn1, cn2, cn3};

    std::string refString = "<polygon points=\"0,0 10,0 10,10 \"/>";

    if (cp.toSVG() != refString) return false;

    return true;
};

SIMPLETEST("op+= 1") {
    ComplexNumber cn1{0, 0};
    ComplexNumber cn2{10, 0};
    ComplexNumber cn3{10, 10};
    ComplexPolygon cp{cn1, cn2, cn3};

    ComplexNumber cn4{0, 10};
    cp += cn4;

    if (cp.length() != 4) return false;

    return true;
};

SIMPLETEST("op<< 1") {
    ComplexNumber cn1{0, 0};
    ComplexNumber cn2{10, 0};
    ComplexNumber cn3{10, 10};
    ComplexPolygon cp{cn1, cn2, cn3};

    ComplexNumber cn4{0, 10};
    cp << cn4;

    if (cp.length() != 4) return false;

    return true;
};

SIMPLETEST("op+= 2") {
    ComplexNumber cn1{0, 0};
    ComplexNumber cn2{10, 0};
    ComplexNumber cn3{10, 10};
    ComplexPolygon cp1{cn1, cn2, cn3};

    ComplexPolygon cp2 = cp1;

    cp1 += cp2;

    if (cp1.length() != 6) return false;

    return true;
};

SIMPLETEST("op+") {
    ComplexNumber cn1{0, 0};
    ComplexNumber cn2{10, 0};
    ComplexNumber cn3{10, 10};
    ComplexPolygon cp1{cn1, cn2, cn3};

    ComplexPolygon cp2 = cp1 + cp1;

    if (cp2.length() != 6) return false;

    return true;
};

SIMPLETEST("op<<") {
    ComplexNumber cn1{0, 0};
    ComplexNumber cn2{10, 0};
    ComplexNumber cn3{10, 10};
    ComplexPolygon cp1{cn1, cn2, cn3};

    std::stringstream ss;

    ss << cp1;

    std::string refString = "CP[";
    for(const ComplexNumber& cn: cp1.points()) {
        if (&cn != &cp1.points()[0]) {
            refString += ", ";
        }
        std::stringstream lss;
        lss << cn;
        refString += lss.str();
    }
    refString += "]";

    if (refString != ss.str()) return false;

    return true;
};
//]

ComplexPolygon::ComplexPolygon(const ComplexNumber& p1, const ComplexNumber& p2, const ComplexNumber& p3) :
    mPoints{p1, p2, p3}
{
    if (trace) std::cout << __PRETTY_FUNCTION__ << std::endl;
}

std::string ComplexPolygon::toSVG() const
{
    std::string svgString;
    svgString += "<polygon points=\"";
    for(const ComplexNumber& cn: mPoints) {
        svgString += std::to_string(Math::toInt(cn.real())) + "," + std::to_string(Math::toInt(cn.imag())) + " ";
    }
    svgString += "\"";
    svgString +=  "/>";

    return svgString;
}

size_t ComplexPolygon::length() const
{
    return mPoints.size();
}

const std::vector<ComplexNumber>& ComplexPolygon::points() const
{
    return mPoints;
}

ComplexPolygon& ComplexPolygon::operator+=(const ComplexPolygon& rhs)
{
    for(const ComplexNumber& cn: rhs.mPoints) {
        mPoints.push_back(cn);
    }
    return *this;
}

ComplexPolygon& ComplexPolygon::operator+=(const ComplexNumber& rhs)
{
    mPoints.push_back(rhs);
    return *this;
}

std::ostream& operator<<(std::ostream& out, const ComplexPolygon& polygon)
{
    out << "CP[";
    for(const ComplexNumber& cn: polygon.mPoints) {
        if (&cn != &polygon.mPoints[0]) {
            out << ", ";
        }
        out << cn;
    }
    out << "]";
    return out;
}

ComplexPolygon& operator<<(ComplexPolygon& out, const ComplexNumber& point)
{
    out.mPoints.push_back(point);
    return out;
}

ComplexPolygon operator+(const ComplexPolygon& cp1, const ComplexPolygon& cp2)
{
    return ComplexPolygon{cp1} += cp2;
}
//]
