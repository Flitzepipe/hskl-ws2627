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

#include <iostream>
#include <memory>

#include "point61.h"

//[foo
void foo(const Point* p) { // <> _Roher_ Zeiger bedeutet: Benutzung *ohne* Lebensdauerverlängerung
    if (p) {
        std::cout << __PRETTY_FUNCTION__ << " " << *p << std::endl; //-
    }
}
void foo(const Point& p) { // <> Reine Benutzung: besser als oben.
    std::cout << __PRETTY_FUNCTION__ << " " << p << std::endl; //-
}
//]
//[A
class A
{
public:
    A(std::shared_ptr<Point> p) : // <> Intelligenter Zeiger (per-value -> Kopie) mit geteilter Eigentümerschaft als Parameter bringt zum Ausdruck, dass die Lebensdauer durch diesen Funktionsaufruf verlängert wird
        mPoint{std::move(p)} { // <> `p` ist schon eine Kopie (s.a. Aussage der Parameterliste), daher ist eine weitere Kopie unnötig
        if (mPoint) { // <> checked-pointer Idiom
            std::cout << __PRETTY_FUNCTION__ << " " << *mPoint << std::endl; //-
        }
    }
    ~A() {
        if (mPoint) {
            std::cout << __PRETTY_FUNCTION__ << " " << *mPoint << std::endl; //-
        }
    }
    void setPoint(std::shared_ptr<Point> p) { // <> wie oben: Verlängerung der Lebensdauer
        if (p) {
            std::cout << __PRETTY_FUNCTION__ << " " << *p << std::endl; //-
            mPoint = std::move(p); // <> ggf. auch Freigabe des Zielobjektes: `p` ist schon eine Kopie, daher eine weitere Kopie unnötig (s.a. Aussage der Parameterliste)
        }
    }
private:
    std::shared_ptr<Point> mPoint;
};
//]
//[main1 -use -share2
int main()
{
    //[share1
    const std::shared_ptr<Point> p1{std::make_shared<Point>()}; // <> Erzeugung eines Freispeicherobjekts `Point` und Kapselung des rohen Zeigers in einem intelligenten Zeiger mit *geteiltes* Eigentümerschaft
    std::cout << *p1 << std::endl; //-
    {
        A a(p1); // <> Das Objekt `a` erhält *zusätzlich* die Eigentümerschaft über `p1`
    }
    //]
    //[use
    foo(p1.get()); // <> Übergabe des _rohen_ Zeigers zur Benutzung
    foo(*p1); // <> Besser!
    //]
    //[share2
    A b(p1);
    {
        const auto p2{std::make_shared<Point>()}; // <> Automatische Typinferenz ist sinnvoll bei der Wiederholung von komplizierten Typangaben
        b.setPoint(p2); // <> Die Lebensdauer des Zielobjektes von `p2` wird über das Blockende verlängert.
    }
    //]
}
//]
