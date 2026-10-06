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

#include "complexnumberA0.h"
#include "../lib/simpletest.h"
#include "math.h"
#include "objectserial.h" // <> Diese _include_-Datei wird für die Seriennummernverwaltung benötigt.

#include <cmath>
#include <iostream>
#include <sstream>

extern bool trace;

SIMPLETEST("ctor1") {
    const ComplexNumber cn0;
    const ComplexNumber cn1;

    size_t nextSerial = nextObjectSerial(); // <> Verwendung der Programm-globalen freien Funktion `nextObjectSerial()`
    const ComplexNumber cn;

    if (!Math::equal(cn.real(), 0.0)) return false;
    if (!Math::equal(cn.imag(), 0.0)) return false;
    if (cn.serial() != nextSerial) return false;

    return true;
};

SIMPLETEST("ctor2") {
    size_t nextSerial = nextObjectSerial();
    const ComplexNumber cn{1.0, 1.1};

    if (!Math::equal(cn.real(), 1.0)) return false;
    if (!Math::equal(cn.imag(), 1.1)) return false;
    if (cn.serial() != nextSerial) return false;
    return true;
};

SIMPLETEST("ctor3") {
    const ComplexNumber cn{2.0};

    if (!Math::equal(cn.real(), 2.0)) return false;
    if (!Math::equal(cn.imag(), 0.0)) return false;
    return true;
};

SIMPLETEST("ctor conversion") {
    const ComplexNumber cn = 2.0;

    if (!Math::equal(cn.real(), 2.0)) return false;
    if (!Math::equal(cn.imag(), 0.0)) return false;
    return true;
};

SIMPLETEST("predicate") {
    const ComplexNumber cn;

    if (!cn.isReal()) return false;
    if (!cn.isImag()) return false;
    return true;
};

SIMPLETEST("setter") {
    ComplexNumber cn;

    cn.real(1.0);
    if (!Math::equal(cn.real(), 1.0)) return false;
    if (!Math::equal(cn.imag(), 0.0)) return false;
    cn.imag(1.0);
    if (!Math::equal(cn.real(), 1.0)) return false;
    if (!Math::equal(cn.imag(), 1.0)) return false;
    return true;
};

SIMPLETEST("add1") {
    ComplexNumber cn1{1.0, 0.0};
    ComplexNumber cn2{0.0, 1.0};

    cn1.add(cn2);

    if (!Math::equal(cn1.real(), 1.0)) return false;
    if (!Math::equal(cn1.imag(), 1.0)) return false;
    return true;
};

SIMPLETEST("op+=") {
    ComplexNumber cn1{1.0, 0.0};
    ComplexNumber cn2{0.0, 1.0};

    cn1 += cn2;

    if (!Math::equal(cn1.real(), 1.0)) return false;
    if (!Math::equal(cn1.imag(), 1.0)) return false;
    return true;
};

SIMPLETEST("op-=") {
    ComplexNumber cn1{1.0, 0.0};
    ComplexNumber cn2{0.0, 1.0};

    cn1 -= cn2;

    if (!Math::equal(cn1.real(), 1.0)) return false;
    if (!Math::equal(cn1.imag(), -1.0)) return false;
    return true;
};

SIMPLETEST("op*=") {
    ComplexNumber cn1{1.0, 0.0};
    ComplexNumber cn2{2.0, 0.0};

    cn1 *= cn2;

    if (!Math::equal(cn1.real(), 2.0)) return false;
    if (!Math::equal(cn1.imag(), 0.0)) return false;
    return true;
};

SIMPLETEST("op/=") {
    ComplexNumber cn1{1.0, 1.0};
    ComplexNumber cn2{2.0, 0.0};

    cn1 /= cn2;

    if (!Math::equal(cn1.real(), 0.5)) return false;
    if (!Math::equal(cn1.imag(), 0.5)) return false;
    return true;
};

#ifdef _MSC_VER //-
#  pragma warning(push) //-
#  pragma warning(disable: 4573) //-
#endif //-

