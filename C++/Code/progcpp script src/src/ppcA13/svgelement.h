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

#include <string>
#include <iosfwd>
#include <vector>

#include "dgeometry.h"

//[svgattr
class SVGElement; // <> Für die folgende `friend`-Deklaration muss die Klasse `SVGElement` bekannt sein (Vorwärts-Deklaration).

class SVGAttribute final
{
    friend class SVGElement; // <> Auch eine _Klasse_ kann als `friend` deklariert werden.
public:
    SVGAttribute(const std::string& name, const std::string& value); // <> `svg`-Attribute sind `xml`-Attribute-Werte-Paare.
    SVGAttribute(const std::string& name, int value);
    SVGAttribute(const std::string& name, double value);

    operator std::string() const;

private:
    std::string mName;
    std::string mValue;
};
//]

//[svgelem
class SVGElement final
{
public:
    explicit SVGElement(const std::string& name);

    SVGElement& operator+=(const SVGAttribute& attribute);

    SVGElement& area(const DRect& area); // <> Der zugehörige `getter` ist als Typumwandlungsoperator realisiert.
    operator DRect() const; // <> Dies ist der _Typumwandlungsoperator_ nach `DRect`

    operator std::string() const; // <> Dies ist der _Typumwandlungsoperator_ nach `std::string`

private:
    std::string mName;
    std::vector<SVGAttribute> mAttributes;
    DRect mArea;
};

std::ostream& operator<<(std::ostream& out, const SVGElement& element);
//]
