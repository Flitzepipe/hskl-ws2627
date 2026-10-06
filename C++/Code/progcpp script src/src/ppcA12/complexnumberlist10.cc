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

#include "complexnumberlist10.h"

#include "../lib/simpletest.h"
#include "math.h"

//[impl -tests
//[tests
SIMPLETEST("ctor")
{
    ComplexNumberList cnl;

    if (cnl.size() != 0) return false;

    return true;
};

SIMPLETEST("back1")
{
    ComplexNumberList cnl;

    cnl.push_back({1.0, 2.0});

    if (cnl.size() != 1) return false;

    if (!Math::equal(cnl.front().real(), 1.0)) return false;
    if (!Math::equal(cnl.front().imag(), 2.0)) return false;

    return true;
};

SIMPLETEST("back2")
{
    ComplexNumberList cnl;

    cnl.push_back({1.0, 2.0});
    cnl.push_back({2.0, 3.0});

    if (cnl.size() != 2) return false;

    if (!Math::equal(cnl.front().real(), 1.0)) return false;
    if (!Math::equal(cnl.front().imag(), 2.0)) return false;

    if (!Math::equal(cnl.back().real(), 2.0)) return false;
    if (!Math::equal(cnl.back().imag(), 3.0)) return false;

    return true;
};

SIMPLETEST("back3")
{
    ComplexNumberList cnl;

    cnl.push_back({1.0, 2.0});

    if (cnl.size() != 1) return false;

    cnl.pop_back();

    if (cnl.size() != 0) return false;

    return true;
};


SIMPLETEST("back4")
{
    ComplexNumberList cnl;

    cnl.push_back({1.0, 2.0});
    cnl.push_back({2.0, 3.0});

    if (cnl.size() != 2) return false;

    if (!Math::equal(cnl.front().real(), 1.0)) return false;
    if (!Math::equal(cnl.front().imag(), 2.0)) return false;

    if (!Math::equal(cnl.back().real(), 2.0)) return false;
    if (!Math::equal(cnl.back().imag(), 3.0)) return false;

    cnl.pop_back();
    if (cnl.size() != 1) return false;

    if (!Math::equal(cnl.front().real(), 1.0)) return false;
    if (!Math::equal(cnl.front().imag(), 2.0)) return false;

    if (!Math::equal(cnl.back().real(), 1.0)) return false;
    if (!Math::equal(cnl.back().imag(), 2.0)) return false;

    cnl.pop_back();
    if (cnl.size() != 0) return false;
    return true;
};

SIMPLETEST("front1")
{
    ComplexNumberList cnl;

    cnl.push_front({1.0, 2.0});

    if (cnl.size() != 1) return false;

    if (!Math::equal(cnl.back().real(), 1.0)) return false;
    if (!Math::equal(cnl.back().imag(), 2.0)) return false;

    return true;
};

SIMPLETEST("front2")
{
    ComplexNumberList cnl;

    cnl.push_front({1.0, 2.0});
    cnl.push_front({2.0, 3.0});

    if (cnl.size() != 2) return false;

    if (!Math::equal(cnl.back().real(), 1.0)) return false;
    if (!Math::equal(cnl.back().imag(), 2.0)) return false;

    if (!Math::equal(cnl.front().real(), 2.0)) return false;
    if (!Math::equal(cnl.front().imag(), 3.0)) return false;

    return true;
};

SIMPLETEST("front3")
{
    ComplexNumberList cnl;

    cnl.push_front({1.0, 2.0});

    if (cnl.size() != 1) return false;

    cnl.pop_front();

    if (cnl.size() != 0) return false;

    return true;
};

SIMPLETEST("front4")
{
    ComplexNumberList cnl;

    cnl.push_front({1.0, 2.0});
    cnl.push_front({2.0, 3.0});

    if (cnl.size() != 2) return false;

    if (!Math::equal(cnl.back().real(), 1.0)) return false;
    if (!Math::equal(cnl.back().imag(), 2.0)) return false;

    if (!Math::equal(cnl.front().real(), 2.0)) return false;
    if (!Math::equal(cnl.front().imag(), 3.0)) return false;

    cnl.pop_front();
    if (cnl.size() != 1) return false;

    if (!Math::equal(cnl.front().real(), 1.0)) return false;
    if (!Math::equal(cnl.front().imag(), 2.0)) return false;

    if (!Math::equal(cnl.back().real(), 1.0)) return false;
    if (!Math::equal(cnl.back().imag(), 2.0)) return false;

    cnl.pop_front();
    if (cnl.size() != 0) return false;
    return true;
};

