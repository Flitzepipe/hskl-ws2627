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

#include <optional>

#include "common.h"
#include "concepts.h"
#include "serializer.h"
#include "deserializer.h"

// CRTP (curiously recurring template pattern)
namespace FProg{
    template<typename T>
    class Serializable { // <> Hier kann man den _constraint_ `Deserializable<T>()` noch nicht anbringen, da ggf. der Typ `T` wegen CRTP noch nicht vollständig bekannt ist.
    public:
        virtual Serializer& serialize(Serializer& serializer) const = 0;
        inline static std::optional<T> deserialize(Deserializer& deserializer) requires Deserializable<T> { 
            return T::doDeserialize(deserializer);
        }
        inline virtual ~Serializable() {};
    };
    
}
