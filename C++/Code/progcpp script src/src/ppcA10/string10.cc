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

#include "string10.h"

#include "../lib/simpletest.h"

void String::replace(std::string& s, const std::string& what, const std::string& with)
{
    auto pos = s.find(what);
    if (pos != std::string::npos) {
       s.replace(pos, what.length(), with);
    }
}

//[cstring -tests
//[tests
SIMPLETEST("hash") {
    const char* s1 = "aaaaaaa1";
    const char* s2 = "aaaaaaa2";

    size_t h1 = String::hash(s1);
    size_t h2 = String::hash(s2);

    if (h1 == h2) return false;

    return true;
};

SIMPLETEST("length") {
    const char* s1 = "1234";

    size_t l1 = String::length(s1);

    if (l1 != 4) return false;

    return true;
};

SIMPLETEST("find1") {
    const char* s1 = "abc1def";

    const char* p = String::find(s1, '1');

    if (!p) return false;
    if (*p != '1') return false;

    return true;
};

SIMPLETEST("find2") {
    const char* s1 = "abcdef";

    const char* p = String::find(s1, "a");

    if (!p) return false;
    if (*p != 'a') return false;

    return true;
};

SIMPLETEST("find3") {
    const char* s1 = "abcdef";

    const char* p = String::find(s1, "bc");

    if (!p) return false;
    if (*p != 'b') return false;

    return true;
};
//]

size_t String::hash(const char* const cstring)
{
    assert(cstring); // <> Zusicherung, dass es sich hier um einen gültigen Zeiger handelt
    size_t hashValue{0};

    for(auto it{cstring}; *it != '\0'; ++it) { // <> Iteration bis zum Wächerelement
        hashValue = hashValue * 31 + static_cast<unsigned char>(*it); // <> Diese _explizite_ Typumwandlung vermeidet eine Compiler-Warnung.
    }
    return hashValue;
}

size_t String::length(const char* const cstring)
{
    assert(cstring); // <> Zusicherung, dass es sich hier um einen gültigen Zeiger handelt
    size_t len{0};

    for(auto it{cstring}; *it != '\0'; ++it) { // <> Iteration bis zum Wächerelement
        ++len;
    }
    return len;
}

const char* String::find(const char* const cstring, const char c) // <> Ein Zeiger auf die Fundstelle wird zurückgegeben, damit lässt sich eine Verkettung formulieren.
{
    if (!cstring) { // <> Falls kein gültiger C-String übergeben wurde (s.a. Verkettung der Operation), wird auch `nullptr` zurückgegeben,
        return nullptr;
    }
    for(auto it{cstring}; *it != '\0'; ++it) { // <> Iteration bis zum Wächerelement
        if (*it == c) {
            return it;
        }
    }
    return nullptr;
}

const char* String::find(const char* const cstring, const char* const substring)
{
    if (!cstring) { // <> Falls kein gültiger C-String übergeben wurde (s.a. Verkettung der Operation), wird auch `nullptr` zurückgegeben,
        return nullptr;
    }
    assert(substring);

    for(auto it{cstring}; *it != '\0'; ++it) {
        auto found{it};
        for (auto start{it}, pat{substring}; (*pat != '\0') && (*start != '\0'); ++start, ++pat) {
            if (*start != *pat) {
                found = nullptr;
                break;
            }
        }
        if (found) return found;
    }
    return nullptr;
}
//]
