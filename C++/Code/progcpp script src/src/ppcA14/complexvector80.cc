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

#include "complexvector80.h"

#include "math.h"
#include "../lib/simpletest.h"
#include "objectserial.h"

#include <iostream>
#include <sstream>

SIMPLETEST("ctor") {
    ComplexVector cv{{},{}};
    if (cv.svgColor() != Color::PredefinedColor::Black) return false;
    return true;
};

SIMPLETEST("color") {
    ComplexVector cv{{},{}};

    if (cv.svgColor() != Color::PredefinedColor::Black) return false;

    cv.svgColor(Color::PredefinedColor::Red);
    if (cv.svgColor() != Color::PredefinedColor::Red) return false;

    return true;
};

SIMPLETEST("begin end") {
    ComplexVector cv{{1, 2}, {3, 4}};

    if (!Math::equal(cv.begin().real(),1.0)) return false;
    if (!Math::equal(cv.begin().imag(),2.0)) return false;
    if (!Math::equal(cv.end().real(),3.0)) return false;
    if (!Math::equal(cv.end().imag(),4.0)) return false;

    return true;
};

SIMPLETEST("toSVG") {
    ComplexVector cv{{},{}};

    std::string svg = cv.begin().toSVG();
    svg += '\n';
    svg += cv.end().toSVG();
    svg += '\n';
    svg += R"D(<line x1="0" y1="0" x2="0" y2="0" stroke="rgb(0,0,0)" stroke-width="3" />)D";

    if (cv.toSVG() != svg) return false;
    return true;
};

SIMPLETEST("svg") {
    ComplexVector cv{{},{}};

    std::string cvSvg = cv.svg();

    std::string svg = "<g>";
    svg += cv.begin().svg();
    svg += cv.end().svg();
    svg += R"D(<line x1="0" y1="0" x2="0" y2="0" stroke="rgb(0,0,0)" stroke-width="3"></line></g>)D";

    if (cvSvg != svg) return false;
    return true;
};

SIMPLETEST("serial") {
    ComplexNumber cn1;

    size_t serial = nextObjectSerial();
    ComplexVector cv{cn1, cn1};

    if (cv.serial() != serial) return false;
    return true;
};

SIMPLETEST("op<<") {
    std::stringstream ss;

    ComplexVector cv{{1.0, 1.0}, {2.0, 2.0}};

    std::string refString = "CV[" + std::to_string(cv.serial()) + ", ";
    refString += cv.begin().toString() + ", ";
    refString += cv.end().toString() + "]";

    ss << cv;

    if (ss.str() != refString) return false;

    return true;
};

SIMPLETEST("op=") {
    ComplexNumber cn1{1.0, 1.0};
    ComplexNumber cn2{2.0, 2.0};

    ComplexVector cv1{cn1, cn2};
    ComplexVector cv2{{},{}};

    cv2 = cv1;

    if (cv1 != cv2) return false;

    return true;
};

SIMPLETEST("op==") {
    ComplexNumber cn1{1.0, 1.0};
    ComplexNumber cn2{2.0, 2.0};

    ComplexVector cv1{cn1, cn2};
    ComplexVector cv2{cn1, cn2};

    if (!(cv1 == cv2)) return false;

    return true;
};

SIMPLETEST("op!=") {
    ComplexNumber cn1{1.0, 1.0};
    ComplexNumber cn2{2.0, 2.0};

    ComplexVector cv1{cn1, cn2};
    ComplexVector cv2{cn1, cn2};

    if (cv1 != cv2) return false;

    return true;
};

int ComplexVector::mSvgWidth = 3;

ComplexVector::ComplexVector(const ComplexNumber& begin, const ComplexNumber& end) :
    mBegin(begin), mEnd(end)
{
    if (trace) std::cout << __PRETTY_FUNCTION__ << std::endl;
}

ComplexVector::ComplexVector(const ComplexVector& other) :
    mBegin(other.mBegin), mEnd(other.mEnd)
{
    if (trace) std::cout << __PRETTY_FUNCTION__ << std::endl;
}

ComplexVector& ComplexVector::operator=(const ComplexVector& rhs)
{
    if (this != &rhs) {
        mBegin = rhs.mBegin;
        mEnd = rhs.mEnd;
    }
    return *this;
}

std::string ComplexVector::toSVG() const
{
    std::string svgString = mBegin.toSVG() + "\n" + mEnd.toSVG();
    svgString += '\n';
    svgString += "<line ";
    svgString += "x1=\"" + std::to_string(Math::toInt(mBegin.real())) + "\" ";
    svgString += "y1=\"" + std::to_string(Math::toInt(mBegin.imag())) + "\" ";
    svgString += "x2=\"" + std::to_string(Math::toInt(mEnd.real())) + "\" ";
    svgString += "y2=\"" + std::to_string(Math::toInt(mEnd.imag())) + "\" ";
    svgString += "stroke=\"";
    svgString += mSVGColor;
    svgString += "\" ";
    svgString += "stroke-width=\"" + std::to_string(mSvgWidth) + "\" ";
    svgString +=  "/>";
    return svgString;
}
DRect ComplexVector::svgArea() const
{
    return mBegin.svgArea() + mEnd.svgArea();
}

SVGElement ComplexVector::svg() const
{
    SVGElement svg{"g"};

    svg += mBegin.svg();
    svg += mEnd.svg();

    SVGElement svgLine{"line"};
    svgLine += SVGAttribute{"x1", Math::toInt(mBegin.real())};
    svgLine += SVGAttribute{"y1", Math::toInt(mBegin.imag())};
    svgLine += SVGAttribute{"x2", Math::toInt(mEnd.real())};
    svgLine += SVGAttribute{"y2", Math::toInt(mEnd.imag())};
    svgLine += SVGAttribute{"stroke", mSVGColor};
    svgLine += SVGAttribute{"stroke-width", mSvgWidth};

    svg += svgLine;
    return svg;
}

const ComplexNumber& ComplexVector::begin() const
{
    return mBegin;
}

const ComplexNumber& ComplexVector::end() const
{
    return mEnd;
}

std::ostream& operator<<(std::ostream& out, const ComplexVector& cv)
{
    return out << "CV[" << cv.mSerial << ", " << cv.mBegin << ", " << cv.mEnd << "]";
}


bool operator==(const ComplexVector& lhs, const ComplexVector& rhs)
{
    return (lhs.mBegin == rhs.mBegin) && (lhs.mEnd == rhs.mEnd);
}


bool operator!=(const ComplexVector& lhs, const ComplexVector& rhs)
{
    return !(lhs == rhs);
}
