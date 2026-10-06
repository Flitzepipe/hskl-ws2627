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

//[file -a
#include "dgeometry.h"

#include <cassert>
#include <algorithm>

#include "../lib/simpletest.h"

// todo: testcases //-

DRect::DRect(DPoint upperLeft, DPoint bottomRight) : mUpperLeft(upperLeft), mBottomRight(bottomRight)
{
}

//[a
int DRect::width() const
{
    int w = mBottomRight.mX - mUpperLeft.mX;
    assert(w >= 0);
    return w;
}

int DRect::height() const
{
    int h = mUpperLeft.mY - mBottomRight.mY;
    assert(h >= 0);
    return h;
}

int DRect::area() const
{
    return width() * height();
}

DRect::operator bool() const
{
    return area() != 0;
}

DPoint DRect::upperLeft() const
{
    return mUpperLeft;
}

DPoint DRect::bottomRight() const
{
    return mBottomRight;
}

DRect& DRect::operator+=(const DRect& rhs)
{
    mUpperLeft.mX   = std::min(mUpperLeft.mX, rhs.mUpperLeft.mX);
    mBottomRight.mX = std::max(mBottomRight.mX, rhs.mBottomRight.mX);
    mBottomRight.mY = std::min(mBottomRight.mY, rhs.mBottomRight.mY);
    mUpperLeft.mY = std::max(mUpperLeft.mY, rhs.mUpperLeft.mY);

    return *this;
}

DRect operator+(const DRect& a, const DRect& b)
{
    return DRect(a) += b;
}
//]
//]
