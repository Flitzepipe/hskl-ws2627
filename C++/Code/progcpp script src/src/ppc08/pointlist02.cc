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

#include "pointlist02.h"

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

//[add
PointList& PointList::operator+=(const Point& point)
{
    if (mHead) { // <> Allgemeiner Fall: nicht-leere Liste
        PointListNode* n{mHead.get()}; // <> *RP* zur Iteration
        assert(n);
        while(n->mNext) {
            n = n->mNext.get();
        }
        assert(!n->mNext); // <> Zusicherung: `n` ist der letzte Knoten
        n->mNext = std::make_unique<PointListNode>(point); // <> Dies ist eine *Verschiebungszuweisung* (`std::make_unique<T>()` liefert einen sog. _R-Wert_).
    }
    else { // <> Spezialfall: leere Liste
        mHead = std::make_unique<PointListNode>(point); // <> Dies ist auch eine Verschienungszuweisung wie oben.
    }
    return *this;
}
//]

size_t PointList::size() const
{
    size_t size{0};
    const PointListNode* node{mHead.get()};
    while(node) {
        size += 1;
        node = node->mNext.get();
    }
    return size;
}

//[access
const Point& PointList::front() const
{
    assert(mHead);
    return mHead->mValue; // <> Ergebnis ist eine `const`-Referenz für das Datenobjekt
}

void PointList::pop_front()
{
    assert(mHead);
    std::unique_ptr<PointListNode> n{std::move(mHead)}; // <> Die Eigentümerschaft des ersten Listenknoten wird in die Variable `n` *verschoben*. Damit auch alle weiteren Listenknoten.
    mHead = std::move(n->mNext); // <> Die Eigentümerschaft des Nachfolgeknotens wird wieder nach `mHead` *verschoben*.
} // <> Der _lokale_ *UP* `n` wird zerstört und damit auch der nicht mehr benötigte, erste Listenknoten.
//]

PointListNode::PointListNode(const Point& point) :
    mValue{point}
{
}
