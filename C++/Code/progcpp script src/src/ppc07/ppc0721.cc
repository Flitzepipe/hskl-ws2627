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
void foo(const Point* p) {
    if (p) {
        std::cout << __PRETTY_FUNCTION__ << " " << *p << std::endl; //-
    }
}

void foo(const Point& p) {
    std::cout << __PRETTY_FUNCTION__ << " " << p << std::endl; //-
}
//]
//[A
class A
{
public:
    A(std::shared_ptr<Point> p) : // <> Intelligenter Zeiger mit geteilter Eigentümerschaft als Parameter bringt zum Ausdruck, dass die Lebensdauer durch diesen Funktionsaufruf verlängert wird
        mPoint{std::move(p)} {
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
            mPoint = std::move(p); // <> ggf. auch Freigabe des Zielobjektes
        }
    }
private:
    std::shared_ptr<Point> mPoint;
};
//]
//[B
class B
{
public:
    B(std::unique_ptr<Point> p) : // <> Klare Aussage: die ungeteilte Eigentümerschaft wir *übernommen*! Der Aufrufer muss(!) die Eigentümerschaft abgeben.
        mPoint{std::move(p)} { // <> Die Eigenntümerschaft wird von `p` nach `mPoint` *verschoben* (sie kann ja nicht kopiert / geteilt werden)
        if (mPoint) {
            std::cout << __PRETTY_FUNCTION__ << " " << *mPoint << std::endl; //-
        }
    }
    ~B() {
        if (mPoint) {
            std::cout << __PRETTY_FUNCTION__ << " " << *mPoint << std::endl; //-
        }
    }
    void setPoint(std::unique_ptr<Point> p) { // <> Wie oben: die Eigentümerschaft wird übernommen.
        if (p) {
            std::cout << __PRETTY_FUNCTION__ << " " << *p << std::endl; //-
        }
        mPoint = std::move(p); // <> Auch hier muss die Eigentümerschaft von `p` nach `mPoint` *verschoben* werden
    }

private:
    std::unique_ptr<Point> mPoint;
};
//]
//[main1 -use -unique2 -promote
int main()
{
    //[unique1
    auto p1{std::make_unique<Point>()}; // <> Hier erhält `p1` die *alleinige* Eigentümerschaft
    std::cout << *p1 << std::endl; //-

    {
        B b{std::move(p1)}; // <> Dies geht nur, wenn die Eigentümerschaft _explizit_ *verschoben* wird!
    }
    //]
    //[use
    if (p1) { // <> Nach dem Verschieben der Eigentümerschaft ist `p1` _leer_ (invalide).
        foo(p1.get()); // <> Benutzung über den rohen Zeiger möglich und sicher wegen Blockstruktur.
        foo(*p1); // <> Besser!
    }
    else {
        std::cout << "p1 invalid" << std::endl;
    }
    //]
    //[unique2
    B b{std::make_unique<Point>()}; // <> Das Objekt `b` übernimmt das `Point`-Objekt
    {
        b.setPoint(std::make_unique<Point>()); // <> Das vorherige Objekt wird gelöscht, das neue Objekt übernommen
    }
    //]
    //[promote
    auto p2{std::make_unique<Point>()}; 
    A a{std::move(p2)}; // <> Die ungeteilte Eigentümerschaft kann auch an einen gemeinsamen Zeiger *verschoben* werden.
    //]
}
//]
