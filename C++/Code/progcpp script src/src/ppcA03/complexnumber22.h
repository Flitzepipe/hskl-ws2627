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

#include <string> // <> Notwendige _Header_-Datei für den Datentyp {stdstring}.

class ComplexNumber
{
public:
    ComplexNumber(double real = 0.0, double imag = 0.0);
    double real() const; //-
    double imag() const; //-
    std::string name() const; // <> Beobachter
    std::string toString() const; // <> Beobachter

    void real(double value);
    void imag(double value);
    void name(std::string name);

    bool isReal() const; //-
    bool isImag() const; //-

    void add(ComplexNumber c); //-
    static ComplexNumber add(ComplexNumber c1, ComplexNumber c2); //-
private:
    double mReal{0.0}; // <> Datenelemente primitiver DT bekommen _in-class-initializer_
    double mImag{0.0};
    std::string mName; // <> Das Datenelement `mName` wird als _UDT_ mit dem Standardkonstruktor initialisiert!
};
