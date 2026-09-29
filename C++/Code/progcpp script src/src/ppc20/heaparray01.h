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
template<typename ValueType>
class HeapArray final // <> Defintion des Klassen-Templates
{
public:
    explicit HeapArray(size_t size); // <> Deklaration der Klassen-Template-Elementfunktion
    size_t size() const;

    ValueType& operator[](size_t index);
    const ValueType& operator[](size_t index) const;
private:
    size_t mSize{0};
    std::unique_ptr<ValueType[]> mData;
};
//]
//[defs
template<typename ValueType> //<> Template-Präambel muss wiederholt werden
HeapArray<ValueType>::HeapArray(size_t size) : // <> Definition des Klassen-Template-Konstruktors
    mSize(size), mData(std::make_unique<ValueType[]>(size))
{
    assert(mData);
}

template<typename ValueType> //<> Template-Präambel muss wiederholt werden
size_t HeapArray<ValueType>::size() const // <> Defintion der Klassen-Template-Elementfunktion
{
    assert(mData);
    return mSize;
}
//]

template<typename ValueType>
ValueType& HeapArray<ValueType>::operator[](size_t index) {
    assert(mData);
    return mData[index];
}

template<typename ValueType>
const ValueType& HeapArray<ValueType>::operator[](size_t index) const {
    assert(mData);
    return mData[index];
}
