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

#if __has_include("../ppc.h")
# include "../ppc.h"
#endif

//[class -conv -pi
//[class2 -equal -pi
#include <limits>
#include <cmath>

class Math
{
public:
    //[equal
    template<typename T>
    static bool equal(T a, T b) { // <> Definition einer Template-Elementfunktion
        if (std::numeric_limits<T>::is_integer) { // <> Ein sog. Type-Trait (s.a. Spezialisierungen von Templates)
            return (a - b) == T(0); // <> Bei Ganzzahlen dürfen wir die einfache Differenz auf Null prüfen.
        }
        else {
            const T epsilon = std::numeric_limits<T>::epsilon(); // <> Lieft die kleinste darstellbare Differenz für jeden primitiven Datentyp.
            T difference = a - b;
            if ((difference >= -epsilon) && (difference <= epsilon)) {
                return true;
            }

        }
        return false;
    }
    //]
    //[conv
    template<typename T>
    static int toInt(T value) {
        T roundedValue = std::round(value); // <> `std::round()` ist für Fließkommatypen vielfach überladen.
        return static_cast<int>(roundedValue);
    }

    template<typename To, typename From>
    static To toFixed(From value) {
        From roundedValue = std::round(value);
        return static_cast<To>(roundedValue); // <> Überall dort, wo ein Datentyp verlangt wird, kann auch ein Template-Typ-Parameter eingesetzt werden.
    }
    //]
    //[pi
    static const double mPi;
    static const double& pi();
    //]
};
//]
//]
