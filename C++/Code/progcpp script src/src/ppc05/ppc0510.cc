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

#include "point44.h"
#include "svgfile.h"
#include "math.h"

int main()
{
#ifdef _MSC_VER
    std::linear_congruential_engine<unsigned int, 63, 0, 255> generator;
#else
    std::linear_congruential_engine<unsigned char, 63, 0, 255> generator;
#endif

    const int numberOfPoints = 20;

    SVGFile file("line2.svg");
    const Angle deltaPhi{2.0 * Math::pi() / numberOfPoints};

    for(int i = 0; i < numberOfPoints; i += 1) {
        static Radius radius{20.0};
        static Angle phi{0.0};
        Point p{radius, phi};
        p.setColor(generator(), generator(), generator());
        file.add(p); // <> Verbesserung der Schnittstelle (s.a. <<ppcP0500.adoc#viewbox>>)

        radius = radius * 1.2;
        phi = phi + deltaPhi;
    }
}
