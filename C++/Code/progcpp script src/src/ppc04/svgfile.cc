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

//[svgfile

SVGFile::SVGFile(const std::string& filename, const int xSize, const int ySize) :
    mFile{filename},
    mXSize{xSize},
    mYSize{ySize}
{
    assert(mFile.is_open());
    mFile << header1 << std::endl;
    mFile << header2 << std::endl;
    std::string actualHeader3{header3};
    String::replace(actualHeader3, "$w", std::to_string(mXSize)); // <> Zum Erstezen eines Teilstrings wurde eine Hilfsfunktion geschrieben.
    String::replace(actualHeader3, "$h", std::to_string(mYSize));
    mFile << actualHeader3 << std::endl;
}
//]

SVGFile::~SVGFile()
{
    assert(mFile.is_open());
    mFile << footer1 << std::endl;
}
void SVGFile::add(const std::string& svgElement)
{
    assert(mFile.is_open());
    mFile << svgElement << std::endl;
}

int SVGFile::getXSize() const
{
    return mXSize;
}

int SVGFile::getYSize() const
{
    return mYSize;
}

