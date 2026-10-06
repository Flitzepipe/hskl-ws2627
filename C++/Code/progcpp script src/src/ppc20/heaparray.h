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

#if __has_include("../ppc.h")
# include "../ppc.h"
#endif

#include <memory>
#include <cassert>

//[class
template<typename ValueType> // <> Der Template-Typ-Parameter heisst diesmal `ValueType` {smile}
class HeapArray final // <> Eine weitere Ableitung verhindern.
{
public:
    explicit HeapArray(size_t size) :
        mSize(size),
        mData(std::make_unique<ValueType[]>(size)) // <> Das Funktionstemplate {stdmake_unique} führt auch eine _value-initialization_ durch.
    {
        assert(mData); // <> Sicherstellen, dass eine Speicherallokation stattgefunden hat. Dies ist eher ein _geprüfter_ Kommentar als wirklich notwendig.
    }
    size_t size() const {
        assert(mData);
        return mSize;
    }
    ValueType& operator[](size_t index) { // <> Subscript-Operator (Mutator)
        assert(mData);
        return mData[index];
    }
    const ValueType& operator[](size_t index) const { // <> Subscript-Operator (Observator)
        assert(mData);
        return mData[index];
    }
private:
    size_t mSize{0};
    std::unique_ptr<ValueType[]> mData;
};
//]