SIMPLETEST("add2") {
    const ComplexNumber cn1{1.0, 0.0};
    const ComplexNumber cn2{0.0, 1.0};

    ComplexNumber cn3 = ComplexNumber::add(cn2, cn1);

    if (!Math::equal(cn3.real(), 1.0)) return false;
    if (!Math::equal(cn3.imag(), 1.0)) return false;
    return true;
};

#ifdef _MSC_VER //-
#  pragma warning(pop) //-
#endif //-

SIMPLETEST("op+") {
    const ComplexNumber cn1{1.0, 0.0};
    const ComplexNumber cn2{0.0, 1.0};

    ComplexNumber cn3 = cn2 + cn1;

    if (!Math::equal(cn3.real(), 1.0)) return false;
    if (!Math::equal(cn3.imag(), 1.0)) return false;
    return true;
};

SIMPLETEST("op-") {
    const ComplexNumber cn1{1.0, 0.0};
    const ComplexNumber cn2{0.0, 1.0};

    ComplexNumber cn3 = cn1 - cn2;

    if (!Math::equal(cn3.real(), 1.0)) return false;
    if (!Math::equal(cn3.imag(), -1.0)) return false;
    return true;
};

SIMPLETEST("op*") {
    const ComplexNumber cn1{1.0, 0.0};
    const ComplexNumber cn2{0.0, 1.0};

    ComplexNumber cn3 = cn1 * cn2;

    if (!Math::equal(cn3.real(), 0.0)) return false;
    if (!Math::equal(cn3.imag(), 1.0)) return false;
    return true;
};

SIMPLETEST("op/") {
    const ComplexNumber cn1{2.0, 0.0};
    const ComplexNumber cn2{1.0, 1.0};

    ComplexNumber cn3 = cn1 / cn2;

    if (!Math::equal(cn3.real(), 1.0)) return false;
    if (!Math::equal(cn3.imag(), -1.0)) return false;
    return true;
};

SIMPLETEST("unary op+") {
    const ComplexNumber cn1{2.0, 2.0};

    ComplexNumber cn3 = +cn1;

    if (!Math::equal(cn3.real(), 2.0)) return false;
    if (!Math::equal(cn3.imag(), 2.0)) return false;
    return true;
};

SIMPLETEST("unary op-") {
    const ComplexNumber cn1{2.0, 2.0};

    ComplexNumber cn3 = -cn1;

    if (!Math::equal(cn3.real(), -2.0)) return false;
    if (!Math::equal(cn3.imag(), -2.0)) return false;
    return true;
};

SIMPLETEST("norm") {
    const ComplexNumber cn1{2.0, 2.0};

    if (!Math::equal(cn1.norm(), 8.0)) return false;
    return true;
};

SIMPLETEST("conjugate") {
    const ComplexNumber cn1{1.0, 2.0};
    const ComplexNumber cn2{1.0, -2.0};

    if (cn1.conjugate() != cn2) return false;
    return true;
};

SIMPLETEST("setter2") {
    ComplexNumber cn;

    cn.real(1.0);
    if (cn.name() != "") return false;
    if (!Math::equal(cn.real(), 1.0)) return false;
    if (!Math::equal(cn.imag(), 0.0)) return false;
    cn.imag(1.0);
    if (cn.name() != "") return false;
    if (!Math::equal(cn.real(), 1.0)) return false;
    if (!Math::equal(cn.imag(), 1.0)) return false;
    cn.name("abc");
    if (cn.name() != "abc") return false;

    return true;
};

SIMPLETEST("toString1") {
    ComplexNumber cn;

    std::string refString = "CN[" + std::to_string(cn.serial()) + ",0.000000,0.000000]";

    if (cn.toString() != refString) return false;
    return true;
};

SIMPLETEST("toString2") {
    ComplexNumber cn{1};
    cn.name("abc");

    std::string refString = "CN[" + std::to_string(cn.serial()) + ",1.000000,0.000000,abc]";

    if (cn.toString() != refString) return false;
    return true;
};

