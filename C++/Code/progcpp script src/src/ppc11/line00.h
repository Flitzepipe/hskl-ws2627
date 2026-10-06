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

#if __has_include("../ppc.h")
# include "../ppc.h"
#endif

#include "svgshape.h"
#include "point80.h"

//[Line
class Line final : public SVGShape // <> Schnittstellenvererbung mit Substitutionsprinzip, aber die Klasse `Line` ist *nicht* weiter ableitbar (`final`).
{
public:
    Line(const Point& point1, const Point& point2);

    virtual std::string toSVG() const override; // <> Explizites Überschreiben der Elementfunktion
    virtual DRect svgArea() const override;

    Line& setColor(const std::string& color);
    const std::string& getColor() const;
private:
    Point mPoint1;
    Point mPoint2;
    std::string mColor{"black"};
    inline static int mSVGWidth{5};
};
//]
