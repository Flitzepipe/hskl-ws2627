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

#include "svgfile.h"
#include <iostream>
#include <cassert>

#include "string.h"
#include "math.h"
#include "point60.h"

SVGFile::SVGFile(const std::string& filename) :
    mFile{filename}
{
    assert(mFile.is_open());
}

SVGFile::~SVGFile()
{
    assert(mFile.is_open());
    mFile << header1 << std::endl;
    mFile << header2 << std::endl;
    std::string width = std::to_string(mArea.width());
    std::string height = std::to_string(mArea.height());
    std::string actualHeader3 = header3;
    String::replace(actualHeader3, "$w", width);
    String::replace(actualHeader3, "$h", height);
    std::string viewbox = std::to_string(mArea.upperLeft().mX) + " " + std::to_string(mArea.bottomRight().mY) + " " + width + " " + height;
    String::replace(actualHeader3, "$v", viewbox);
    mFile << actualHeader3 << std::endl;
    mFile << mSVGData;
    mFile << footer1 << std::endl;
}
SVGFile& SVGFile::add(const Point& point)
{
    assert(mFile.is_open());
    mSVGData += point.toSVG();
    mSVGData += '\n';
    if (mArea) {
        mArea += point.svgArea();
    }
    else {
        mArea = point.svgArea();
    }
    return *this;
}
