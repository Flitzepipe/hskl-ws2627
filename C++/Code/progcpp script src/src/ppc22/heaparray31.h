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

//[begin
namespace std {
    template<typename T>
    T* begin(const std::unique_ptr<T[]>& up) {
        return up.get();
    }
    template<typename T>
    const T* begin(const std::unique_ptr<const T[]>& up) {
        return up.get();
    }
}
//]

//[iterator
template<typename ValueType>
class HeapArrayIterator; // <> Deklaration des Klassen-Templates `HeapArrayIterator` `it` für die folgende Deklaration des Funktions-Templates `operator!=()` notwendig.

template<typename ValueType>
bool operator!=(const HeapArrayIterator<ValueType>& lhs, const HeapArrayIterator<ValueType>& rhs); // <> Diese Deklaration des Funktions-Templates ist für die folgende `friend`-Deklaration erforderlich.

template<typename ValueType>
class HeapArrayIterator final
{
    friend bool operator!= <>(const HeapArrayIterator<ValueType>& lhs, const HeapArrayIterator<ValueType>& rhs); // <> Mit den vorangehenden Deklationen ist nun diese `friend`-Deklaration machbar.
public:
    HeapArrayIterator(const ValueType* p = nullptr) : mPtr(p) {}
    HeapArrayIterator& operator++() { // <> Der Pre-Increment-Operator
        ++mPtr; return *this;
    }
    HeapArrayIterator operator++(int) { // <> Der Post-Increment-Operator
        HeapArrayIterator copy = *this;
        ++mPtr;
        return copy;
    }
    ValueType operator*() { // <> Der Indirektionsoperator
        return *mPtr;
    }
private:
    const ValueType* mPtr = nullptr;
};
template<typename ValueType>
bool operator!=(const HeapArrayIterator<ValueType>& lhs, const HeapArrayIterator<ValueType>& rhs) { // <> Hier reicht ein einfacher Vergleich der rohen Zeigerwerte.
    return lhs.mPtr != rhs.mPtr;
}
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
    explicit HeapArray(size_t size, const ValueType& value) : mSize(size), mData(std::make_unique<ValueType[]>(size)) {
        assert(mData);
        std::fill(mData.get(), mData.get() + size, value);
    }
    
    explicit HeapArray(const std::initializer_list<ValueType>& ilist) :
        mSize(ilist.size()), mData(std::make_unique<ValueType[]>(ilist.size())) {
        assert(mData);
        std::copy(std::begin(ilist), std::end(ilist), mData.get());
    }
    
    HeapArray(const HeapArray& other) : mSize(other.mSize), mData(std::make_unique<ValueType[]>(other.mSize)) {
        std::copy(std::begin(other.mData), std::begin(other.mData) + other.mSize, std::begin(mData)); // <> Durch die Definition einer Funktionstemplate-Überladung für {stdbegin} kann man die _Generizität_ erhöhen, wenngleich dies wegen des dann fehlenden {stdend} (nicht möglich, zu realisieren) nicht vollständig gelingt.
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
    HeapArray() = delete;
    ~HeapArray() = default;
    //[beginend
    HeapArrayIterator<ValueType> begin() const {
        return HeapArrayIterator<ValueType>(&mData[0]); // <> Der rohe Zeiger auf das erste Element wird an den Konstruktor übergeben
    }
    
    HeapArrayIterator<ValueType> end() const {
        return HeapArrayIterator<ValueType>(&mData[mSize - 1] + 1); // <> Der rohe Zeiger auf das nicht-existierende eins-nach-dem-letzten Element wird übergeben.
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
