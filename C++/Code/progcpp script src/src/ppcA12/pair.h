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

#include <iosfwd> // <> Für die Deklaration des Ausgabe-Operators
#include <string>

class Pair
{
    friend std::ostream& operator<<(std::ostream& out, const Pair& pair);
public:
    Pair(double first, double second);
    Pair& asInt(bool flag = true);

    operator std::string() const; // <> Dies ist der _Typumwandlungsoperator_ zum DT `std::string`

    std::string toString() const;
private:
    double mFirst{0.0};
    double mSecond{0.0};
    bool mAsInt{false};
};

std::ostream& operator<<(std::ostream& out, const Pair& pair);
