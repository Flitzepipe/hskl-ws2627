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

//[fileIO -header -footer
#include <iostream>
#include <string>
#include <fstream> // <> Deklariert den Typ `std::ofstream`

#include "point20.h"
#include "math.h"

int main()
{
    Point p1{50, 50};
    p1.setColor("blue"); // <> Aufruf der Elementfunktion `Point::setColor(std::string)` mit einem Parameter des Typs C-String
    //[header
    std::string header1{R"(<?xml version="1.0" standalone="no"?>)"}; // <> Definition der lokalen Variable `header1` und Initialisierung mit einem *rohen* C-String-Literal
    std::string header2{R"(<!DOCTYPE svg PUBLIC "-//W3C//DTD SVG 1.1//EN" "http://www.w3.org/Graphics/SVG/1.1/DTD/svg11.dtd">)"};
    std::string header3{R"(<svg xmlns="http://www.w3.org/2000/svg"  width="100" height="100">)"};
    std::string footer1{R"(</svg>)"};
    //]
    //[file
    std::ofstream file{"point.svg"}; // <> Erzeugen und Öffnen der Datei `point.svg`
    //[header
    file << header1 << std::endl; // <> Einfügen der Kopfzeilen für eine _wohlgeformte_ SVG-Datei
    file << header2 << std::endl;
    file << header3 << std::endl;
    //]
    file << p1.toSVG() << std::endl; // <> Schreiben eines Strings in die Datei
    //[footer
    file << footer1 << std::endl; // <> Einfügen der Fußzeile für eine _wohlgeformte_ SVG-Datei
    //]
    //]
}
//]
