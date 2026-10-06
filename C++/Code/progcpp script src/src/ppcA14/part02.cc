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

#include "car.h"
#include "motorcycle.h"

#include <vector>
#include <memory>
#include <iostream>

int main()
{
    //[a1
    const auto p1 = std::make_unique<Car>(); // <> `p1` hat den Typ: `std::unique_ptr<Car>`

    const std::unique_ptr<Serializable> p2 = std::make_unique<Car>(); // <> `p2` ist nun ein Zeiger auf den Basistyp `Serializable`

    std::cout << "SNR1: " << p1->serial() << std::endl;
    std::cout << "SNR2: " << p2->serial() << std::endl;

    const std::unique_ptr<Serializable> p3 = std::make_unique<MotorCycle>(); // <> Auch `p3` ist ein Zeiger auf den Basistyp
    std::cout << "SNR3: " << p3->serial() << std::endl;
    //]

    //[a2
    std::vector<std::unique_ptr<Serializable>> v; // <> Polymorphe Sammlung mit Zeigern auf den Basistyp

    v.push_back(std::make_unique<Car>());
    v.push_back(std::make_unique<Car>());
    v.push_back(std::make_unique<MotorCycle>());

    for(const auto& p: v) {
        std::cout << "SNR aus v: " << p->serial() << std::endl;
    }
    //]
}
