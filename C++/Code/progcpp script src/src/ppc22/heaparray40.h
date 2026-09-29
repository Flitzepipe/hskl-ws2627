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
#include <iterator>

template<typename ValueType>
class HeapArray final
{
public:
    typedef ValueType value_type; // für insert iterator

    class HeapArrayIterator final : public std::iterator<std::random_access_iterator_tag, ValueType>
    {
        // random access
        using diff_t = typename std::iterator<std::random_access_iterator_tag, ValueType>::difference_type;
    public:
        HeapArrayIterator(ValueType* p = nullptr) : mPtr(p) {}
        HeapArrayIterator& operator++() {
            ++mPtr; return *this;
        }
        HeapArrayIterator operator++(int) {
            HeapArrayIterator copy = *this;
            ++mPtr;
            return copy;
        }
        ValueType& operator*() {return *mPtr;}

        bool operator!=(const HeapArrayIterator& rhs) {return mPtr != rhs.mPtr;}
        bool operator==(const HeapArrayIterator& rhs) {return !(*this != rhs);}

        //[ randomaccess
        HeapArrayIterator operator+(diff_t n) {
            HeapArrayIterator copy{*this};
            copy.mPtr += n;
            return copy;
        }
        HeapArrayIterator operator-(diff_t n) {
            HeapArrayIterator copy{*this};
            copy.mPtr -= n;
            return copy;
        }
        diff_t operator-(const HeapArrayIterator& rhs) {
            return mPtr - rhs.mPtr;
        }
        bool operator<(const HeapArrayIterator& rhs) {
            return mPtr < rhs.mPtr;
        }
        HeapArrayIterator& operator--() {
            --mPtr;
            return *this;
        }
        //]
    private:
        ValueType* mPtr = nullptr;
    };

    HeapArray() = default;

    explicit HeapArray(size_t size) : mSize(size), mCapacity(size), mData(std::make_unique<ValueType[]>(size)) {
        assert(mData);
    }

    explicit HeapArray(size_t size, const ValueType& value) : mSize(size), mCapacity(size), mData(std::make_unique<ValueType[]>(size)) {
        assert(mData);
        std::fill(mData.get(), mData.get() + mSize, value);
    }

    HeapArray(const std::initializer_list<ValueType>& ilist) :
        mSize(ilist.size()), mCapacity(ilist.size()), mData(std::make_unique<ValueType[]>(ilist.size())) {
        assert(mData);
        std::copy(std::begin(ilist), std::end(ilist), mData.get());
    }

    HeapArray(const HeapArray& other) : mSize(other.mSize), mCapacity(other.mCapacity), mData(std::make_unique<ValueType[]>(other.mSize)) {
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

    ~HeapArray() = default;

    HeapArrayIterator begin() const {
        return HeapArrayIterator(&mData[0]);
    }

    HeapArrayIterator end() const {
        return HeapArrayIterator(&mData[mSize - 1] + 1);
    }

    size_t size() const {return mSize;}
    size_t capacity() const {return mCapacity;}


    ValueType& operator[](size_t index) {assert(mData); assert(index < mSize); return mData[index];}
    const ValueType& operator[](size_t index) const {assert(mData); assert(index < mSize); return mData[index];}

    void swap(HeapArray& other) {
        using std::swap;
        swap(mSize, other.mSize);
        swap(mCapacity, other.mCapacity);
        swap(mData, other.mData);
    }

    //[grow
    void push_back(const ValueType& v) {
        if (mSize >= mCapacity) {
            reserve(2 * (mSize + 1));
        }
        assert(mSize < mCapacity);
        mData[mSize++] = v;
    }

    void reserve(size_t count) {
        if (count <= mCapacity)
            return;
        assert(count > mCapacity);

        auto copy = std::make_unique<ValueType[]>(count);
        std::copy(mData.get(), mData.get() + mSize, copy.get());

        std::swap(mData, copy);
        mCapacity = count;
    }
    //]
private:
    size_t mSize{0};
    size_t mCapacity{0};
    std::unique_ptr<ValueType[]> mData;
};

template<typename T>
void swap(HeapArray<T>& a, HeapArray<T>& b) {
    a.swap(b);
}
