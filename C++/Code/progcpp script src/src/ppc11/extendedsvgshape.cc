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

#include "extendedsvgshape.h"

ExtendedSVGShape::ExtendedSVGShape(const std::string& color) : mColor{color}, mSNR{mObjectCounter++}
{
}

void ExtendedSVGShape::swap(ExtendedSVGShape& other)
{
    using std::swap;
    swap(mColor, other.mColor);
}

int ExtendedSVGShape::getSNR() const
{
    return mSNR;
}

const std::string& ExtendedSVGShape::getColor() const
{
    return mColor;
}

ExtendedSVGShape& ExtendedSVGShape::setColor(const std::string& color)
{
    mColor = color;
    return *this;
}

ExtendedSVGShape& ExtendedSVGShape::setColor(unsigned char r, unsigned char g, unsigned char b)
{
    mColor = "rgb(" + std::to_string(r) + "," + std::to_string(g) + "," + std::to_string(b) + ")";
    return *this;
}

ExtendedSVGShape::~ExtendedSVGShape()
{
}

