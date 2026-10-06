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

#include <iostream>

int main()
{
    std::cout << "__cplusplus: " << __cplusplus << std::endl; // <> Ausgabe der aktuellen Version des Standards, den der verwendete Compiler unterstützt

#ifdef _MSC_VER
    std::cout << "_MSC_VER: " << _MSC_VER << std::endl;
#endif

#ifdef __GNUC__
    std::cout << "__GNUC__: " << __GNUC__ << std::endl;
#endif

#ifdef __clang__
    std::cout << "__clang__: " << __clang_version__ << std::endl;
#endif

#ifdef _WIN32
    std::cout << "_WIN32: " << _WIN32 << std::endl;
#endif

#ifdef __CYGWIN__
    std::cout << "__CYGWIN__: " << __CYGWIN__ << std::endl;
#endif
}
