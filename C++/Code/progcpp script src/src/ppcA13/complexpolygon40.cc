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

#include "complexpolygon40.h"
#include "trace10.h"
#include "math.h"
#include "pair.h"
#include "objectserial.h"
#include "../lib/simpletest.h"

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

    std::string refString = R"d(<polygon points="0,0 10,0 10,10" stroke="rgb(0,0,0)" fill="rgb(0,255,0)" stroke-width="3" />)d";

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

SIMPLETEST("cctor") {
    ComplexNumber cn1{0, 0};
    ComplexNumber cn2{10, 0};
    ComplexNumber cn3{10, 10};
    ComplexPolygon cp1{cn1, cn2, cn3};

    ComplexPolygon cp2 = cp1;

    if (cp1.serial() == cp2.serial()) return false;
    if (cp1 != cp2) return false;

    return true;
};

SIMPLETEST("op==") {
    ComplexNumber cn1{0, 0};
    ComplexNumber cn2{10, 0};
    ComplexNumber cn3{10, 10};
    ComplexPolygon cp1{cn1, cn2, cn3};
    ComplexPolygon cp2{cn1, cn2, cn3};

    if (cp1 != cp2) return false;
    if (!(cp1 == cp2)) return false;

    return true;
};

SIMPLETEST("op=") {
    ComplexNumber cn1{0, 0};
    ComplexNumber cn2{10, 0};
    ComplexNumber cn3{10, 10};
    ComplexNumber cn4{20, 20};
    ComplexPolygon cp1{cn1, cn2, cn3};
    ComplexPolygon cp2{cn4, cn2, cn3};

    cp2 = cp1;

    if (cp2 != cp1) return false;

    return true;
};

int ComplexPolygon::mSvgWidth = 3;

ComplexPolygon::ComplexPolygon(const ComplexNumber& p1, const ComplexNumber& p2, const ComplexNumber& p3) :
    mPoints{p1, p2, p3}
{
    if (trace) std::cout << __PRETTY_FUNCTION__ << std::endl;
}

ComplexPolygon::ComplexPolygon(const ComplexPolygon& other) :
    ComplexPolygon{(assert(other.length() >= 3), other.mPoints[0]),
    other.mPoints[1], other.mPoints[2]}
{
    if (trace) std::cout << __PRETTY_FUNCTION__ << std::endl;
    if (other.length() > 3) {
        for(size_t i = 3; i < other.length(); ++i) {
            mPoints.push_back(other[i]);
        }
    }
}

ComplexPolygon& ComplexPolygon::operator=(const ComplexPolygon& rhs)
{
    ComplexPolygon copy(rhs);
    swap(copy);
    return *this;
}

void ComplexPolygon::swap(ComplexPolygon& other)
{
    using std::swap;
    SVGShape::swap(other); // <> Auch der Basisklassenanteil muss vertauscht werden.
    swap(mFillColor, other.mFillColor);
    swap(mPoints, other.mPoints);
}

std::string ComplexPolygon::toSVG() const
{
    std::string svgString = R"(<polygon points=")";
    for(const ComplexNumber& cn: mPoints) {
        if (&cn != &mPoints[0]) {
            svgString += ' ';
        }
        svgString += Pair{cn.real(), cn.imag()}.asInt();
    }
    svgString += R"(" )";
    svgString += "stroke=\"" + mSVGColor.rgbString() + "\" ";
    svgString += "fill=\"" + mFillColor.rgbString() + "\" ";
    svgString += "stroke-width=\"" + std::to_string(mSvgWidth) + "\" ";

    return svgString += "/>";
}

DRect ComplexPolygon::svgArea() const
{
    DRect area = mPoints[0].svgArea();
    for(size_t i = 1; i < mPoints.size(); ++i) {
        area += mPoints[i].svgArea();
    }
    return area;
}

SVGElement ComplexPolygon::svg() const
{
    SVGElement svgElement{"polygon"};
    svgElement.area(svgArea());

    std::string pointsString;
    for(const ComplexNumber& cn: mPoints) {
        if (&cn != &mPoints[0]) { // <> falls nicht das erste Element, dann wird das Trennzeichen eingefügt
            pointsString += ' ';
        }
        pointsString += Pair{cn.real(), cn.imag()}.asInt(); // <> Ein Object des DT `Pair` wird erzeugt und durch den Typumwandlungsoperator in den DT `std::string` umgewandelt.
    }
    svgElement += SVGAttribute{"points", pointsString};

    svgElement += SVGAttribute{"stroke", mSVGColor};
    svgElement += SVGAttribute{"fill", mFillColor};
    svgElement += SVGAttribute{"stroke-width", mSvgWidth};

    return svgElement;
}

size_t ComplexPolygon::length() const
{
    return mPoints.size();
}

ComplexNumber& ComplexPolygon::operator[](const size_t index)
{
    return mPoints[index];
}

const ComplexNumber& ComplexPolygon::operator[](const size_t index) const
{
    return mPoints[index];
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

const Color& ComplexPolygon::fillColor() const
{
    return mFillColor;
}

ComplexPolygon& ComplexPolygon::fillColor(const Color& fillColor)
{
    mFillColor = fillColor;
    return *this;
}

std::ostream& operator<<(std::ostream& out, const ComplexPolygon& polygon)
{
    out << "CP[";
    for(const ComplexNumber& cn: polygon.mPoints) {
        if (&cn != &polygon.mPoints[0]) { // <> falls nicht das erste Element, dann wird die Trennzeichenfolge eingefügt
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

bool operator==(const ComplexPolygon& lhs, const ComplexPolygon& rhs)
{
    if (lhs.length() != rhs.length()) return false;

    for(size_t i = 0; i < lhs.length(); ++i) {
        if (lhs[i] != rhs[i]) {
            return false;
        }
    }
    return true;
}

bool operator!=(const ComplexPolygon& lhs, const ComplexPolygon& rhs)
{
    return !(lhs == rhs);
}
