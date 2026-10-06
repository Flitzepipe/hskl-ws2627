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

#include <iosfwd>
#include <string>
#include <algorithm>

namespace FProg
{
    
    class Attribute
    {
    public:
        inline explicit Attribute(const std::string& name) : mName(name) {}
        inline Attribute& value(const std::string& value) {mValue = value; return *this;}
        inline const std::string& value() const {return mValue;}
        inline const std::string& name() const {return mName;}
    private:
        const std::string mName;
        std::string mValue;
    };
    
    std::ostream& operator<<(std::ostream&, const Attribute&);
    
    class Serializer
    {
    public:
        virtual bool start(const std::string& classname) = 0;
        virtual bool end() = 0;
        virtual bool writeToken(const Attribute& attr) = 0;
        virtual ~Serializer() {}
    };
    
    template<typename T>
    Serializer& operator<<(Serializer& serializer, const T& item)
    {
        return item.serialize(serializer);
    }
    
    class SerializerTransaction
    {
    public:
        inline SerializerTransaction(Serializer& serializer, const std::string& name) : mSerializer(serializer) {
            mSerializer.start(name);
        }
        inline bool writeToken(const Attribute& attr) {
            return mSerializer.writeToken(attr);
        }
        inline ~SerializerTransaction() {
            mSerializer.end();
        }
    private:
        Serializer& mSerializer;
    };
    
}
