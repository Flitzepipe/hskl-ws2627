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

#include "double.h"

#include "../lib/simpletest.h"

#include <iostream>

#include "math.h"

SIMPLETEST("equal1") {
    Double a = 1.0;
    Double b = 1.1;

    if (Math::equal(a, b)) return false;
    return true;
};

Double::Double(double v) : mValue(v) {}

Double Double::operator-() const
{
    return Double(-mValue);
}

std::ostream& operator<<(std::ostream& out, const Double& p) {
    out << p.mValue;
    return out;
}

Double operator-(const Double& lhs, const Double& rhs)
{
    return Double(lhs.mValue - rhs.mValue);
}

bool operator==(const Double& lhs, const Double& rhs)
{
    return Math::equal(lhs.mValue, rhs.mValue);
}

bool operator>(const Double& lhs, const Double& rhs)
{
    return lhs.mValue > rhs.mValue;
}

bool operator<(const Double& lhs, const Double& rhs)
{
    return lhs.mValue < rhs.mValue;
}

bool operator<=(const Double& lhs, const Double& rhs)
{
    return (lhs.mValue < rhs.mValue) || (lhs == rhs);
}

bool operator>=(const Double& lhs, const Double& rhs)
{
    return (lhs.mValue > rhs.mValue) || (lhs == rhs);
}

Double std::numeric_limits<Double>::epsilon()
{
        return std::numeric_limits<double>::epsilon();
}
