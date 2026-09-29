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

#include "complexnumber10.h"

#include <cmath>

//[ctors
ComplexNumber::ComplexNumber() :
    mReal{0.0}, mImag{0.0} // <> Diese Initialisierer sind streng genommen nicht notwendig, da wir _in-class_-Initialisierer haben.
{
}

ComplexNumber::ComplexNumber(const double real) :
    mReal{real}, mImag{0.0}
{
}

ComplexNumber::ComplexNumber(const double real, const double imag) :
    mReal{real}, mImag{imag}
{
}
//]

double ComplexNumber::real() const
{
    return mReal;
}

double ComplexNumber::imag() const
{
    return mImag;
}

//[predicates
bool ComplexNumber::isReal() const
{
    return std::fabs(mImag) < 1e-10; // <> Dieser Vergleich ist verbesserungswürdig! Die Schwelle ist willkürlich gewählt.
}

bool ComplexNumber::isImag() const
{
    return std::fabs(mReal) < 1e-10; // <> Dieser Vergleich ist verbesserungswürdig!
}
//]
