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

#include "complexnumber22.h"
#include "../lib/simpletest.h"
#include "math.h"
#include <cmath>

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
    const ComplexNumber cn2{0.0, 1.0};

    cn1.add(cn2);

    if (!Math::equal(cn1.real(), 1.0)) return false;
    if (!Math::equal(cn1.imag(), 1.0)) return false;
    return true;
};

#ifdef _MSC_VER //-
#  pragma warning(push) //-
#  pragma warning(disable: 4573) //-
#endif //-

SIMPLETEST("add2") {
    const ComplexNumber cn1{1.0, 0.0};
    const ComplexNumber cn2{0.0, 1.0};

    const ComplexNumber cn3 = ComplexNumber::add(cn2, cn1);

    if (!Math::equal(cn3.real(), 1.0)) return false;
    if (!Math::equal(cn3.imag(), 1.0)) return false;
    return true;
};

#ifdef _MSC_VER //-
#  pragma warning(push) //-
#  pragma warning(disable: 4573) //-
#endif //-

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

//[name
SIMPLETEST("toString1") {
    const ComplexNumber cn;

    if (cn.toString() != "CN[0.000000,0.000000]") return false;
    return true;
};

SIMPLETEST("toString2") {
    ComplexNumber cn{1};

    cn.name("abc");
    if (cn.toString() != "CN[1.000000,0.000000,abc]") return false;
    return true;
};
//]

ComplexNumber::ComplexNumber(const double real, const double imag) :
    mReal{real}, mImag{imag}
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
//[name
std::string ComplexNumber::name() const
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
//]
void ComplexNumber::real(const double value)
{
    mReal = value;
}

void ComplexNumber::imag(const double value)
{
    mImag = value;
}
//[name
void ComplexNumber::name(const std::string name)
{
    mName = name;
}
//]
bool ComplexNumber::isReal() const
{
    return Math::equal(mImag, 0.0);
}

bool ComplexNumber::isImag() const
{
    return Math::equal(mReal, 0.0);
}

void ComplexNumber::add(const ComplexNumber c)
{
    mReal += c.mReal;
    mImag += c.mImag;
}

ComplexNumber ComplexNumber::add(const ComplexNumber c1, const ComplexNumber c2)
{
    ComplexNumber sum{c1};
    sum.add(c2);
    return sum;
}
