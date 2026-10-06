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
#include <iosfwd>

//[CNOp -b
//[CN -a
class ComplexNumber {
    //[b
    //[a
    friend bool operator==(const ComplexNumber& c1, const ComplexNumber& c2);
    friend std::ostream& operator<<(std::ostream& out, const ComplexNumber& cn);
    //]
    //]
public:
    //[b
    //[a
    ComplexNumber(double real = 0.0, double imag = 0.0);
    //]
    //]
    ComplexNumber(const ComplexNumber& other); // <> Die _Deklaration_ des Kopierkonstruktors
    //[a
    //[b
    ~ComplexNumber();

    double real() const;
    double imag() const;
    bool isReal() const;
    bool isImag() const;
    const std::string& name() const;
    std::string toString() const;
    std::string toSVG() const;
    const std::string& color() const;
    //[setter
    ComplexNumber& color(const std::string& color); // <> Das eigene Objekt wird zurückgegeben und damit kann verkettet werden
    ComplexNumber& real(double value); // <> Das eigene Objekt wird zurückgegeben und damit kann verkettet werden
    ComplexNumber& imag(double value); // <> Das eigene Objekt wird zurückgegeben und damit kann verkettet werden
    ComplexNumber& name(const std::string& name); // <> Das eigene Objekt wird zurückgegeben und damit kann verkettet werden
    //]
    //]
    ComplexNumber& operator+=(const ComplexNumber& other); // <> Der Zuweisung-Additionsoperator, das eigene Objekt wird zurückgegeben und damit kann verkettet werden
    ComplexNumber& operator-=(const ComplexNumber& other); // <> Der Zuweisung-Subtraktionsoperator, das eigene Objekt wird zurückgegeben und damit kann verkettet werden
    ComplexNumber& operator*=(const ComplexNumber& other); // <> Der Zuweisung-Multiplikationsoperator, das eigene Objekt wird zurückgegeben und damit kann verkettet werden
    ComplexNumber& operator/=(const ComplexNumber& other); // <> Der Zuweisung-Divisionsoperator, das eigene Objekt wird zurückgegeben und damit kann verkettet werden

    double norm() const; // <> Berechnung des Betragsquadrates
    ComplexNumber conjugate() const; // <> Bestimmung der _konjugiert_-komplexen Zahl

    const ComplexNumber& operator+() const; // Der _unäre_-Plus-Operator (No-Operation)
    ComplexNumber operator-() const; // <> Der _unäre_-Minus-Operator (Negation)
    //[b
    void add(const ComplexNumber& c);
    static ComplexNumber add(const ComplexNumber& c1, const ComplexNumber& c2);

private:
    double mReal{0.0};
    double mImag{0.0};
    std::string mName;
    inline static const int mSVGRadius{3};
    std::string mColor{"black"};
    //]
    //]
};
//]
std::ostream& operator<<(std::ostream& out, const ComplexNumber& cn);

ComplexNumber operator+(const ComplexNumber& c1, const ComplexNumber& c2); // <> Der _binäre_ Additionsoperator
ComplexNumber operator-(const ComplexNumber& c1, const ComplexNumber& c2); // <> Der _binäre_ Subtraktionsoperator
ComplexNumber operator*(const ComplexNumber& c1, const ComplexNumber& c2); // <> Der _binäre_ Multiplikationsoperator
ComplexNumber operator/(const ComplexNumber& c1, const ComplexNumber& c2); // <> Der _binäre_ Divisionsoperator

bool operator==(const ComplexNumber& c1, const ComplexNumber& c2);
bool operator!=(const ComplexNumber& c1, const ComplexNumber& c2);
//]
