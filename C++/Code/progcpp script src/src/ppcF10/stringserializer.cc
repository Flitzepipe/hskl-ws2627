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

#include "stringserializer.h"

#include <iostream>
#include <iomanip>

#include "../lib/simpletest.h"

using namespace FProg;

SIMPLETEST("Serializer1")
{
    StringSerializer ss;
    if (!ss.start("class")) return false;
    if (!ss.writeToken(Attribute("t").value("v"))) return false;
    if (!ss.end()) return false;

    std::string o = "class { t = \"v\" }\n";

    if (ss.toString() != o) return false;
    return true;
};

SIMPLETEST("Deserializer1")
{
    std::string o = "class { t = \"v\" }\n";

    StringDeserializer ds(o);
    if (!ds.start("class")) return false;
    std::string value;
    if (!ds.readToken("t", value)) return false;
    if (!ds.end()) return false;

    if (value != "v") return false;
    return true;
};

SIMPLETEST("SerDeser1")
{
    StringSerializer ss;
    if (!ss.start("class")) return false;
    if (!ss.writeToken(Attribute("t").value("v"))) return false;
    if (!ss.end()) return false;

    StringDeserializer ds(ss.toString());
    if (!ds.start("class")) return false;
    std::string value;
    if (!ds.readToken("t", value)) return false;
    if (!ds.end()) return false;

    if (value != "v") return false;

    return true;
};

bool StringSerializer::start(const std::string &classname)
{
    if (mStarted) {
        return false;
    }
    mData << classname << " {";
    mStarted = true;
    return true;
}

bool StringSerializer::end()
{
    if (!mStarted) {
        return false;
    }
    mData << " }\n";
    mStarted = false;
    return true;
}

bool StringSerializer::writeToken(const Attribute& attribute)
{
    if (!mStarted) {
        return false;
    }
    mData << " " << attribute;
    return true;
}

std::string StringSerializer::toString() const
{
    return mData.str();
}

StringSerializer::~StringSerializer()
{
    // no asserts in dtor -> exceptions!
#ifndef NDEBUG
    if (mStarted) {
        std::cerr << __PRETTY_FUNCTION__ <<
                     " wrong use of class StringSerializer" << std::endl;
    }
#endif
}

StringDeserializer::StringDeserializer(const std::string &data) :
    mData(data),
    mStarted(false)
{
}

StringDeserializer::~StringDeserializer()
{
    // no asserts in dtor -> exceptions!
#ifndef NDEBUG
    if (mStarted) {
        std::cerr << __PRETTY_FUNCTION__ <<
                     " wrong use of class StringDeserializer" << std::endl;
    }
#endif
}

bool StringDeserializer::start(const std::string &classname)
{
    if (mStarted) {
        return false;
    }
    std::string token;
    mData >> token;
    if (token != classname) {
        return false;
    }
    mData >> token;
    if (token != "{") {
        return false;
    }
    mStarted = true;
    return true;
}

bool StringDeserializer::end()
{
    if (!mStarted) {
        return false;
    }
    while(!mData.eof()) {
        std::string token;
        mData >> token;
        if (token == "}") {
            mStarted = false;
            return true;
        }
    }
    return false;
}

bool StringDeserializer::readToken(const std::string& token, std::string& value)
{
    if (!mStarted) {
        return false;
    }
    std::string actualToken;
    mData >> actualToken;
    if (actualToken != token) {
        return false;
    }
    mData >> actualToken;
    if (actualToken != "=") {
        return false;
    }
    mData >> std::quoted(value);
    return true;
}


std::ostream& FProg::operator<<(std::ostream& out, const StringSerializer& serializer)
{
    return out << serializer.toString();
}


