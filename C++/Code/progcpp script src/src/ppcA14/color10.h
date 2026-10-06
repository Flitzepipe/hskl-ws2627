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

#include "../ppc.h"

#include <string>
#include <cstdint> // <> Definiert Alternativen zu den primitiven DT wie `int` mit festen Größen: etwa `int32_t`, ein Ganzzahltyp mit 32-Bit Breite.

class Color final
{
    friend bool operator==(const Color& lhs, const Color& rhs);
public:
    enum class PredefinedColor // <> Ein sog. _Scoped Enumeration_-Typ (Aufzählungstyp) `PredefinedColor`
    {                          // <> Der Wertebereich des Aufzählungstyps in `{...}`
        Black, White,          // <> Die vollständige Auflistung der möglichen Werte im Wertebereich
        Maroon, Green, Olive, Navy,
        Purple, Teal, Silver, Gray,
        Red, Lime, Yellow, Blue,
        Fuchsia, Aqua
    };

    explicit Color(uint8_t red = 0, uint8_t green = 0, uint8_t blue = 0); // <> Der Datentyp `uint8_t` ist ein Ganzzahltyp mit fester Breite (_fixed width integer type_): 8-Bit und vorzeichenlos
    Color(PredefinedColor predefinedColor); // <> Dies ist auch ein Typumwandlungskonstruktor.

    std::string rgbString() const; // <> Umwandlung des Farbwertes in ein _RGB_-Darstellung: `rgb(<Rotwert>, <Grünwert>, <Blauwert>)`
    operator std::string() const; // <> Dieser _Typumwandlungsoperator_ leifert auch die _RGB_-Darstellung.

private:
    uint8_t mRed{};
    uint8_t mGreen{};
    uint8_t mBlue{};
};

bool operator==(const Color& lhs, const Color& rhs); // <> Zwei Farbwerte sind gleich, wenn alle ihre Komponenten gleich sind.
bool operator!=(const Color& lhs, const Color& rhs);
