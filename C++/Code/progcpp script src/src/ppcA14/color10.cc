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

#include "color10.h"
#include "../lib/simpletest.h"

SIMPLETEST("Color1"){
    Color c;
    auto s = c.rgbString();
    if (s != "rgb(0,0,0)") {
        return false;
    }
    return true;
};

SIMPLETEST("Color2"){
    Color c = Color::PredefinedColor::Black;
    auto s = c.rgbString();
    if (s != "rgb(0,0,0)") {
        return false;
    }
    return true;
};

SIMPLETEST("Color3"){
    Color c = Color::PredefinedColor::White;
    auto s = c.rgbString();
    if (s != "rgb(255,255,255)") {
        return false;
    }
    return true;
};

Color::Color(uint8_t red, uint8_t green, uint8_t blue) :
    mRed{red},
    mGreen{green},
    mBlue{blue}
{
}

Color::Color(PredefinedColor predefinedColor) :
    Color{0, 0, 0}
{
    switch (predefinedColor) {
    case PredefinedColor::Black:
        mRed = 0; mGreen = 0; mBlue = 0;
        break;
    case PredefinedColor::White:
        mRed = 255; mGreen = 255; mBlue = 255;
        break;
    case PredefinedColor::Maroon:
        mRed = 128; mGreen = 0; mBlue = 0;
        break;
    case PredefinedColor::Green:
        mRed = 0; mGreen = 255; mBlue = 0;
        break;
    case PredefinedColor::Olive:
        mRed = 128; mGreen = 128; mBlue = 0;
        break;
    case PredefinedColor::Navy:
        mRed = 0; mGreen = 0; mBlue = 128;
        break;
    case PredefinedColor::Purple:
        mRed = 128; mGreen = 0; mBlue = 128;
        break;
    case PredefinedColor::Teal:
        mRed = 0; mGreen = 128; mBlue = 128;
        break;
    case PredefinedColor::Silver:
        mRed = 192; mGreen = 192; mBlue = 192;
        break;
    case PredefinedColor::Gray:
        mRed = 128; mGreen = 128; mBlue = 128;
        break;
    case PredefinedColor::Red:
        mRed = 255; mGreen = 0; mBlue = 0;
        break;
    case PredefinedColor::Lime:
        mRed = 0; mGreen = 255; mBlue = 0;
        break;
    case PredefinedColor::Yellow:
        mRed = 255; mGreen = 255; mBlue = 0;
        break;
    case PredefinedColor::Blue:
        mRed = 0; mGreen = 0; mBlue = 255;
        break;
    case PredefinedColor::Fuchsia:
        mRed = 255; mGreen = 0; mBlue = 255;
        break;
    case PredefinedColor::Aqua:
        mRed = 0; mGreen = 255; mBlue = 255;
        break;
    default:
        break;
    }
}

std::string Color::rgbString() const
{
    return "rgb(" +
            std::to_string(mRed) + "," +
            std::to_string(mGreen) + "," +
            std::to_string(mBlue) +
            ")";
}

Color::operator std::string() const
{
    return rgbString();
}

bool operator==(const Color& lhs, const Color& rhs)
{
    return (lhs.mBlue == rhs.mBlue) &&
            (lhs.mRed== rhs.mRed) &&
            (lhs.mGreen== rhs.mGreen);
}

bool operator!=(const Color& lhs, const Color& rhs)
{
    return !(lhs == rhs);
}
