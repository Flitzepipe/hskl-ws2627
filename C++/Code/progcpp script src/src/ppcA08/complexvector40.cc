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

#include "complexvector40.h"

#include "math.h"
#include "../lib/simpletest.h"
#include "objectserial.h"

#include <iostream>

SIMPLETEST("ctor") {
    ComplexVector cv{{},{}};
    if (cv.color() != "black") return false;
    return true;
};

SIMPLETEST("color") {
    ComplexVector cv{{},{}};

    if (cv.color() != "black") return false;

    cv.color("red");
    if (cv.color() != "red") return false;

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
    svg += R"(<line x1="0" y1="0" x2="0" y2="0" stroke="black" stroke-width="3" />)";

    if (cv.toSVG() != svg) return false;
    return true;
};

SIMPLETEST("serial") {
    ComplexNumber cn1;

    size_t serial = nextObjectSerial();
    ComplexVector cv{cn1, cn1};

    if (cv.serial() != serial) return false;
    return true;
};

//[serial
ComplexVector::ComplexVector(const ComplexNumber& begin, const ComplexNumber& end) :
    mSerial(createObjectSerial()), mBegin(begin), mEnd(end) // <> Initialisierung des Datenelements `mSerial` durch das Ergebnis der Funktion `createObjektSerial()`.
{
}

ComplexVector::ComplexVector(const ComplexVector& other) :
    mSerial(createObjectSerial()), mBegin(other.mBegin), mEnd(other.mEnd)
{
}

ComplexVector& ComplexVector::operator=(const ComplexVector& rhs)
{
    if (this != &rhs) { // <> Auch bei diesem _Kopierzuweisungsoperator_ können nur die `non-const`-Element zugewiesen werden.
        mBegin = rhs.mBegin;
        mEnd = rhs.mEnd;
        mColor = rhs.mColor;
    }
    return *this;
}
//]

std::string ComplexVector::toSVG() const
{
    std::string svgString = mBegin.toSVG() + "\n" + mEnd.toSVG();
    svgString += '\n';
    svgString += "<line ";
    svgString += "x1=\"" + std::to_string(Math::toInt(mBegin.real())) + "\" ";
    svgString += "y1=\"" + std::to_string(Math::toInt(mBegin.imag())) + "\" ";
    svgString += "x2=\"" + std::to_string(Math::toInt(mEnd.real())) + "\" ";
    svgString += "y2=\"" + std::to_string(Math::toInt(mEnd.imag())) + "\" ";
    svgString += "stroke=\"" + mColor + "\" ";
    svgString += "stroke-width=\"" + std::to_string(mSvgWidth) + "\" ";
    svgString +=  "/>";
    return svgString;
}

const std::string& ComplexVector::color() const
{
    return mColor;
}

void ComplexVector::color(const std::string& color)
{
    mColor = color;
}

const ComplexNumber& ComplexVector::begin() const
{
    return mBegin;
}

const ComplexNumber& ComplexVector::end() const
{
    return mEnd;
}

size_t ComplexVector::serial() const
{
    return mSerial;
}