SIMPLETEST("color") {
    ComplexNumber cn;
    cn.svgColor(Color::PredefinedColor::Red);

    if (cn.svgColor() != Color::PredefinedColor::Red) return false;
    return true;
};

SIMPLETEST("toSVG") {
    ComplexNumber cn{1.1, 2.1};
    cn.svgColor(Color::PredefinedColor::Red);

    std::string svg = R"d(<circle cx="1" cy="2" r="3" stroke="rgb(255,0,0)" fill="rgb(255,0,0)" />)d";

    if (cn.toSVG() != svg) return false;
    return true;
};

SIMPLETEST("op<<") {
    std::stringstream ss;

    ComplexNumber cn{1.1, 2.1};
    cn.svgColor(Color::PredefinedColor::Red);

    ss << cn;

    if (ss.str() != cn.toString()) return false;

    return true;
};

SIMPLETEST("op==") {
    ComplexNumber cn1{1.0, 0.0};
    ComplexNumber cn2 = cn1;

    if (!(cn1 == cn2)) return false;

    return true;
};

SIMPLETEST("op!=") {
    ComplexNumber cn1{1.0, 0.0};
    ComplexNumber cn2;

    if (!(cn1 != cn2)) return false;

    return true;
};

SIMPLETEST("op=") {
    ComplexNumber cn1{1.1, 2.2};
    ComplexNumber cn2;

    cn1 = cn2;

    if (cn1 != cn2) return false;

    return true;
};

SIMPLETEST("serial") {
    size_t serial = nextObjectSerial();
    ComplexNumber cn1;

    if (cn1.serial() != serial) return false;

    return true;
};

int ComplexNumber::mSVGRadius = 3;

ComplexNumber::ComplexNumber(double real, double imag) :
    mReal(real), mImag(imag)
{
    if (trace) std::cout << __PRETTY_FUNCTION__ << std::endl;
}

ComplexNumber::ComplexNumber(const ComplexNumber& other) :
    ComplexNumber(other.mReal, other.mImag)
{
    if (trace) std::cout << __PRETTY_FUNCTION__ << std::endl;
}

ComplexNumber::~ComplexNumber()
{
    if (trace) std::cout << __PRETTY_FUNCTION__ << std::endl;
}

ComplexNumber& ComplexNumber::operator=(const ComplexNumber& rhs)
{
    ComplexNumber copy(rhs);
    swap(copy);
    return *this;
}

void ComplexNumber::swap(ComplexNumber& other)
{
    using std::swap;
    SVGShape::swap(other); // <> Auch der Basisklassenanteil muss vertauscht werden.
    swap(mReal, other.mReal);
    swap(mImag, other.mImag);
    swap(mName, other.mName);
}

double ComplexNumber::real() const
{
    return mReal;
}

double ComplexNumber::imag() const
{
    return mImag;
}

const std::string& ComplexNumber::name() const
{
    return mName;
}

std::string ComplexNumber::toString() const
{
    if (mName.empty()) {
        return "CN[" + std::to_string(mSerial) + "," + std::to_string(mReal) + "," + std::to_string(mImag) + "]";
    }
    return "CN[" + std::to_string(mSerial) + "," + std::to_string(mReal) + "," + std::to_string(mImag) + "," + mName + "]";
}

std::string ComplexNumber::toSVG() const
{
    std::string svgString = "<circle ";
    svgString += "cx=\"" + std::to_string(Math::toInt(mReal)) + "\" ";
    svgString += "cy=\"" + std::to_string(Math::toInt(mImag)) + "\" ";
    svgString += "r=\"" + std::to_string(mSVGRadius) + "\" ";
    svgString += "stroke=\"" + mSVGColor.rgbString() + "\" ";
    svgString += "fill=\"" + mSVGColor.rgbString() + "\" ";
    svgString +=  "/>";
    return svgString;
}

