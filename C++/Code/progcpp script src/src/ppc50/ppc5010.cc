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

#include <cstdlib>
#include <algorithm>

int main() {
    //[c1
    constexpr const int a1 = 1; // <> Die Auswertung des Initialisierungsausdrucks (hier: `1`) _muss_ zur Compile-Zeit erfolgen.
    constexpr int a2 = 2; // <> _implizit_ auch `const`, damit äquivalent zu `a1` 
    //]
    //[c2
    const int b = std::atoi("1"); // <> Dieser Initialisierung erfolgt durch eine Funktion `atoi()` zur Laufzeit. 
#if WITH_ERROR //-
    constexpr int d = std::atoi("2"); // <> Dies ist nicht möglich.
#endif //-
    //]
    //[c3
    constexpr int e = std::max(a1, a2);    
    //]
}
