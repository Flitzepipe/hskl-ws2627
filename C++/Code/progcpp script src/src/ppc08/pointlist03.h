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

class PointListNode; // <> Vorwärts-Deklaration der Klasse `PointListNode`

class PointList
{
public:
    PointList(); // <> Nur notwendig wegen der Vorwärtsdeklaration von `PointListNode`, es erfolgt eine leere Implementierung
    ~PointList(); // <> Nur notwendig wegen der Vorwärtsdeklaration von `PointListNode` (wie oben)

    PointList(const PointList& other) = delete;
    PointList& operator=(const PointList& rhs) = delete;

    PointList& operator+=(const Point& point);
    size_t size() const;

    const Point& front() const;
    void pop_front();
private:
    std::unique_ptr<PointListNode> mHead; // <> Unikate Eigentümerschaft der Listenkonten
    PointListNode* mTail{nullptr}; // <> Roher Zeiger als spezieller Iterator auf den letzten Knoten: keine Eigentümerschaft, nur Benutzung des Objektes
    size_t mSize{0};
};

