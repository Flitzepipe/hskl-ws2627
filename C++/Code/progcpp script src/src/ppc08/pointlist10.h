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
    const Point mValue;
    PointListNode* mNext{nullptr};
};
//]
//[PointList -a
class PointList
{
public:
    PointList() = default; // <> Der synthetisierte Standardkonstruktor ist ausreichend. Wegen des deklarierten Kopierkonstruktors muss er allerdings wieder _eingeschaltet_ werden.
    PointList(const PointList& other) = delete; // <> Ein _flaches_ Kopieren ist *falsch*: aus Aufwandsgründen deswegen hier _verboten_.
    PointList& operator=(const PointList& rhs) = delete; // <> Ein _flaches_ Kopierzuweisen ist *falsch*: deswegen hier _verbieten_.
    ~PointList(); // <> _Tiefes Löschen_ ist erforderlich.
    //[a
    PointList& operator+=(const Point& point); // <> Anfügeoperation: fügt einen Listenknoten mit dem Wert `point` an das Ende an.
    size_t size() const; // <> Bestimmen der Knotenanzahl
private:
    PointListNode* mHead{nullptr}; // <> Ein _roher_ Zeiger als Datenelement -> *rule-of-three* beachten!
    //]
};
//]
