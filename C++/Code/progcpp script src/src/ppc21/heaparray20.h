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
#include <iostream>

//[class
template<typename ValueType>
class HeapArray final
{
public:
    explicit HeapArray(size_t size) : mSize(size), mData(std::make_unique<ValueType[]>(size)) {
        assert(mData);
    }

    HeapArray() = delete;
    ~HeapArray() = default;

    explicit HeapArray(const std::initializer_list<ValueType>& ilist) :
        mSize(ilist.size()), mData(std::make_unique<ValueType[]>(ilist.size())) {
        assert(mData);
        ValueType* ptr = mData.get();
        for(const ValueType& v: ilist) {
            *ptr++ = v;
        }
    }
    //[copyswap
    HeapArray(const HeapArray& other) : mSize(other.mSize), mData(std::make_unique<ValueType[]>(other.mSize)) {
        for(size_t i = 0; i < mSize; ++i) { // <> Der Kopierkonstruktor fertigt eine _tiefe_ Kopie an.
            mData[i] = other.mData[i];
        }
    }

    HeapArray& operator=(const HeapArray& rhs) { // <> Anwendung des _Copy-Swap_-Idioms
        HeapArray<ValueType> copy = rhs;
        swap(copy);
        return *this;
    }

    HeapArray(HeapArray&& other) { // <> Die `default`-Version des Verschiebungskonstruktors ist eigentlich ausreichend, da alle Datenelemente versschiebbar sind.
        swap(other);
    }

    HeapArray& operator=(HeapArray&& rhs) { // <> Auch hier ist wegen der Verschiebbarkeit der Datenelemente die `default`-Version eigentlich ausreichend.
        swap(rhs);
        return *this;
    }
    //]
    size_t size() const {return mSize;}

    ValueType& operator[](size_t index) {assert(mData); return mData[index];}
    const ValueType& operator[](size_t index) const {assert(mData); return mData[index];}

    //[copyswap
    void swap(HeapArray& other) { // <> Die _idiomatische_ Realisierung der Vertauschungsoperation
        using std::swap;
        swap(mSize, other.mSize);
        swap(mData, other.mData);
    }
    //]
private:
    size_t mSize{0};
    std::unique_ptr<ValueType[]> mData;
};
//]
//[copyswap
template<typename T> // <> Für ein Klassentemplate brauchen wir auch ein freies Funktionstemplate für die Vertauschungsoperation
void swap(HeapArray<T>& a, HeapArray<T>& b) {
    a.swap(b);
}
//]
