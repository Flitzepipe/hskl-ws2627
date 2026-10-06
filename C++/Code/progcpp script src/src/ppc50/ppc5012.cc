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

#include <cstddef>
#include <cstdint>

namespace PPC {
//[array
    template<typename T, size_t Size>
    struct array {
        constexpr const T& operator[](size_t index) const { //<> Kann nur dann in einem `constexpr`-Kontext verwendet werden, wenn `mData` ebenfalls `constexpr` ist (also das gesamte Objekt).
            return mData[index];
        }
        constexpr size_t size() const { //<> Kann immer in einem `constexpr`-Kontext verwendet werden, weil der Nicht-Typ-Template-Parameter `Size` ebenfalls `constexpr` ist.
            return Size;
        }
        size_t test() const { //<> kann nicht in einem `constexpr`-Kontext verwendet werden, weil nicht als `constexpr` qualifiziert.
            return Size;
        }
        T mData[Size] = {};
    };
//]
}
int main() {
    //[main1
    constexpr PPC::array<int, 3> a1 = {1, 2, 3}; //<> Das Objekt `a1` ist `constexpr`
    
    constexpr int x1 = a1.size(); //<> Die Elementfunktion `size()` ist auch `constexpr`
#if 0 //-
    constexpr int x2 = a1.test(); //<> Die Elementfunktion `test()` ist _nicht_ `constexpr`, daher ist dies _nicht_ möglich
#endif //-
    constexpr int x3 = a1[0]; // <> Der Subscript-Operator ist ebenfalls `constexpr`. Zusammen mit `constexpr a1` ergibt das ein `constexpr`-Ausdruck. 
    //]
    //[main2
    PPC::array<int, 3> a2 = {1, 2, 3}; //<> Das Objekt `a2` ist _nicht_ `constexpr`
    constexpr int y1 = a2.size(); //<> Dies ist korrekt, weil die Elementfunktion `size()` selbst `constexpr` ist und _nicht_ vom Objektzustand (nicht-`constexpr`) anhängt!
#if 0 //-
    constexpr int y2 = a2[0]; //<> Dies ist nicht möglich, obwohl der Subscript-Operator `constexpr` ist, gilt dies aber nicht für `mData`.
#endif //-
    //]
    return a1[1];
}
