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

#include "svgscene.h"

#include "svgfile.h"

#include "../lib/simpletest.h"

SVGScene&SVGScene::operator+=(std::unique_ptr<SVGShape> shape)
{
    mShapes.push_back(std::move(shape));
    return *this;
}

void SVGScene::serialize(SVGFile& svgFile) const
{
    for(const auto& shapePointer: mShapes) {
        svgFile.add(*shapePointer);
    }
}
