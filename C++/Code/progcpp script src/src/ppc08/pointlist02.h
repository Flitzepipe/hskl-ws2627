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

class PointListNode
{
public:
    PointListNode(const Point& point);
    const Point mValue;
    std::unique_ptr<PointListNode> mNext;
};

//[PointList
class PointList
{
public:
    PointList() = default; // <> Das explizite Einschalten des synthetisierten Standard-Konstruktors ist notwendig wegen der Deklaration anderer Konstruktoren (Kopierkonstruktor)

    PointList(const PointList& other) = delete; // <> Deklaration zum Verbot der Kopierkonstruktors
    PointList& operator=(const PointList& rhs) = delete; // <> Deklaration zum Verbot des Kopierzuweisungsoperators

    PointList& operator+=(const Point& point);
    size_t size() const;

    const Point& front() const; // <> Zugriff auf die Daten des ersten Listenknoten. Annahme: Liste ist nicht leer!
    void pop_front(); // <> Entfernen des ersten Listenknoten. Annahme: Liste ist nicht leer!
private:
    std::unique_ptr<PointListNode> mHead;
};
//]
