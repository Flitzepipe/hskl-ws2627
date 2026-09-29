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
#include <memory>

int main() {
    const size_t l{1000 * 1000};

//    std::unique_ptr<double[]> p1{new double[l]};

//    double* p1 = new double[l]();
    double* p1 = new double[l];

    for(size_t i = 0; i < l; ++i) {
        if (p1[i] != 0.0) {
            std::cout << i << ":" << p1[i] << std::endl;
        }
    }


//    double x;

//    std::cout << "x: " << x << std::endl;
}
