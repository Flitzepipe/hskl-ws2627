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
#include <cstddef>

//[functor -a
class Functor // <> Die Klasses des Funktionsobjektes.
{
public:
    size_t operator()() { // <> Definition des _Aufruf_-Operators: das erste `()`-Paar ist der _Name_ und das zweit `()`-Paar die Parameterliste (hier leer) der Operator-Elementfunktion.
        return mCount++;
    }
    //[a
    size_t count() const {
        return mCount;
    }
    //]
private:
    size_t mCount{}; // <> Das Datenelement repräsentiert den Zustand des Funktionsobjektes
};
//]
//[main
int main()
{
    Functor f;
    f(); // <> Der Typ `Functor` des Objektes `f` hat den _Aufruf_-Operator `()` definiert.
    f();
    std::cout << f.count() << std::endl;
}
//]
