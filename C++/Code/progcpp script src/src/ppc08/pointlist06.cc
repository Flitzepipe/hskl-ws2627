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

#include "pointlist06.h"

#include <algorithm>
#include <cassert>

#include "math.h"

#include "../lib/simpletest.h"

SIMPLETEST("PointList ctor1"){
    PointList pl;
    if (pl.size() != 0) return false;
    return true;
};

SIMPLETEST("PointList insert1"){
    PointList pl;
    pl += Point();
    if (pl.size() != 1) return false;
    pl += Point();
    if (pl.size() != 2) return false;
    return true;
};

SIMPLETEST("PointList first"){
    PointList pl;
    pl += Point(XCoor{1.1}, YCoor{2.2});
    if (pl.size() != 1) return false;
    const Point& p = pl.front();
    if (!Math::equal(p.getX(), 1.1)) return false;
    if (!Math::equal(p.getY(), 2.2)) return false;
    return true;
};

SIMPLETEST("PointList TakeFirst"){
    PointList pl;
    pl += Point();
    pl += Point(XCoor{1.1}, YCoor{2.2});
    if (pl.size() != 2) return false;
    Point p1 = pl.front();
    pl.pop_front();
    if (pl.size() != 1) return false;
    if (!Math::equal(p1.getX(), 0.0)) return false;
    if (!Math::equal(p1.getY(), 0.0)) return false;
    Point p2 = pl.front();
    pl.pop_front();
    if (pl.size() != 0) return false;
    if (!Math::equal(p2.getX(), 1.1)) return false;
    if (!Math::equal(p2.getY(), 2.2)) return false;
    return true;
};

SIMPLETEST("PointList TakeFirst"){
    PointList pl;
    pl += Point();
    pl += Point(XCoor{1.1}, YCoor{2.2});
    if (pl.size() != 2) return false;

    pl.pop_front();
    pl.pop_front();
    if (pl.size() != 0) return false;

    pl += Point(XCoor{1.2}, YCoor{2.2});
    pl += Point(XCoor{2.2}, YCoor{2.2});

    Point p1 = pl.front();
    pl.pop_front();
    if (pl.size() != 1) return false;
    if (!Math::equal(p1.getX(), 1.2)) return false;
    if (!Math::equal(p1.getY(), 2.2)) return false;
    Point p2 = pl.front();
    pl.pop_front();
    if (pl.size() != 0) return false;
    if (!Math::equal(p2.getX(), 2.2)) return false;
    if (!Math::equal(p2.getY(), 2.2)) return false;
    return true;
};

SIMPLETEST("PointList swap"){
    PointList pl1;
    PointList pl2;
    pl1 += Point(XCoor{1.1}, YCoor{2.2});
    pl1 += Point(XCoor{2.1}, YCoor{2.2});
    if (pl1.size() != 2) return false;

    pl2 += Point();
    if (pl2.size() != 1) return false;

    pl1.swap(pl2);
    if (pl1.size() != 1) return false;
    if (pl2.size() != 2) return false;

    if (!Math::equal(pl1.front().getX(), 0.0)) return false;
    if (!Math::equal(pl1.front().getY(), 0.0)) return false;

    if (!Math::equal(pl2.front().getX(), 1.1)) return false;
    if (!Math::equal(pl2.front().getY(), 2.2)) return false;

    pl2.pop_front();

    if (!Math::equal(pl2.front().getX(), 2.1)) return false;
    if (!Math::equal(pl2.front().getY(), 2.2)) return false;

    return true;
};

SIMPLETEST("PointList swap2"){
    PointList pl1;
    PointList pl2;
    pl1 += Point(XCoor{1.1}, YCoor{2.2});
    pl1 += Point(XCoor{2.1}, YCoor{2.2});
    if (pl1.size() != 2) return false;

    pl2 += Point();
    if (pl2.size() != 1) return false;

    swap(pl1, pl2);

    if (pl1.size() != 1) return false;
    if (pl2.size() != 2) return false;

    if (!Math::equal(pl1.front().getX(), 0.0)) return false;
    if (!Math::equal(pl1.front().getY(), 0.0)) return false;

    if (!Math::equal(pl2.front().getX(), 1.1)) return false;
    if (!Math::equal(pl2.front().getY(), 2.2)) return false;

    pl2.pop_front();

    if (!Math::equal(pl2.front().getX(), 2.1)) return false;
    if (!Math::equal(pl2.front().getY(), 2.2)) return false;

    return true;
};

