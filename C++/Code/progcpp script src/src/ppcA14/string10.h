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

//[cstring -r
class String
{
public:
    //[r
    static void replace(std::string& s, const std::string& what, const std::string& with);
    //]

    static size_t length(const char* cstring); // <> Der Parameter `cstring` hat den Typ: Zeiger auf _konstantes_ Zeichen, damit sind die _Zeichen_ des C-Strings nicht änderbar.
    static size_t hash(const char* cstring);

    static const char* find(const char* cstring, char c);
    static const char* find(const char* cstring, const char* substring);
};
//]