DRect ComplexNumber::svgArea() const
{
    return DRect{
        DPoint{Math::toInt(mReal) - mSVGRadius, Math::toInt(mImag) + mSVGRadius},
        DPoint{Math::toInt(mReal) + mSVGRadius, Math::toInt(mImag) - mSVGRadius}
    };
}

//[svg
SVGElement ComplexNumber::svg() const
{
    SVGElement svgElement{"circle"};
    svgElement.area(svgArea());

    svgElement += SVGAttribute{"cx", mReal};
    svgElement += SVGAttribute{"cy", mImag};
    svgElement += SVGAttribute{"r", mSVGRadius};
    svgElement += SVGAttribute{"stroke", mSVGColor};
    svgElement += SVGAttribute{"fill", mSVGColor};

    return svgElement;
}
//]

ComplexNumber& ComplexNumber::real(double value)
{
    mReal = value;
    return *this;
}

ComplexNumber& ComplexNumber::imag(double value)
{
    mImag = value;
    return *this;
}

ComplexNumber& ComplexNumber::name(const std::string& name) // <> Wie oben!
{
    mName = name;
    return *this;
}

bool ComplexNumber::isReal() const
{
    return Math::equal(mImag, 0.0);
}

bool ComplexNumber::isImag() const
{
    return Math::equal(mReal, 0.0);
}

void ComplexNumber::add(const ComplexNumber& c)
{
    mReal += c.mReal;
    mImag += c.mImag;
}

ComplexNumber ComplexNumber::add(const ComplexNumber& c1, const ComplexNumber& c2)
{
    ComplexNumber sum = c1;
    sum.add(c2);
    return sum;
}

ComplexNumber& ComplexNumber::operator+=(const ComplexNumber& other)
{
    mReal += other.mReal;
    mImag += other.mImag;

    return *this;
}

ComplexNumber& ComplexNumber::operator-=(const ComplexNumber& other)
{
    mReal -= other.mReal;
    mImag -= other.mImag;

    return *this;
}

ComplexNumber& ComplexNumber::operator*=(const ComplexNumber& other)
{
    double real = mReal * other.mReal - mImag * other.mImag;
    double imag = mImag * other.mReal + mReal * other.mImag;
    mReal = real;
    mImag = imag;
    return *this;
}

ComplexNumber& ComplexNumber::operator/=(const ComplexNumber& other)
{
    *this *= other.conjugate();
    double norm = other.norm();
    mReal /= norm;
    mImag /= norm;
    return *this;
}

double ComplexNumber::norm() const
{
    return mReal * mReal + mImag * mImag;
}

ComplexNumber ComplexNumber::conjugate() const
{
    return ComplexNumber{mReal, -mImag};
}

const ComplexNumber& ComplexNumber::operator+() const
{
    return *this;
}

ComplexNumber ComplexNumber::operator-() const
{
    return ComplexNumber{-mReal, -mImag};
}

std::ostream& operator<<(std::ostream& out, const ComplexNumber& cn)
{
    return out << cn.toString();
}

ComplexNumber operator+(const ComplexNumber& c1, const ComplexNumber& c2)
{
    ComplexNumber sum = c1;
    sum += c2;
    return sum;
}

bool operator==(const ComplexNumber& c1, const ComplexNumber& c2)
{
    return Math::equal(c1.mReal, c2.mReal) && Math::equal(c1.mImag, c2.mImag);
}

bool operator!=(const ComplexNumber& c1, const ComplexNumber& c2)
{
    return !(c1 == c2);
}


ComplexNumber operator-(const ComplexNumber& c1, const ComplexNumber& c2)
{
    ComplexNumber diff = c1;
    diff -= c2;
    return diff;
}


ComplexNumber operator*(const ComplexNumber& c1, const ComplexNumber& c2)
{
    ComplexNumber prod = c1;
    prod *= c2;
    return prod;
}


ComplexNumber operator/(const ComplexNumber& c1, const ComplexNumber& c2)
{
    ComplexNumber quot = c1;
    quot /= c2;
    return quot;
}
