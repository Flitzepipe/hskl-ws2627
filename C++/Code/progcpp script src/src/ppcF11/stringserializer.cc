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

#include "simpletest.h"

using namespace FProg;

SIMPLETEST("Serializer1"){
    StringSerializer ss;
    {
        SerializerTransaction st{ss, "class"};
        st.write(Attribute{"t"}.value("v"));
    }

    std::string o = "class { t = \"v\" }\n";

    if (ss.toString() != o) return false;
    return true;
};

SIMPLETEST("Deserializer1"){
    std::string o = "class { t = \"v\" }\n";

    StringDeserializer ds(o);
    if (!ds.start("class")) return false;
    if (auto attr = ds.read("t")) {
        if (attr->value() != "v") return false;
    }
    else {
        return false;
    }
    if (!ds.stop()) return false;

    return true;
};

SIMPLETEST("SerDeser1") {
    StringSerializer ss;
    {
        SerializerTransaction st{ss, "class"};
        st.write(Attribute{"t"}.value("v"));
    }
    StringDeserializer ds(ss.toString());
    {
        DeserializerTransaction dt{ds, "class"};
        if (auto attr = dt.read("t")) {
            if (attr->value() != "v") return false;
        }
        else {
            return false;
        }
    }
    return true;
};

void StringSerializer::start_impl(const std::string &classname){
    mData << classname << " {";
}

void StringSerializer::stop_impl(){
    mData << " }\n";
}

void StringSerializer::write_impl(const Attribute& attribute){
    mData << " " << attribute;
}

std::string StringSerializer::toString() const{
    return mData.str();
}

StringDeserializer::StringDeserializer(const std::string &data) :
    mData(data){
}

bool StringDeserializer::start_impl(const std::string &classname){
    std::string token;
    mData >> token;
    if (token != classname) {
        return false;
    }
    mData >> token;
    if (token != "{") {
        return false;
    }
    return true;
}

bool StringDeserializer::stop_impl(){
    while(!mData.eof()) {
        std::string token;
        mData >> token;
        if (token == "}") {
            return true;
        }
    }
    return false;
}

std::optional<Attribute> StringDeserializer::read_impl(const std::string& token){
    std::string actualToken;
    mData >> actualToken;
    if (actualToken != token) {
        return {};
    }
    mData >> actualToken;
    if (actualToken != "=") {
        return {};
    }
    std::string value;
    mData >> std::quoted(value);
    return Attribute{token}.value(value);
}


std::ostream& FProg::operator<<(std::ostream& out, const StringSerializer& serializer){
    return out << serializer.toString();
}


