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
#include <limits>
#include "heaparray35.h"

int main()
{
    //[main1
    HeapArray<double> ha1 {.1, .2, .3};
    HeapArray<double> ha2(3);
    
    using IT = HeapArray<double>::iterator; // <> Es ist Konvention, das die Container den Typ `iterator` definieren (entweder als geschachtelten Typ oder als Typ-Alias)
    
    for(IT it = ha1.begin(), it2 = ha2.begin(); it != ha1.end(); ++it, ++it2) {
        IT::value_type temp = *it; // <> Auch der Typ des Iterators liefert wiederum Informationen, die ohne Kenntnis des Containers nicht direkt zugänglich wären.
        *it2 = temp + IT::value_type{1.01}; // <> Auch hier ist der Wert-Typ des Containers wichtig!
    }
    //]
    
    for(const auto& v : ha2) {
        std::cout << v << '\n';
    }
    
    std::copy(std::begin(ha1), std::end(ha1), std::begin(ha2)); 
    
    //[limits
    const auto mv = std::numeric_limits<double>::min();
    if (std::numeric_limits<double>::is_integer) {
        // ...
    }
    //]
}
