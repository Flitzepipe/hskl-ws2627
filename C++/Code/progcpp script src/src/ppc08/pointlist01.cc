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

#include "pointlist01.h"

#include <algorithm>
#include <cassert>

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

//[add
PointList& PointList::operator+=(const Point& point)
{
    auto node{std::make_unique<PointListNode>(point)}; // <> Ein neuer Knoten wird erzeugt und die lokale Zeigervariable `node` ist zunächst _alleiniger_ Eigentümer.

    if (mHead) {
        PointListNode* n{mHead.get()}; // <> `n` ist ein _roher_ Zeiger zur Iteration _ohne_ Eigentümerschaft.
        assert(n);
        while(n->mNext) {
            n = n->mNext.get();
        }
        assert(!n->mNext); // <> `n` ist damit ein Zeiger auf den letzten Knoten.
        n->mNext = std::move(node); // <> Die unikate Eigentümerschaft von `node` kann man nur *verschieben*! `node` ist anschließend leer.
    }
    else { // <> Spezialfall: leere Liste
        assert(!mHead);
        mHead = std::move(node); // <> Die unikate Eigentümerschaft von `node` kann man nur nach `mHead` *verschieben*. Damit hat das Hüllobjekt die (unikate) Eigentümerschaft übernommen. `node` ist anschließend leer.
    }
    assert(!node); // <> `node` _muss_ die Eigentümerschaft abgegeben haben.
    return *this;
}
//]
//[size
size_t PointList::size() const
{
    size_t size{0};
    const PointListNode* n{mHead.get()}; // <> Hier ist `n` ein _roher_ Zeiger zur Iteration (Iterator) _ohne_ Eigentümerschaft.
    while(n) {
        size += 1;
        n = n->mNext.get(); // <> Der *UP* behält die Eigentümerschaft!
    }
    return size;
}
//]
PointListNode::PointListNode(const Point& point) :
    mValue{point}
{
}
