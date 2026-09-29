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

#include "polar.h"

#include <cassert>

Polar::Radius operator*(Polar::Radius a, Polar::Radius b)
{
    return Polar::Radius{a.mValue * b.mValue};
}

Polar::Radius operator*(double a, Polar::Radius b)
{
    return Polar::Radius{a * b.mValue};
}

Polar::Radius operator*(Polar::Radius a, double b)
{
    return Polar::Radius{a.mValue * b};
}

Polar::Radius::Radius(double r) : mValue(r)
{
    assert(r >= 0.0);
}

Polar::Angle operator+(Polar::Angle a, Polar::Angle b)
{
    return {a.mRadiant + b.mRadiant};
}
