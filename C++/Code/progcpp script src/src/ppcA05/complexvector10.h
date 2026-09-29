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

#include <string>

#include "complexnumber40.h"

//[CV
class ComplexVector
{
public:
    ComplexVector(ComplexNumber begin, ComplexNumber end);

    std::string toSVG() const; // <> Die Beobachter-Elementfunktion zur Erzeugung der `svg`-Darstellung

    std::string color() const;
    void color(std::string color);

    ComplexNumber begin() const;
    ComplexNumber end() const;

private:
    ComplexNumber mBegin;
    ComplexNumber mEnd;

    inline static const int mSvgWidth{3}; // <> Die Breite des `svg`-Elements `line` für die `svg`-Darstellung als Klassenvariable (`static`) `mSvgWidth`
    std::string mColor{"black"};
};
//]
