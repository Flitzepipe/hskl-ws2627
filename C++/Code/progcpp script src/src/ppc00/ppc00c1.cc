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
#include <vector>
#include <string>
#include <iterator>

//[HelloDecl
class Hello { // <> Deklaration der Klasse `Hello`
public:
    static void main(std::vector<std::string> arguments); // <> Deklaration der statischen Element-Funktion `void main()`
};
//]
//[main
int main(const int argc, const char* const* const argv) {
    //[copy
    std::vector<std::string> args{argv, argv + argc};
    //]
    //[call
    Hello::main(args); // <> Die obige Deklaration hat das Element `Hello::main()` bekanntgemacht, deswegen können wir die Funktion aufrufen
    //]
}
//]
//[maindef
void Hello::main(const std::vector<std::string> arguments) { // <> *Definition* der (statischen) Element-Funktion `void main()`
    std::cout << "Hallo C++-Welt" << std::endl;
    for(std::string s: arguments) {
        std::cout << s << std::endl;
    }
}
//]
