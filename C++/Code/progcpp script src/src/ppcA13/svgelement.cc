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

#include "svgelement.h"

#include <sstream>

#include "../lib/simpletest.h"
#include "math.h"
#include "trace10.h"

//[test1
SIMPLETEST("SVGAttribute1")
{
    SVGAttribute attr1{"name", "value"};

    std::string s = attr1;
    if (s != "name=\"value\"") return false;

    return true;
};

SIMPLETEST("SVGAttribute2")
{
    SVGAttribute attr1{"name", 42};

    std::string s = attr1;
    if (s != "name=\"42\"") return false;

    return true;
};

SIMPLETEST("SVGAttribute3")
{
    SVGAttribute attr1{"name", 42.0};

    std::string s = attr1;
    if (s != "name=\"42\"") return false;

    return true;
};
//]

//[tests
SIMPLETEST("SVGElement1")
{
    SVGElement element{"element"};
    SVGAttribute attr1{"name", 42.0};

    element += attr1;

    std::string s = element;
    if (s != "<element name=\"42\"/>") return false;

    return true;
};

SIMPLETEST("SVGElement2")
{
    SVGElement element{"element"};
    SVGAttribute attr1{"a1", "v1"};
    SVGAttribute attr2{"a2", 11};

    element += attr1;
    element += attr2;

    std::string s = element;
    if (s != "<element a1=\"v1\" a2=\"11\"/>") return false;

    std::stringstream ss;
    ss << element;
    if (ss.str() != "<element a1=\"v1\" a2=\"11\"/>") return false;

    return true;
};
//]

//[svgattr
SVGAttribute::SVGAttribute(const std::string& name, const std::string& value) :
    mName{name}, mValue{value}
{
}

SVGAttribute::SVGAttribute(const std::string& name, const int value) :
    mName{name}, mValue{std::to_string(value)}
{
}

SVGAttribute::SVGAttribute(const std::string& name, const double value) :
    mName{name}, mValue{std::to_string(Math::toInt(value))}
{
}

SVGAttribute::operator std::string() const
{
    return mName + "=\"" + mValue + '"';
}
//]

//[svgelem
SVGElement::SVGElement(const std::string& name) :
    mName{name}
{
}

SVGElement& SVGElement::operator+=(const SVGAttribute& attribute)
{
    mAttributes.push_back(attribute);
    return *this;
}

SVGElement& SVGElement::area(const DRect& area)
{
    mArea = area;
    return *this;
}

SVGElement::operator DRect() const
{
    return mArea;
}

SVGElement::operator std::string() const
{
    std::string svgString = "<" + mName;
    for(const SVGAttribute& a: mAttributes) {
        svgString += ' ';
        svgString += a;
    }
    return svgString += "/>";
}

std::ostream& operator<<(std::ostream& out, const SVGElement& element)
{
    return out << std::string(element); // <> Typumwandlung in `std::string` durch Typumwandlungsoperator und gleichzeitig Vermeidung einer endlosen Rekursion.
}
//]
