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

#include <fstream>
#include <string>

class SVGFile
{
public:
    SVGFile(std::string filename);
    ~SVGFile();

    void add(std::string svgElement);
private:
    std::ofstream mFile;
    inline static std::string const header1 = R"(<?xml version="1.0" standalone="no"?>)"; // <> Definition des statischen Datenelements (Klassenvariable)
    inline static std::string const header2 = R"(<!DOCTYPE svg PUBLIC "-//W3C//DTD SVG 1.1//EN" "http://www.w3.org/Graphics/SVG/1.1/DTD/svg11.dtd">)";
    inline static std::string const header3 = R"(<svg xmlns="http://www.w3.org/2000/svg"  width="100" height="100">)";
    inline static std::string const footer1 = R"(</svg>)";
};
