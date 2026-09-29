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
#include <initializer_list>
#include <cassert>

//[class1 -a
//[class
template<typename T>
class List final
{
private:
    class ListNode final // <> Das _geschachtelte_ Klassen-_Template_ (gleiche Parametrierung mit Template-Typ-Parameter `T`)
    {
        friend class List; // <> Die umgebende, generische Klasse `List<T>` (gleiche Parametrierung) ist `friend`: notwendig für Zugriff auf das Datenelement `mNext`.
    public:
        ListNode(const T& v) : mValue(v) {}
    private:
        std::unique_ptr<ListNode> mNext;
        T mValue;
    };
public:
    List() {}
    //[a
    List(const List& other) {
        ListNode* node = other.mHead.get();
        while(node) {
            *this += node->mValue;
            node = node->mNext.get();
        }
    }

    List(List&& other) {
        swap(other);
    }

    List& operator=(List rhs) {
        swap(rhs);
        return *this;
    }

    List& operator=(List&& rhs) {
        swap(rhs);
        return *this;
    }

    List(const std::initializer_list<T>& ilist) {
        for(const T& v: ilist) {
            *this += v;
        }
    }

    List& operator+=(const T& value) {
        if (mTail) {
            assert(!mTail->mNext);
            mTail->mNext = std::make_unique<ListNode>(value);
            mTail = mTail->mNext.get();
        }
        else {
            mHead = std::make_unique<ListNode>(value);
            mTail = mHead.get();
        }
        mSize += 1;
        return *this;
    }

    bool empty() const {
        return (mSize == 0);
    }

    void clear() {
        List<T> emptyList;
        swap(emptyList);
    }

    T& front() {
        assert(mHead);
        return mHead->mValue;
    }

    const T& front() const {
        assert(mHead);
        return mHead->mValue;
    }

    void pop_front() {
        assert(mHead);
        mHead = std::move(mHead->mNext);
        mSize -= 1;
        if (!mHead) {
            mTail = nullptr;
        }
    }

    void swap(List<T>& o) {
        using std::swap;
        swap(mHead, o.mHead);
        swap(mTail, o.mTail);
        swap(mSize, o.mSize);
    }
    //]
    size_t size() const {
        return mSize;
    }
private:
    std::unique_ptr<ListNode> mHead; // <> `ListNode` ist hier schon ein Template parameteriert mit `T`
    List<T>::ListNode* mTail = nullptr; // <> Hier kann man auch als DT einfach `ListNode` (s.o.) schreiben.
    size_t mSize = 0;
};
//]
//]

template<typename T>
void swap(List<T>& a, List<T>& b)
{
    a.swap(b);
}
