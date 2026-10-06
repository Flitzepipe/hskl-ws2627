/*
 *
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

#if __has_include("../ppc.h")
# include "../ppc.h"
#endif

#include <iostream>

#ifndef _MSC_VER
# pragma GCC diagnostic ignored "-Wunused-value"
#endif

//[classes
class Base
{
public:
    int mBase;
    void nonvirtualfunction() const;
    virtual void virtualfunction() const;
};

class Derived : public Base
{
public:
    int mDerived;
    void nonvirtualfunction() const; // <> Die `override`-Qualifizierung ist bei _nicht-virtuellen_ Funktionen nicht zulässig.
    virtual void virtualfunction() const override;
};
//]
//[functions
void foo(Base x) // <> Parameterübernahme _per-value_ bewirkt `Objektsclicing`, weil eine _Kopierkonstruktion_ stattfindet
{
    x.mBase;
//    x.mDerived; // <> Wegen `Slicing` nicht vorhandenes Datenelement.
    x.nonvirtualfunction();
    x.virtualfunction();
}
void bar(const Base& x) // <> Parameterübernahme _per-reference_  vermeidet `Slicing`, denn `x` ist hier nur ein weiterer Name (statischer Typ: `Base`) für das Objekt des Aufrufers
{
    x.mBase;
//    x.mDerived; // <> Über den _statischen_ Type nicht erreichbares Datenelement
    x.nonvirtualfunction();
    x.virtualfunction();
}
//]
//[functionptr
void fox(const Base* x)
{
    x->nonvirtualfunction();
    x->virtualfunction();
}
//]
//[mainptr2 -c -a -p
//[mainptr -c -a -p2
//[mainparam -c -p -p2
//[mainslice -b -p -p2
//[mainref -a -p -p2
//[main
int main()
{
    //[c
    //[b
    Derived derived; // <> Ein `Derived`-Objekt wird in der Variable `derived` instanziiert.
    Base base; // <> Eine Variable des Typs `Base` wird definiert, damit wird ein Objekt dieses Typs erzeugt.
    Base& base2 = derived; // <> Hier wird `base2` als ein weiterer *Name* für das Objekt der Variable `derived` deklariert.
    base2.nonvirtualfunction();
    base2.virtualfunction();
    //]
    //]
    //[p2
    Base* bPtr = &derived;
    bPtr->nonvirtualfunction();
    bPtr->virtualfunction();
    //]
    //[a
    //[c
    base = derived; // <> Dem Objekt der Variablen `base` soll das Objekt der Variablen `derived` kopier-zugewiesen werden! *Achtung*: Hier passiert das sog. _slicing_: nur der `Base`-Anteil von `derived` wird zugewiesen!
    //]
    //[b
    foo(derived); // <> Bei Parameterübergabe _per-value_ kommt es auch zu einem *Slicing*, denn hier findet eine _Kopierkonstruktion_ in die Parametervalue statt.
    bar(derived); // <> Die Parameterübergabe _per-reference_ vermeidet das _Slicing_.
    //]
    //]
    //[p
    fox(&derived);
    //]
}
//]
//]
//]
//]
//]
//]
//[defs
void Base::nonvirtualfunction() const {
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

void Base::virtualfunction() const {
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}


void Derived::nonvirtualfunction() const {
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

void Derived::virtualfunction() const {
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}
//]