SIMPLETEST("PointList move-ctor"){
    PointList pl1;
    pl1 += Point{XCoor{1.0}, YCoor{2.0}};
    pl1 += Point();

    if (pl1.size() != 2) return false;

    PointList pl2 = std::move(pl1);
    if (pl2.size() != 2) return false;
    if (pl1.size() != 0) return false;

    if (!Math::equal(pl2.front().getX(), 1.0)) return false;
    if (!Math::equal(pl2.front().getY(), 2.0)) return false;

    return true;
};

SIMPLETEST("PointList move-assign"){
    PointList pl1;
    pl1 += Point{XCoor{1.0}, YCoor{2.0}};
    pl1 += Point();

    if (pl1.size() != 2) return false;

    PointList pl2;
    pl2 = std::move(pl1);
    if (pl2.size() != 2) return false;
    if (pl1.size() != 0) return false;

    if (!Math::equal(pl2.front().getX(), 1.0)) return false;
    if (!Math::equal(pl2.front().getY(), 2.0)) return false;

    return true;
};

SIMPLETEST("PointList copy-ctor"){
    PointList pl1;
    pl1 += Point{XCoor{1.0}, YCoor{2.0}};
    pl1 += Point();

    if (pl1.size() != 2) return false;

    PointList pl2 = pl1;
    if (pl2.size() != 2) return false;
    if (pl1.size() != 2) return false;

    if (!Math::equal(pl2.front().getX(), 1.0)) return false;
    if (!Math::equal(pl2.front().getY(), 2.0)) return false;

    return true;
};

SIMPLETEST("PointList copy-assign"){
    PointList pl1;
    pl1 += Point{XCoor{1.0}, YCoor{2.0}};
    pl1 += Point();

    if (pl1.size() != 2) return false;

    PointList pl2;
    pl2 = pl1;
    if (pl2.size() != 2) return false;
    if (pl1.size() != 2) return false;

    if (!Math::equal(pl2.front().getX(), 1.0)) return false;
    if (!Math::equal(pl2.front().getY(), 2.0)) return false;

    return true;
};

class PointListNode
{
public:
    PointListNode(const Point& point);
    const Point mValue;
    std::unique_ptr<PointListNode> mNext;
};

PointList::PointList()
{
}

PointList::~PointList()
{
}
//[copyable
PointList::PointList(const PointList& other) // <> Die Datenelemente werden durch `in-class`-Initialisierer als Zustand _leere_ Liste initialisiert
{
    const PointListNode* n = other.mHead.get(); // <> Ein _roher_ Zeiger (RP) als Iterator
    while(n) {
        *this += n->mValue; // <> Um Code-Duplizierung zu vermeiden, wird der `+=`-Operator eingesetzt.
        n = n->mNext.get();
    }
}

PointList& PointList::operator=(const PointList& rhs) // <> Die Realisierung des Kopierzuweisungsoperators nach dem *copy-swap*-Idiom
{
    PointList copy(rhs); // <> Zuerst eine Kopier des `rhs`-Objektes anfertigen -> Kopierkonstruktor
    swap(copy); // <> Den aktuellen Zustand mit dem der Kopie des `rhs`-Objektes vertauschen
    return *this; // <> Kettenzuweisungen ermöglichen
} // <> Die lokale Variable `copy` wird zerstört -> Destruktor
//]
PointList& PointList::operator=(PointList&& rhs)
{
    swap(rhs);
    return *this;
}

PointList::PointList(PointList&& other)
{
    swap(other);
}

PointList& PointList::operator+=(const Point& point)
{
    if (mTail) {
        mTail->mNext = std::make_unique<PointListNode>(point);
        mTail = mTail->mNext.get();
    }
    else {
        mHead = std::make_unique<PointListNode>(point);
        mTail = mHead.get();
    }
    mSize += 1;
    return *this;
}

size_t PointList::size() const
{
    return mSize;
}

const Point& PointList::front() const
{
    assert(mHead);
    return mHead->mValue;
}

void PointList::pop_front()
{
    assert(mHead);
    mHead = std::move(mHead->mNext);
    mSize -= 1;
    if (!mHead) {
        mTail = nullptr;
    }
}

void PointList::swap(PointList& other)
{
    using std::swap;
    swap(mHead, other.mHead);
    swap(mTail, other.mTail);
    swap(mSize, other.mSize);
}

PointListNode::PointListNode(const Point& point) :
    mValue{point}
{
}

void swap(PointList& a, PointList& b)
{
    a.swap(b);
}
