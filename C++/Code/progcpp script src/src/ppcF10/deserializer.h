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

#include "common.h"

#include <string>

namespace FProg
{

class Deserializer {
public:
    virtual bool start(const std::string& classname) = 0;
    virtual bool end() = 0;
    virtual bool readToken(const std::string& token, std::string& value) = 0;

    virtual ~Deserializer() {}
};

template<typename T, typename It>
Deserializer& deserialize(Deserializer& ds, It it) {
    while(auto item  = T::deserialize(ds)) {
        *it++ = *item;
    }
    return ds;
}

class DeserializerTransaction final {
public:
    inline DeserializerTransaction(Deserializer& deserializer, const std::string classname) : mDeserializer(deserializer) {
        mDeserializer.start(classname);
    }
    inline bool readToken(const std::string& token, std::string& value) {
        return mDeserializer.readToken(token, value);
    }

    ~DeserializerTransaction() {
        mDeserializer.end();
    }

private:
    Deserializer& mDeserializer;
};

}
