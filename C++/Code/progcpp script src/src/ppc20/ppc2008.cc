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

#if __has_include("../ppc.h") //-
# include "../ppc.h" //-
#endif //-

#include <string>
#include <cstring>
#include <iostream>

template<typename T>
size_t numberOfBits(const T& v)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    return sizeof(v) * 8;
}

template<>
size_t numberOfBits<const char*>(const char* const& v)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    return std::strlen(v) * 8;
}

template<>
size_t numberOfBits<std::string>(const std::string& v)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    return v.size() * 8;
}

int main()
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    bool b = false;
    int  i = 0;
    std::string s1 = "abc";
    std::string s2 = "dhshdsjhjsjshdhsdhsdjhsdhsjd";
    std::cout << numberOfBits(b) << std::endl;
    std::cout << numberOfBits(i) << std::endl;
    std::cout << numberOfBits(s1) << std::endl;
    std::cout << numberOfBits(s2) << std::endl;
    std::cout << numberOfBits("1234") << std::endl;
    const char* cs = "abc";
    std::cout << numberOfBits(cs) << std::endl;
}
