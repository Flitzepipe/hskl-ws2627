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
#include "attribute.h"
#include <optional>

namespace FProg {
    class DeserializerTransaction;
    class Deserializer {// NVI Pattern
        friend class DeserializerTransaction;
    public:
        virtual ~Deserializer() {}
        bool start(const std::string& classname);
        std::optional<Attribute> read(const std::string& name);
        bool stop();
    protected:
        virtual bool start_impl(const std::string& classname) = 0;
        virtual std::optional<Attribute> read_impl(const std::string& name) = 0; // Fehlerbehandlung?
        virtual bool stop_impl() = 0;
    private:
        bool mStarted{false};
    };
    
    template<typename T, typename Deserializer, typename It>
    Deserializer& deserialize(Deserializer& ds, It it) {
        using value_type = T;
        while(const auto item  = value_type::deserialize(ds)) {
            *it++ = *item;
        }
        return ds;
    }
    
    class DeserializerTransaction final {
    public:
        DeserializerTransaction(Deserializer& deserializer, const std::string classname);
        std::optional<Attribute> read(const std::string& token);
        ~DeserializerTransaction();
    private:
        bool mOk{true};
        Deserializer& mDeserializer;
    };
    
}
