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

#if __has_include("../ppc.h")
# include "../ppc.h"
#endif

#include <memory>
#include "svgfile.h"
#include "point80.h"
#include "line00.h"
#include "svgscene.h"
#include "math.h"

int main()
{
    SVGFile svgFile("test2.svg");

    SVGScene svgScene;
    svgScene += std::make_unique<Point>();

    const size_t numberOfLines = 7;
    for(size_t i = 0; i < numberOfLines; ++i) {
        svgScene += std::make_unique<Line>(Point{}, Point{Radius{100.0}, Angle{(2.0 * Math::mPi * static_cast<double>(i)) / static_cast<double>(numberOfLines)}});
    }

    svgScene.serialize(svgFile);
}
