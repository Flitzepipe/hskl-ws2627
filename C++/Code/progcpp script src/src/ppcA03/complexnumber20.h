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

class ComplexNumber
{
public:
    ComplexNumber();
    ComplexNumber(double real);
    ComplexNumber(double real, double imag);
    double real() const; // <> Obervatoren sind `const`-Elementfunktionen
    double imag() const;

    void real(double value); // <> non-`const`-Elementfunktionen verändern das Objekt
    void imag(double value);

    bool isReal() const; // <> Dies ist auch eine Observator-Funktion
    bool isImag() const;
    void add(ComplexNumber c);
    static ComplexNumber add(ComplexNumber c1, ComplexNumber c2);
private:
    double mReal{0.0}; // <> Datenelemente primitiver DT bekommen _in-class-initializer_
    double mImag{0.0};
};

