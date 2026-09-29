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

#include <algorithm>
#include <cmath>
#include <vector>

#pragma GCC diagnostic ignored "-Wunused-variable"

//[template
template<typename C>
typename C::iterator::difference_type countValue(const C& container, const typename C::value_type& searchValue) // <> Das Schlüsselwort `typename` ist vor sog. _dependent names_ notwendig.
{
    const double threshold = 1E-10;
    return std::count_if(std::begin(container), std::end(container),
                         [&](auto v){return std::fabs(v - searchValue) < threshold;} // <> Es werden alle erreichbaren Variablen der Speicherklasse _automatic_ per-reference gefangen: dies sind hier `container`, `searchValue` und `threshold`.
    );
}
//]
int main()
{
    //[main
    std::vector<double> v{1.0, 2.0, 3.0, 1.0};
    auto n1 = std::count_if(std::begin(v), std::end(v),
                           [](double v) -> bool {return std::fabs(v - 1.0) < 1E-10;} // <> Lambda-Ausdruck, um das Prädikat-Funktionsobjekt zu generieren. Die Angabe des Rückgabetyps kann auch entfallen, da der `<`-Operator den Typ `bool` liefert.
    );
    //]
    //[notrailing
    auto n2 = std::count_if(std::begin(v), std::end(v),
                           [](double v) {return std::fabs(v - 1.0) < 1E-10;} // <> Der Rückgabetyp wird durch den Typ in der `return`-Anweisung bestimmt.
    );
    //]
    //[capture1
    double searchValue = 1.0;
    auto n3 = std::count_if(std::begin(v), std::end(v),
                           [&searchValue](double v) {return std::fabs(v - searchValue) < 1E-10;} // <> Die Variable `searchValue` wird _per-reference_ gefangen.
    );
    //]
    //[capture2
    const double threshold = 1E-10;;
    auto n4 = std::count_if(std::begin(v), std::end(v),
                           [&](double v) {return std::fabs(v - searchValue) < threshold;} // <> _Alle erreichbaren_ Variabeln werden _per-reference_ gefangen.
    );
    //]
    //[template
    auto n5 = countValue(v, 1.0); // <> Instanziierung des Funktionstemplate.
    //]
}
