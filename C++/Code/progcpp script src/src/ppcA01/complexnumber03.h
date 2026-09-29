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
    ComplexNumber() = default; // <> Hier sind die _in-class_-Initialisierer notwendig
    ComplexNumber(double real, double imag);

    double real() const; // <> Eine sog. _Beobachter_-Elementfunktion für den Realteil
    double imag() const; // <> *Wichtig*: Beobachter-Elementfunktionen werden mit dem Zusatz `const` qualifiziert
private:
    double mReal = 0.0; // <> Dies ist ein sog. _in-class_-Initialisierer in _equal_-Form
    double mImag{0.0}; // <> Dies ist ein sog. _in-class_-Initialisierer in _brace_-Form
};

