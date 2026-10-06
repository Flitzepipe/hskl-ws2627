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
#include "util.h"
#include "propagate_const.h"
#include "algorithm.h"
#include <memory>
#include <cassert>
#include <iostream>
#include <iterator>


namespace FProg {
    template<typename ValueType, typename SizeType = size_t>
    class Vector final {
    public:
        using value_type = ValueType ; // <> für insert iterator notwendig
        using size_type = SizeType ;
        
        class ConstIterator final {
        public:
            using value_type = ValueType;
            using difference_type = std::ptrdiff_t;
            using iterator_category = std::random_access_iterator_tag;
            using pointer = ValueType*;
            using reference = ValueType&;
            
            ConstIterator(const ValueType* p = nullptr) : mPtr{p} {}
            ConstIterator& operator++() {
                ++mPtr; 
                return *this;
            }
            ConstIterator operator++(int) {
                ConstIterator copy{*this};
                ++mPtr;
                return copy;
            }
            const ValueType& operator*() {
                return *mPtr;
            }
            
            bool operator!=(const ConstIterator& rhs) {
                return mPtr != rhs.mPtr;
            }
            bool operator==(const ConstIterator& rhs) {
                return !(*this != rhs);
            }
            ConstIterator operator+(const int n) {
                ConstIterator copy{*this};
                copy.mPtr += n;
                return copy;
            }
            ConstIterator operator-(const int n) {
                ConstIterator copy{*this};
                copy.mPtr -= n;
                return copy;
            }
            std::ptrdiff_t operator-(const ConstIterator& rhs) {
                return mPtr - rhs.mPtr;
            }
            bool operator<(const ConstIterator& rhs) {
                return mPtr < rhs.mPtr;
            }
            ConstIterator& operator--() {
                --mPtr;
                return *this;
            }
        private:
            const ValueType* mPtr{nullptr};
        };
        class Iterator final {
        public:
            using value_type = ValueType;
            using difference_type = std::ptrdiff_t;
            using iterator_category = std::random_access_iterator_tag;
            using pointer = ValueType*;
            using reference = ValueType&;
            
            Iterator(ValueType* p = nullptr) : mPtr{p} {}
            Iterator& operator++() {
                ++mPtr; 
                return *this;
            }
            Iterator operator++(int) {
                Iterator copy{*this};
                ++mPtr;
                return copy;
            }
            ValueType& operator*() {
                return *mPtr;
            }
            
            bool operator!=(const Iterator& rhs) {
                return mPtr != rhs.mPtr;
            }
            bool operator==(const Iterator& rhs) {
                return !(*this != rhs);
            }
            Iterator operator+(const int n) {
                Iterator copy{*this};
                copy.mPtr += n;
                return copy;
            }
            Iterator operator-(const int n) {
                Iterator copy{*this};
                copy.mPtr -= n;
                return copy;
            }
            std::ptrdiff_t operator-(const Iterator& rhs) {
                return mPtr - rhs.mPtr;
            }
            bool operator<(const Iterator& rhs) {
                return mPtr < rhs.mPtr;
            }
            Iterator& operator--() {
                --mPtr;
                return *this;
            }
        private:
            ValueType* mPtr{nullptr};
        };
        
        Vector() = default;
        
        explicit Vector(const SizeType size) : 
            mSize{size}, mCapacity{size}, mData{std::make_unique<ValueType[]>(size)} {
            assert(mData);
        }
        
        explicit Vector(const SizeType size, const ValueType& value) : 
            mSize{size}, mCapacity{size}, mData{std::make_unique<ValueType[]>(size)} {
            assert(mData);
            std::fill(&mData[0], &mData[0] + mSize, value);
        }
        
        Vector(const std::initializer_list<ValueType>& ilist) :
            mSize{ilist.size()}, mCapacity{ilist.size()}, mData{std::make_unique<ValueType[]>(ilist.size())} {
            assert(mData);
            FProg::copy(ilist, mData);
        }
        
        Vector(const Vector& other) : 
            mSize{other.mSize}, mCapacity{other.mCapacity}, mData{std::make_unique<ValueType[]>(other.mSize)} {
            FProg::copy(other, mData);
        }
        
        Vector& operator=(const Vector& rhs) {
            Vector<ValueType> copy{rhs};
            swap(copy);
            return *this;
        }
        
        Vector(Vector&& other) {
            swap(other);
        }
        
        Vector& operator=(Vector&& rhs) {
            swap(rhs);
            return *this;
        }
        
        ~Vector() = default;
        
        ConstIterator begin() const {
            return ConstIterator{&mData[0]};
        }
        
        ConstIterator end() const {
            return ConstIterator{&mData[mSize - 1] + 1};
        }

        Iterator begin() {
            return Iterator{&mData[0]};
        }
        
        Iterator end() {
            return Iterator{&mData[mSize - 1] + 1};
        }
        
        SizeType size() const {return mSize;}
        SizeType capacity() const {return mCapacity;}
        
        ValueType& operator[](const SizeType index) {
            assert(mData); 
            assert(index < mSize); 
            return mData[index];
        }
        const ValueType& operator[](const SizeType index) const {
            assert(mData); 
            assert(index < mSize); 
            return mData[index];
        }
        
        void swap(Vector& other) {
            using std::swap;
            swap(mSize, other.mSize);
            swap(mCapacity, other.mCapacity);
            swap(mData, other.mData);
        }
        
        void push_back(const ValueType& v) {
            if (mSize >= mCapacity) {
                reserve(2 * (mSize + 1));
            }
            assert(mSize < mCapacity);
            mData[mSize++] = v;
        }
        
        void reserve(SizeType count) {
            if (count <= mCapacity)
                return;
            assert(count > mCapacity);
            
            auto copy = std::make_unique<ValueType[]>(count);
            std::copy(&mData[0], &mData[0] + mSize, &copy[0]);
            
            using std::swap;
            swap(mData, copy);
            swap(mCapacity, count);
        }
    private:
        SizeType mSize{0};
        SizeType mCapacity{0};
//        std::unique_ptr<ValueType[]> mData;
        FProg::propagate_const<std::unique_ptr<ValueType[]>> mData;
    };
    template<typename T>
    void swap(Vector<T>& a, Vector<T>& b) {
        a.swap(b);
    }
}
