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

//[iterator
template<typename ValueType>
class HeapArrayIterator final // <> Weil der Container `HeapArray<T>` ein Template ist, muss natürlich der Iterator dazu ebenfalls ein Template sein.
{
public:
    HeapArrayIterator(const ValueType* p = nullptr) : mPtr(p) {}
private:
    const ValueType* mPtr = nullptr; // <> Im wesentlichen kapselt dieses Klassentemplate den _rohen_ Zeiger auf die Elemente des Containers.
};
//]
//[class -ctor -util -private
template<typename ValueType>
class HeapArray final
{
public:
    //[ctor
    explicit HeapArray(size_t size) : mSize(size), mData(std::make_unique<ValueType[]>(size)) {
        assert(mData);
    }
    //[fill
    explicit HeapArray(size_t size, const ValueType& value) : mSize(size), mData(std::make_unique<ValueType[]>(size)) {
        assert(mData);
        std::fill(mData.get(), // <> Ein _roher_ Zeiger als _Anfang-Iterator_.
                  mData.get() + mSize, // <> Ein _roher_ _eins-hinter-das-letzte-Element_ Zeiger als Ende-Itrator.
                  value); // <> Der Füllwert `value`
    }
    //]
    //[ilist
    explicit HeapArray(const std::initializer_list<ValueType>& ilist) :
        mSize(ilist.size()), mData(std::make_unique<ValueType[]>(ilist.size())) {
        assert(mData);
        std::copy(std::begin(ilist), std::end(ilist),
                  &mData[0]); // <> Eine _alternative_ Möglichkeit, den _rohen_ Zeiger auf das erste Element zu bestimmen.
    }
    //]
    HeapArray() = delete;
    ~HeapArray() = default;

    HeapArray(const HeapArray& other) : mSize(other.mSize), mData(std::make_unique<ValueType[]>(other.mSize)) {
        std::copy(other.mData.get(), other.mData.get() + other.mSize, mData.get());
    }

    HeapArray& operator=(const HeapArray& rhs) {
        HeapArray<ValueType> copy = rhs;
        swap(copy);
        return *this;
    }

    HeapArray(HeapArray&& other) {
        swap(other);
    }

    HeapArray& operator=(HeapArray&& rhs) {
        swap(rhs);
        return *this;
    }
    //]
    //[beginend
    HeapArrayIterator<ValueType> begin() const {
        return HeapArrayIterator<ValueType>(&mData[0]);
    }

    HeapArrayIterator<ValueType> end() const {
        return HeapArrayIterator<ValueType>(&mData[mSize - 1] + 1);
    }
    //]
    //[util
    size_t size() const {return mSize;}

    ValueType& operator[](size_t index) {assert(mData); return mData[index];}
    const ValueType& operator[](size_t index) const {assert(mData); return mData[index];}

    void swap(HeapArray& other) {
        using std::swap;
        swap(mSize, other.mSize);
        swap(mData, other.mData);
    }
    //]
private:
    //[private
    size_t mSize{0};
    std::unique_ptr<ValueType[]> mData;
    //]
};
//]
template<typename T>
void swap(HeapArray<T>& a, HeapArray<T>& b) {
    a.swap(b);
}