SIMPLETEST("swap")
{
    ComplexNumberList cnl1;
    ComplexNumberList cnl2;

    cnl1.push_front({1.0, 2.0});
    cnl1.push_front({2.0, 3.0});

    swap(cnl1, cnl2);

    if (cnl1.size() != 0) return false;
    if (cnl2.size() != 2) return false;

    return true;
};

SIMPLETEST("cctor")
{
    ComplexNumberList cnl1;

    cnl1.push_front({1.0, 2.0});
    cnl1.push_front({2.0, 3.0});

    ComplexNumberList cnl2{cnl1};

    if (cnl2.size() != 2) return false;

    return true;
};

SIMPLETEST("op=")
{
    ComplexNumberList cnl1;

    cnl1.push_front({1.0, 2.0});
    cnl1.push_front({2.0, 3.0});

    ComplexNumberList cnl2;

    cnl2.push_back({3.0, 4.0});
    cnl2.push_back({4.0, 5.0});
    cnl2.push_back({5.0, 6.0});

    if (cnl2.size() != 3) return false;

    cnl2 = cnl1;

    if (cnl2.size() != 2) return false;

    return true;
};

SIMPLETEST("mctor")
{
    ComplexNumberList cnl{ComplexNumberList() += ComplexNumber{1.0, 2.0}};

    if (cnl.size() != 1) return false;

    return true;
};

SIMPLETEST("mop=")
{
    ComplexNumberList cnl;

    cnl = (ComplexNumberList() += ComplexNumber{1.0, 2.0});

    if (cnl.size() != 1) return false;

    return true;
};

SIMPLETEST("clear")
{
    ComplexNumberList cnl1;

    cnl1.push_front({1.0, 2.0});
    cnl1.push_front({2.0, 3.0});

    if (cnl1.size() != 2) return false;

    cnl1.clear();

    if (cnl1.size() != 0) return false;
    return true;
};

SIMPLETEST("op+=1")
{
    ComplexNumberList cnl1;

    cnl1 += ComplexNumber{1.0, 2.0};
    cnl1 += ComplexNumber{2.0, 3.0};

    if (cnl1.size() != 2) return false;

    return true;
};

SIMPLETEST("op+=2")
{
    ComplexNumberList cnl1;

    cnl1 += ComplexNumber{1.0, 2.0};
    cnl1 += ComplexNumber{2.0, 3.0};

    ComplexNumberList cnl2;
    cnl2 += cnl1;

    if (cnl2.size() != 2) return false;

    return true;
};

SIMPLETEST("op+")
{
    ComplexNumberList cnl1;

    cnl1 += ComplexNumber{1.0, 2.0};
    cnl1 += ComplexNumber{2.0, 3.0};

    ComplexNumberList cnl2;
    cnl2 += ComplexNumber{3.0, 4.0};
    cnl2 += ComplexNumber{4.0, 5.0};

    ComplexNumberList cnl3;

    cnl3 = cnl1 + cnl2;

    if (cnl3.size() != 4) return false;

    return true;
};
//]

//[cnln
class ComplexNumberListNode
{
public:
    ComplexNumberListNode(const ComplexNumber& v, ComplexNumberListNode* previous = nullptr) :
        mValue{v}, mPrevious{previous} // <> Initialisierungsliste
    {}
    ComplexNumber mValue;
    ComplexNumberListNode* mPrevious{nullptr}; // <> in-class-initializer für primitive Datentypen
    std::unique_ptr<ComplexNumberListNode> mNext;
};
//]

//[swappable
void ComplexNumberList::swap(ComplexNumberList& other)
{
    using std::swap; // <> Das standardisierte Idiom für die Elementfunktion `swap()`
    swap(mHead, other.mHead); // <> Alle Datenelemente werden in dieser Elementfunktion behandelt.
    swap(mTail, other.mTail);
    swap(mSize, other.mSize);
}
//]
//[moveable
ComplexNumberList::ComplexNumberList(ComplexNumberList&& other) // <> Der Verschiebungskonstruktor nach dem _empty-swap_-Idiom. *Wichtig*: die Initialisierung der Datenelemente findet über die _in-class_-Initialisierer statt.
{
    swap(other);
}

ComplexNumberList& ComplexNumberList::operator=(ComplexNumberList&& rhs) // <> Der Verschiebungszuweisungsoperator nach dem _swap_-Idiom: dies ergibt eine verzögerte Destruktion am Ende der Lebenszeit von `rhs`.
{
    swap(rhs);
    return *this;
}
//]
//[mutator
void ComplexNumberList::push_back(const ComplexNumber& item)
{
    if (mTail) { // <> allgemeiner Fall: nicht-leere Liste
        assert(!mTail->mNext);
        mTail->mNext = std::make_unique<ComplexNumberListNode>(item, mTail);
        mTail = mTail->mNext.get();
    }
    else { // <> Spezialfall: leere Liste
        assert(!mHead);
        mHead = std::make_unique<ComplexNumberListNode>(item);
        mTail = mHead.get();
    }
    mSize += 1;
}

