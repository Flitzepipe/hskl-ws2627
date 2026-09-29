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

//[A
class A
{
public:
    A(const int v) : mValue{v} {} // <> Dies ist ein allg. Konstruktor in der _Rolle_ eines *Typumwandlungskonstruktors*
private:
    int mValue{0};
};
//]
//[B
class B
{
public:
    explicit B(const int v) : mValue{v} {} // <> _Implizite_ Typumwandlung durch das Schlüsselwort `explicit` ausgeschlossen
private:
    int mValue{0};
};
//]
int main()
{
    //[conversion
    A a1{1}; // <> Verwendung des allgemeinen Konstruktors
    A a2 = 2; // <> Der `int`-Initialisierer `2` wird in ein temporäres, anonymes Objekt des Typs `A` konvertiert und damit wird `a2` _kopier-initialisiert_
    a1 = 3; // <> Der `int`-Wert `3` wird in ein temporäres, anonymes Objekt des Typs `A` konvertiert und dieses wir dann an `a1` _kopier-zugewiesen_
    a2 = 4;

    B b1{1}; // <> Verwendung des allgemeinen Konstruktors
//    B b2 = 2; // <> Die Rolle des allgemeinen Konstruktors als _Typumwandlungskonstruktor_ ist durch das Schlüsselwort `explicit` abgeschaltet worden
//    b1 = 3;
    b1 = B(3); // <> Auf der rechten Seite wird ein temporäres, anonymes Objekt des Typs `B` _explizit_ instanziiert, das dann an `b1` kopier-zugewiesen wird.
    //]
}
