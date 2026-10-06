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

#include "complexnumber50.h"
#include "../lib/simpletest.h"
#include "math.h"
#include <cmath>
//[CNOutput
#include <iostream> // <> In dieser Implementierungsdatei wird wegen `operator<<(...)` der _vollständige_ Typ `std::ostream` benötigt.
//]
#include <sstream>

SIMPLETEST("ctor1") {
    ComplexNumber cn;

    if (!Math::equal(cn.real(), 0.0)) return false;
    if (!Math::equal(cn.imag(), 0.0)) return false;
    return true;
};

SIMPLETEST("ctor2") {
    ComplexNumber cn{1.0, 1.1};

    if (!Math::equal(cn.real(), 1.0)) return false;
    if (!Math::equal(cn.imag(), 1.1)) return false;
    return true;
};

SIMPLETEST("ctor3") {
    ComplexNumber cn{2.0};

    if (!Math::equal(cn.real(), 2.0)) return false;
    if (!Math::equal(cn.imag(), 0.0)) return false;
    return true;
};

SIMPLETEST("ctor conversion") {
    ComplexNumber cn = 2.0;

    if (!Math::equal(cn.real(), 2.0)) return false;
    if (!Math::equal(cn.imag(), 0.0)) return false;
    return true;
};

SIMPLETEST("predicate") {
    ComplexNumber cn;

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

//[CNAdd
SIMPLETEST("op+=") {
    ComplexNumber cn1{1.0, 0.0};
    ComplexNumber cn2{0.0, 1.0};

    cn1 += cn2;

    if (!Math::equal(cn1.real(), 1.0)) return false;
    if (!Math::equal(cn1.imag(), 1.0)) return false;
    return true;
};
//]

#ifdef _MSC_VER //-
#  pragma warning(push) //-
#  pragma warning(disable: 4573) //-
#endif //-

SIMPLETEST("add2") {
    ComplexNumber cn1{1.0, 0.0};
    ComplexNumber cn2{0.0, 1.0};

    ComplexNumber cn3 = ComplexNumber::add(cn2, cn1);

    if (!Math::equal(cn3.real(), 1.0)) return false;
    if (!Math::equal(cn3.imag(), 1.0)) return false;
    return true;
};

#ifdef _MSC_VER //-
#  pragma warning(pop) //-
#endif //-

SIMPLETEST("op+") {
    ComplexNumber cn1{1.0, 0.0};
    ComplexNumber cn2{0.0, 1.0};

    ComplexNumber cn3 = cn2 + cn1;

    if (!Math::equal(cn3.real(), 1.0)) return false;
    if (!Math::equal(cn3.imag(), 1.0)) return false;
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

ComplexNumber::ComplexNumber(const double real, const double imag) :
    mReal{real}, mImag{imag}
{
}

ComplexNumber::~ComplexNumber()
{
}

double ComplexNumber::real() const
{
    return mReal;
}

double ComplexNumber::imag() const
{
    return mImag;
}

const std::string& ComplexNumber::name() const // <> Eine Beobachterfunktion (`const`) darf _per-const-reference_ ein Datenelement zurückgeben.
{
    return mName;
}

std::string ComplexNumber::toString() const // <> Ein _temporärer_ String *muss* _per-value_ zurückgegeben werden.
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

void ComplexNumber::color(const std::string& color) // <> In dieser Parameterliste ist der Input-Parameter `color` ein UDT, daher _per-const-reference_ entgegengenommen.
{
    mColor = color;
}

void ComplexNumber::real(const double value)
{
    mReal = value;
}

void ComplexNumber::imag(const double value)
{
    mImag = value;
}

void ComplexNumber::name(const std::string& name) // <> Input-Parameter: wie oben!
{
    mName = name;
}

bool ComplexNumber::isReal() const
{
    return Math::equal(mImag, 0.0);
}

bool ComplexNumber::isImag() const
{
    return Math::equal(mReal, 0.0);
}

void ComplexNumber::add(const ComplexNumber& c) // <> Input-Parameter: wie oben!
{
    mReal += c.mReal;
    mImag += c.mImag;
}

ComplexNumber ComplexNumber::add(const ComplexNumber& c1, const ComplexNumber& c2) // <> Input-Parameter: wie oben!
{
    ComplexNumber sum = c1;
    sum.add(c2);
    return sum;
}

//[CNAdd
void ComplexNumber::operator+=(const ComplexNumber& other) // <> Der Ergebnistyp ist noch nicht korrekt! Vorgriff: s.a. die Regeln für die Verkettung von Mutatoren!
{
    mReal += other.mReal;
    mImag += other.mImag;
}
//]

//[CNOutput
std::ostream& operator<<(std::ostream& out, const ComplexNumber& cn) // <> Das Idiom _reference-in / reference-out_ ist hier umgesetzt.
{
    return out << cn.toString();
}
//]

//[CNAdd2
ComplexNumber operator+(const ComplexNumber& c1, const ComplexNumber& c2)
{
    ComplexNumber sum = c1; // <> Erzeugen einer Kopie von `c1`. Alternativ: für Parameter `c1` Parameterübergabe _per-value_.
    sum += c2; // <> Die sog. _kanonische_ Implementierung verwendet den `+=`-Operator und vermeidet damit Code-Duplizierung.
    return sum; // <> Wenn der Ergebnistyp des `+=`-Operators _später_ nach den Regeln der _Mutatoren_ angepasst wird, dann lässt sich dieses hier auch noch kürzer (_idiomatischer_) schreiben.
}
//]

//[CNComp
bool operator==(const ComplexNumber& c1, const ComplexNumber& c2) // <> Durch die `friend`-Deklaration kann diese _freie_ Funktion auf die _privaten_ Datenelemente zugreifen.
{
    return Math::equal(c1.mReal, c2.mReal) && Math::equal(c1.mImag, c2.mImag);
}

bool operator!=(const ComplexNumber& c1, const ComplexNumber& c2) // <> Diese kanonische Implementierung verwendet den `operator==()`
{
    return !(c1 == c2); // <> Die sog. _kanonische_ Implementierung verwendet den `==`-Operator und vermeidet damit Code-Duplizierung.
}
//]
