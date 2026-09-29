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
#include <algorithm>
#include <cmath>
#include <vector>

//[equals
bool equalsToOne(double a)
{
    if (std::fabs(a - 1.0) < 1e-10) {
        return true;
    }
    return false;
}
//]
int main()
{
    //[double
    std::vector<double> v{1.0, 2.0, 3.0, 1.0};
    auto n = std::count_if(std::begin(v), std::end(v), equalsToOne); // <> Ein direkter Vergleich von _Fließkommawerten_ ist _immer_ falsch.
    std::cout << n << std::endl;
    //]
    //[int
    std::vector<int> w{1, 2, 3, 1};
    auto m = std::count(std::begin(w), std::end(w), 2);
    std::cout << m << std::endl;
    //]
}