ComplexNumberList& ComplexNumberList::operator+=(const ComplexNumber& rhs)
{
    push_back(rhs); // <> Delegation
    return *this;
}

ComplexNumberList& ComplexNumberList::operator+=(const ComplexNumberList& rhs)
{
    const ComplexNumberListNode* node = rhs.mHead.get(); // <> `node` ist der Iterator (hoher Zeiger: Benutzungsrelation)
    while(node) {
        assert(node);
        push_back(node->mValue);
        node = node->mNext.get();
    }
    return *this;
}

void ComplexNumberList::push_front(const ComplexNumber& item)
{
    if (mHead) {
        auto n = std::move(mHead);
        mHead = std::make_unique<ComplexNumberListNode>(item);
        mHead->mNext = std::move(n);
        mHead->mNext->mPrevious = mHead.get();
    }
    else {
        assert(!mTail); // <> Spezialfall: leere Liste
        mHead = std::make_unique<ComplexNumberListNode>(item);
        mTail = mHead.get();
    }
    mSize += 1;
}
//]
//[copyable
ComplexNumberList::ComplexNumberList(const ComplexNumberList& other) // <> die `in-class-initializer` erzeugen einen _leeren_ Zustand
{
    *this +=(other); // <> Erspart die Code-Duplizierung
}

ComplexNumberList& ComplexNumberList::operator=(const ComplexNumberList& rhs) // <> `copy-swap`-Idiom
{
    ComplexNumberList copy(rhs);
    swap(copy);
    return *this;
}
//]
//[getter
const ComplexNumber& ComplexNumberList::front() const
{
    assert(mSize > 0);
    assert(mHead);
    return mHead->mValue;
}

const ComplexNumber& ComplexNumberList::back() const
{
    assert(mSize > 0);
    assert(mTail);
    return mTail->mValue;
}
//]
//[mutator2
ComplexNumber& ComplexNumberList::front() // <> Wird eine non-const-Referenz zurück geliefert, ist diese Funktion ein Mutator
{
    assert(mSize > 0);
    assert(mHead);
    return mHead->mValue;
}

ComplexNumber& ComplexNumberList::back() // <> Wird eine non-const-Referenz zurück geliefert, ist diese Funktion ein Mutator
{
    assert(mSize > 0);
    assert(mTail);
    return mTail->mValue;
}
//]
//[mutator
void ComplexNumberList::pop_front()
{
    assert(mSize > 0);
    assert(mHead);

    if (mHead->mNext) {
        mHead = std::move(mHead->mNext); // <> Der *UP* auf den ersten Knoten wird durch den *UP* des zweiten Knotens ersetzt. Damit wird vom *UP* auch der erste Knoten gelöscht.
    }
    else {
        assert(mTail);
        assert(mSize == 1);
        mHead = nullptr; // <> Damit wird auch der erste Knoten vom _intelligenten Zeiger_ gelöscht.
        mTail = nullptr;
    }
    mSize -= 1;
}

void ComplexNumberList::pop_back()
{
    assert(mSize > 0);
    assert(mTail);

    if (mTail->mPrevious) {
        mTail = mTail->mPrevious;
        mTail->mNext = nullptr; // <> Damit wird auch der letzte Knoten vom _intelligenten Zeiger_ gelöscht.
    }
    else { // <> Das einzige Element wird entfernt
        assert(mHead);
        assert(mSize == 1);
        mHead = nullptr; // <> Damit wird auch der letzte Knoten vom _intelligenten Zeiger_ gelöscht.
        mTail = nullptr;
    }
    mSize -= 1;
}
//]
//[getter
size_t ComplexNumberList::size() const
{
    return mSize;
}
//]
void ComplexNumberList::clear()
{
    ComplexNumberList e; // <> Eine _leere_ Liste
    swap(e); // <> Die Behandlung _aller_ Datenelemente wird an zentraler Stelle in `swap()` durchgeführt.
} // <> Der Destruktor löscht nun aller Elemente

//[swappable
void swap(ComplexNumberList& a, ComplexNumberList& b)
{
    a.swap(b);
}
//]
//[binop
ComplexNumberList operator+(const ComplexNumberList& lhs, const ComplexNumberList& rhs)
{
    return ComplexNumberList(lhs) += rhs; // <> kanonisches Delegationsschema
}
//]
//]
