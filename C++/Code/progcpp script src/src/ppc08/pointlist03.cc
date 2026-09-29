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

#include "pointlist03.h"

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
//[a
PointList& PointList::operator+=(const Point& point)
{
    if (mTail) {
        mTail->mNext = std::make_unique<PointListNode>(point); // <> Ein neuer Listenknoten wird erzeugt und die Eigentümerschaft direkt an den bisherigen letzten Listenknoten abgegeben
        mTail = mTail->mNext.get(); // <> Aktualisierung des speziellen Iterators (RP)
    }
    else {
        mHead = std::make_unique<PointListNode>(point); // <> wie oben
        mTail = mHead.get();
    }
    mSize += 1;
    return *this;
}
//]
size_t PointList::size() const
{
    return mSize;
}

const Point& PointList::front() const
{
    assert(mHead);
    return mHead->mValue;
}
//[a
void PointList::pop_front()
{
    assert(mHead);
    mHead = std::move(mHead->mNext); // <> kürzere Notation: Verschieben des zweiten Kontens an den Anfang, der ursprüngliche Anfang wird dabei gelöscht.
    mSize -= 1;
    if (!mHead) { // <> Spezialfall: es entsteht eine leere Liste: `mTail` zeigt damit auf das _Nichts_
        mTail = nullptr;
        assert(mSize == 0);
    }
}
//]
PointListNode::PointListNode(const Point& point) :
    mValue{point}
{
}
