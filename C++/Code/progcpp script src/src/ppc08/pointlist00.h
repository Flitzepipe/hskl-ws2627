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

#include "point70.h"

//[PointListNode
class PointListNode
{
public:
    explicit PointListNode(const Point& point);
    const Point mValue; // <> Initialisierung über den allegmeinen Konstruktor; der `Point`-Wert eines Listenknotens kann nachträglich nicht mehr modifiziert werden.
    PointListNode* mNext{nullptr}; // <> Der _rohe_ Zeiger (*RP*) auf den nächsten Listenknoten.
};
//]
//[PointList
class PointList // <> *Achtung*: diese Realisierung ist in *mehrfacher* Hinsicht *falsch* (s.a. _rule-of-three_)!
{
public:
    PointList& operator+=(const Point& point); // <> Anfügeoperation: fügt einen Listenknoten mit dem Wert `point` und Typ `Point` an das Ende der Liste an.
    size_t size() const; // <> Bestimmen der Knotenanzahl
private:
    PointListNode* mHead{nullptr}; // <> Der Initialzustand wir durch diesen _in-class-initializer_ hergestellt -> kein spezieller Konstruktor erfoderlich.
};
//]
