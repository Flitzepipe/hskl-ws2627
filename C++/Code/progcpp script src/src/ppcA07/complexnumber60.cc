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

#include "complexnumber60.h"
#include "../lib/simpletest.h"
#include "math.h"
#include <cmath>
#include <iostream>
#include <sstream>

//[trace
extern const bool trace; // <> Deklaration der Programm-globalen Variable `trace`.
//]

SIMPLETEST("ctor1") {
    const ComplexNumber cn;

    if (!Math::equal(cn.real(), 0.0)) return false;
    if (!Math::equal(cn.imag(), 0.0)) return false;
    return true;
};

SIMPLETEST("ctor2") {
    const ComplexNumber cn{1.0, 1.1};

    if (!Math::equal(cn.real(), 1.0)) return false;
    if (!Math::equal(cn.imag(), 1.1)) return false;
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

    if (cn.toString() != "CN[0.000000,0.000000]") return false;
    return true;
};

SIMPLETEST("toString2") {
    ComplexNumber cn{1};

    cn.name("abc");
    if (cn.toString() != "CN[1.000000,0.000000,abc]") return false;
    return true;
};

SIMPLETEST("color") {
    ComplexNumber cn;
    cn.color("red");
    if (cn.color() != "red") return false;
    return true;
};

SIMPLETEST("toSVG") {
    ComplexNumber cn{1.1, 2.1};
    cn.color("red");

    std::string svg = R"(<circle cx="1" cy="2" r="3" stroke="red" fill="red" />)"; // <> _Rohe_ C-Strings machen den Umgang mit Meta-Zeichen wie `"` einfacher

    if (cn.toSVG() != svg) return false;
    return true;
};

SIMPLETEST("op<<") {
    std::stringstream ss;

    ComplexNumber cn{1.1, 2.1};
    cn.color("red");

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

SIMPLETEST("cctor") {
    ComplexNumber cn1{1.0, 0.0};
    cn1.color("red");
    cn1.name("one");
    ComplexNumber cn2 = cn1;

    if ((cn1 != cn2)) return false;

    if (cn1.color() != cn2.color()) return false;
    if (cn1.name() != cn2.name()) return false;
    return true;
};

//[trace
ComplexNumber::ComplexNumber(const double real, const double imag) :
    mReal{real}, mImag{imag}
{
    if (trace) std::cout << __PRETTY_FUNCTION__ << std::endl; // <> Die Kontrollausgabe erfolgt abhängig von der Programm-globalen Variablen `trace`.
}
//]

//[cctor
ComplexNumber::ComplexNumber(const ComplexNumber& other) :
    mReal{other.mReal}, mImag{other.mImag}, mName{other.mName}, mColor{other.mColor} // <> Kopieren _aller_ Datenelemente (wie der vom Compiler erzeugte Kopierkonstruktor)
{
    if (trace) std::cout << __PRETTY_FUNCTION__ << std::endl;
}
//]

ComplexNumber::~ComplexNumber()
{
    if (trace) std::cout << __PRETTY_FUNCTION__ << std::endl;
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
        return "CN[" + std::to_string(mReal) + "," + std::to_string(mImag) + "]";
    }
    return "CN[" + std::to_string(mReal) + "," + std::to_string(mImag) + "," + mName + "]";
}

std::string ComplexNumber::toSVG() const
{
    std::string svgString = "<circle ";
    svgString += "cx=\"" + std::to_string(Math::toInt(mReal)) + "\" ";
    svgString += "cy=\"" + std::to_string(Math::toInt(mImag)) + "\" ";
    svgString += "r=\"" + std::to_string(mSVGRadius) + "\" ";
    svgString += "stroke=\"" + mColor + "\" ";
    svgString += "fill=\"" + mColor + "\" ";
    svgString +=  "/>";
    return svgString;
}

const std::string& ComplexNumber::color() const
{
    return mColor;
}

ComplexNumber& ComplexNumber::color(const std::string& color)
{
    mColor = color;
    return *this;
}

ComplexNumber& ComplexNumber::real(const double value)
{
    mReal = value;
    return *this;
}

ComplexNumber& ComplexNumber::imag(const double value)
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

//[op
ComplexNumber& ComplexNumber::operator+=(const ComplexNumber& other)
{
    mReal += other.mReal; // <> Die Datenelemente des eigenen Objektes werden direkt manipuliert.
    mImag += other.mImag;

    return *this;
}

ComplexNumber& ComplexNumber::operator-=(const ComplexNumber& other)
{
    mReal -= other.mReal; // <> Die Datenelemente des eigenen Objektes werden direkt manipuliert.
    mImag -= other.mImag;

    return *this;
}

ComplexNumber& ComplexNumber::operator*=(const ComplexNumber& other)
{
    double real = mReal * other.mReal - mImag * other.mImag; // <> Hier muss mit einer Interimsvariablen `real` gearbeitet werden, da das Datenelement `mReal` in der nächsten Zeile noch unverändert sein muss.
    double imag = mImag * other.mReal + mReal * other.mImag; // <> Aus Gründen der Vereinheitlichung auch hier mit Iterimsvariable
    mReal = real;
    mImag = imag;
    return *this;
}

ComplexNumber& ComplexNumber::operator/=(const ComplexNumber& other)
{
    *this *= other.conjugate(); // <> Beim Quotienten wird der Nenner reell, wenn man _konjugiert-komplex_ erweitert.
    double norm = other.norm(); // <> Dabei ergibt sich im Nenner dann das Betragsquadrat der Zahl im Nenner, dies wird auch als _Norm_ (der quadrierte Betrag) bezeichnet.
    mReal /= norm;
    mImag /= norm;
    return *this;
}

double ComplexNumber::norm() const
{
    return mReal * mReal + mImag * mImag; // <> Berechnung des Betragsquadrates
}

ComplexNumber ComplexNumber::conjugate() const
{
    return ComplexNumber{mReal, -mImag}; // <> Bei der _Konjugation_ wird der Imaginärteil negiert.
}

const ComplexNumber& ComplexNumber::operator+() const
{
    return *this; // <> Der _unäre_ Plus-Operator liefert das Objekt unverändert zurück.
}

ComplexNumber ComplexNumber::operator-() const
{
    return ComplexNumber{-mReal, -mImag}; // <> Der _unäre_ Minus-Operator liefert die negierte komplexe Zahl zurück.
}
//]

std::ostream& operator<<(std::ostream& out, const ComplexNumber& cn)
{
    return out << cn.toString();
}

ComplexNumber operator+(const ComplexNumber& c1, const ComplexNumber& c2)
{
    ComplexNumber sum = c1;
    sum += c2; // <> Kanonische Realisierung
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

//[op
ComplexNumber operator-(const ComplexNumber& c1, const ComplexNumber& c2)
{
    ComplexNumber diff = c1;
    diff -= c2; // <> Kanonische Realisierung
    return diff;
}


ComplexNumber operator*(const ComplexNumber& c1, const ComplexNumber& c2)
{
    ComplexNumber prod(c1);
    return prod *= c2; // <> Kanonische Realisierung (etwas verkürzt)
}


ComplexNumber operator/(const ComplexNumber& c1, const ComplexNumber& c2)
{
    return ComplexNumber(c1) /= c2; // <> Kanonische Realisierung (noch etwas weiter verkürzt)
}
//]
