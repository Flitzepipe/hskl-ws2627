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

//[CN -a
class ComplexNumber {
    friend bool operator==(const ComplexNumber& c1, const ComplexNumber& c2);
    friend std::ostream& operator<<(std::ostream& out, const ComplexNumber& cn);
public:
    //[a
    ComplexNumber(double real =  0.0, double imag = 0.0);
    ComplexNumber(const ComplexNumber& other);
    ~ComplexNumber();

    ComplexNumber& operator=(const ComplexNumber& rhs); // <> Die Deklaration des _expliziten_ Kopierzuweisungsoperators.

    double real() const;
    double imag() const;
    bool isReal() const;
    bool isImag() const;
    const std::string& name() const;
    std::string toString() const;
    std::string toSVG() const;
    const std::string& color() const;
    //]
    ComplexNumber& color(const std::string& color); // <> Das eigene Objekt wird zurückgegeben und damit kann verkettet werden
    ComplexNumber& real(double value);
    ComplexNumber& imag(double value);
    ComplexNumber& name(const std::string& name);

    ComplexNumber& operator+=(const ComplexNumber& other); // <> Das eigene Objekt wird zurückgegeben und damit kann verkettet werden
    ComplexNumber& operator-=(const ComplexNumber& other);
    ComplexNumber& operator*=(const ComplexNumber& other);
    ComplexNumber& operator/=(const ComplexNumber& other);
    //[a
    double norm() const;
    ComplexNumber conjugate() const;

    size_t serial() const; // <> Observator-Funktion für die Seriennummer

    const ComplexNumber& operator+() const;
    ComplexNumber operator-() const;

    void add(const ComplexNumber& c);
    static ComplexNumber add(const ComplexNumber& c1, const ComplexNumber& c2);

private:
    double mReal{0.0};
    double mImag{0.0};
    std::string mName;
    inline static int mSVGRadius{3};
    std::string mColor{"black"};

    const size_t mSerial; // <> Das Seriennummer-Datenelement ist `const`.
    //]
};
//]
std::ostream& operator<<(std::ostream& out, const ComplexNumber& cn);

ComplexNumber operator+(const ComplexNumber& c1, const ComplexNumber& c2);
ComplexNumber operator-(const ComplexNumber& c1, const ComplexNumber& c2);
ComplexNumber operator*(const ComplexNumber& c1, const ComplexNumber& c2);
ComplexNumber operator/(const ComplexNumber& c1, const ComplexNumber& c2);

bool operator==(const ComplexNumber& c1, const ComplexNumber& c2);
bool operator!=(const ComplexNumber& c1, const ComplexNumber& c2);
