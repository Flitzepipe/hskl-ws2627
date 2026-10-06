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

#if __has_include("../ppc.h") //-
# include "../ppc.h" //-
#endif //-

#include <iostream>
#include <vector> // <> Notwendiges `include` für den DT `std::vector<T>` (s.u.)
#include <utility>
#include <cassert>
#include <numeric>

int absoluteSum(const std::vector<int>& array) {
    const int sum = [&]{
        int partialSum{0};
        for(const int& x: array) { // <> Diese sog. `range-based` `for`-Schleife kann auf den DT `std::vector<T>` angewendet werden.
            partialSum += std::abs(x);
        }
        return partialSum;
    }();
    return sum;
}

int main()
{
    const std::vector<int> array = {1, 2, -3, -4, 5};

    std::cout << absoluteSum(array) << std::endl;
    std::cout <<
                 std::accumulate(std::begin(array), std::end(array), 0) // <> Alternative Akkumulation durch Anwendung eines _Algorithmus_ aus der Standardbibliothek. Achtung: dies ist _keine_ Summation des Betrages der Elemente!
              << std::endl;

    std::cout <<
                 std::accumulate(std::begin(array), std::end(array), 0,
                                 [](int init, int element) {return init + std::abs(element);}) // <> Dieses _Funktionsobjekt_ wird für jede Iteration aufgerufen und bewirkt die Betragsaddition.
              << std::endl;
}
