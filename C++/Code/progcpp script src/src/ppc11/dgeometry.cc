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

#include "dgeometry.h"
#include "../lib/simpletest.h"

#include <cassert>
#include <algorithm>

DRect::DRect(const DPoint upperLeft, const DPoint bottomRight) : 
    mUpperLeft{upperLeft}, mBottomRight{bottomRight}
{
}

int DRect::width() const
{
    const int w{mBottomRight.mX - mUpperLeft.mX};
    assert(w >= 0);
    return w;
}

int DRect::height() const
{
    const int h{mUpperLeft.mY - mBottomRight.mY};
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
    if (rhs) {
        mUpperLeft.mX   = std::min(mUpperLeft.mX, rhs.mUpperLeft.mX);
        mBottomRight.mX = std::max(mBottomRight.mX, rhs.mBottomRight.mX);
        mBottomRight.mY = std::min(mBottomRight.mY, rhs.mBottomRight.mY);
        mUpperLeft.mY = std::max(mUpperLeft.mY, rhs.mUpperLeft.mY);
    }
    return *this;
}
//[plus
DRect operator+(const DRect& a, const DRect& b)
{
    return DRect(a) += b; // <> Dies ist sog. kanonische Implementierung des Operators `+` durch den Operator `+=`
}
//]

SIMPLETEST("DG std-ctor") {
    DRect dr;
    if (dr) return false;
    return true;
};

SIMPLETEST("DG ctor1") {
    DRect dr{{0, 1}, {1, 0}};
    if (!dr) return false;
    if (dr.area() != 1) return false;
    return true;
};

SIMPLETEST("DG attr1") {
    DRect dr{{0, 2}, {2, 0}};
    if (!dr) return false;
    if (dr.height() != 2) return false;
    if (dr.width() != 2) return false;
    if (dr.area() != 4) return false;
    return true;
};

SIMPLETEST("DG op+=1") {
    DRect dr1{{0, 2}, {2, 0}};
    DRect dr2;
    
    dr1 += dr2;
    
    if (!dr1) return false;
    if (dr1.area() != 4) return false;
    
    return true;
};

SIMPLETEST("DG op+=2") {
    DRect dr1{{0, 2}, {2, 0}};
    DRect dr2{{1, 3}, {3, 1}};
    
    dr1 += dr2;
    
    if (!dr1) return false;
    if (dr1.area() != 9) return false;
    
    return true;
};
