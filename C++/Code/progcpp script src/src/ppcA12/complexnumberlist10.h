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

#include <memory>

#include "complexnumber90.h"

class ComplexNumberListNode; // <> Diese Vorwärtsdeklarartion ist notwendig, damit das Datenelement `mHead` deklariert werden kann.

class ComplexNumberList
{
public:
    //[ stdctor
    ComplexNumberList() = default;
    //]
    void swap(ComplexNumberList& other); // <> Vertauschbarkeit

    ComplexNumberList(ComplexNumberList&& other); // <> Verschiebungskonstruktion (Verschiebbarkeit)
    ComplexNumberList& operator=(ComplexNumberList&& rhs); // <> Verschiebungszuweisung (Verschiebbarkeit)

    ComplexNumberList(const ComplexNumberList& other); // <> Kopierkonstruktion (Kopierbarbeit)
    ComplexNumberList& operator=(const ComplexNumberList& rhs); // <> Kopierzuweisung (Kopierbarbeit)

    const ComplexNumber& front() const;
    const ComplexNumber& back() const;

    ComplexNumber& front();
    ComplexNumber& back();
    
    void pop_front();
    void pop_back();

    void push_front(const ComplexNumber& item);
    void push_back(const ComplexNumber& item);

    ComplexNumberList& operator+=(const ComplexNumber& rhs); // <> Dieselbe Funktion wie `push_back()`, allerdings sind Kettenoperationen möglich.
    ComplexNumberList& operator+=(const ComplexNumberList& rhs); // <> Überladene Variante, um eine vollständige Liste am Ende hinzuzufügen.

    size_t size() const;

    void clear();
private:
    std::unique_ptr<ComplexNumberListNode> mHead;
    ComplexNumberListNode* mTail{nullptr};
    size_t mSize{0};
};

void swap(ComplexNumberList& a, ComplexNumberList& b);

ComplexNumberList operator+(const ComplexNumberList& lhs, const ComplexNumberList& rhs); // <> Wenn es den `+=`-Operator gibt, so wird vom Kunden auch der binäre `+`-Operator _erwartet_.
