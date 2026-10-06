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

#include <fstream>
#include <string>

#include "dgeometry.h"
#include "complexnumber90.h"
#include "complexvector60.h"
#include "complexpolygon30.h"
#include "svgelement.h"

//[class -a
class SVGFile
{
public:
    //[a
    SVGFile(const std::string& filename);
    ~SVGFile();
    //]
    SVGFile& add(const ComplexNumber& number); // <> Diese Übeladungen können später noch durch eine _Schnittstellendefinition_ (interface) vermieden werden.
    SVGFile& add(const ComplexVector& vector);
    SVGFile& add(const ComplexPolygon& polygon);
    //[a
    SVGFile& add(const SVGElement& element); // <> Mit Hilfe der Klasse `SVGElement` (und `SVGAttribute`) lässt sich diese Schnittstelle vereinfachen (die obigen Überladungen werden nicht mehr benötigt).
private:
    std::ofstream mFile;
    DRect mArea;
    std::string mSVGData;
    static const std::string header1;
    static const std::string header2;
    static const std::string header3;
    static const std::string footer1;
    //]
};
//]
