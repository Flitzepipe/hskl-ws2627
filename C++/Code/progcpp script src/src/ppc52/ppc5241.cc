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

#include <cassert>
#include <type_traits>

namespace PPC {
//[meta
    template<typename... T>
    struct List {}; // <> Eine einfache Typ-Liste
//]
}
//[foo
template<typename... T>
void foo(T... tt) {
    using tl = PPC::List<T...>; // <> Typ-Alias für die Typ-Liste. Die Typ-Liste wird durch die Parameter-Pack-Expansion parametriert.
}
//]
int main() {
    //[main
    using tl = PPC::List<int, double, char>; // <> Explizite Erzeugung der Typ-Liste und Verwendung eines Typ-Alias.
    //]
    //[foo
    foo(1, 1.1, 'c');
    //]
}