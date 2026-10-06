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

#include <cmath>
#include <random>

#include "point43.h"
#include "svgfile.h"
#include "math.h"

int main()
{
#ifdef _MSC_VER
    std::linear_congruential_engine<unsigned int, 63, 0, 255> generator;
#else
    std::linear_congruential_engine<unsigned char, 63, 0, 255> generator;
#endif
    const int number{10};

    SVGFile file{"line.svg"};
    const double deltaPhi = 2.0 * Math::mPi / number;
    for(int i = 0; i < number; i += 1) {
        static double radius{20};
        static double phi{0.0};
        const double x{radius * std::cos(phi)};
        const double y{radius * std::sin(phi)};
        Point p{x, y};
        p.setColor(generator(), generator(), generator());
        file.add(p);

        radius *= 1.2;
        phi += deltaPhi;
    }
}
