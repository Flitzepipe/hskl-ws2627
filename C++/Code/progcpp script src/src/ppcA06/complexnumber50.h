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

//[CNComp -old -ctor -data -getter -setter -add -out
//[CNAdd2 -old -ctor -data -getter -setter -comp -friend -out
//[CNAdd -old -ctor -data -getter -setter -comp -friend -ff
//[CNOutput -old -ctor -data -getter -setter -add -comp
//[CNParameter -old -friend -ctor -data -ff
#include <string>
#include <iosfwd> // <> `iostream` nicht notwendig, da nur _unvollständige_ Typen (Referenzen, Zeiger) in dieser Header-Datei verwendet werden.

class ComplexNumber {
    //[friend
    friend bool operator==(const ComplexNumber& c1, const ComplexNumber& c2); // <> Diese `friend`-Deklaration ermöglicht den Zugriff auf die _privaten_ Datenelemente.
//    friend std::ostream& operator<<(std::ostream& out, const ComplexNumber& cn); // <> Diese `friend`-Deklaration ist nur notwendig, falls die _öffentliche_ Elementfunktion `toString()` entfernt wird.
    //]
public:
    //[ctor
    ComplexNumber(double real = 0.0, double imag = 0.0); // Dieser allg. Konstruktor kann als _Typumwandlungskonstruktor_ `double` -> `ComplexNumber` verwendet werden.
    ~ComplexNumber();
    //]

    //[old
    double real() const;
    double imag() const;
    bool isReal() const;
    bool isImag() const;
    //]

    //[getter
    const std::string& name() const; // <> Die Regel für die Ergebnisrückgabe erlaubt hier (Beobachter) die Rückgabe _per-const-reference_.

    std::string toString() const; // <> Nicht mehr wirklich notwendig, da ja der `operator<<()` für den Typ `ComplexNumber` überladen worden ist.
    std::string toSVG() const;
    const std::string& color() const; // <> Wie oben: `name()`
    //]
    //[setter
    void color(const std::string& color); // <> Input-Parameter (UDT) als _const-reference_.
    void real(double value);
    void imag(double value);
    void name(const std::string& name); // <> Input-Parameter (UDT) als _const-reference_.
    //]

    //[add
    void add(const ComplexNumber& c); // <> Nicht mehr wirklich notwendig, da ja der `operator+=()` existiert.
    static ComplexNumber add(const ComplexNumber& c1, const ComplexNumber& c2); // <> Nicht mehr wirklich notwendig, da ja der `operator+()` existiert

    void operator+=(const ComplexNumber& other); // <> Der Ergebnistyp ist noch nicht korrekt! Vorgriff: s.a. die Regeln für die Verkettung von Mutatoren!
    //]
    //[data
private:
    double mReal{0.0};
    double mImag{0.0};
    std::string mName;
    inline static const int mSVGRadius{3};
    std::string mColor{"black"};
    //]
};
//]
//[ff
//[out
std::ostream& operator<<(std::ostream& out, const ComplexNumber& cn); // <> Macht die Elementfunktion `toString()` überflüssig.
//]
//[add
ComplexNumber operator+(const ComplexNumber& c1, const ComplexNumber& c2); // <> Input-Parameter (UDT) als _const-reference_.
//]
//[comp
bool operator==(const ComplexNumber& c1, const ComplexNumber& c2);
bool operator!=(const ComplexNumber& c1, const ComplexNumber& c2);
//]
//]
//]
//]
//]
//]


