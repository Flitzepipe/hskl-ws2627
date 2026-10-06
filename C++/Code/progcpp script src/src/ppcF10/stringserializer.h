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

#include <sstream>

#include "serializer.h"
#include "deserializer.h"

namespace FProg
{

class StringSerializer final : public Serializer {
public:
    StringSerializer() = default;
    virtual bool start(const std::string& classname) override;
    virtual bool end() override;
    virtual bool writeToken(const Attribute& attribute)  override;

    std::string toString() const;

    virtual ~StringSerializer();
private:
    StringSerializer(const StringSerializer&) = delete;
    StringSerializer& operator=(const StringSerializer&) = delete;

    std::stringstream mData;
    bool mStarted{false};
};

std::ostream& operator<<(std::ostream& out, const StringSerializer& serializer);


class StringDeserializer final : public Deserializer {
public:
    StringDeserializer(const std::string& data);

    virtual bool start(const std::string& classname) override;
    virtual bool end() override;
    virtual bool readToken(const std::string& token, std::string& value) override;

    virtual ~StringDeserializer();
private:
    StringDeserializer(const StringSerializer&) = delete;
    StringDeserializer& operator=(const StringSerializer&) = delete;

    std::stringstream mData;
    bool mStarted{false};
};

}
