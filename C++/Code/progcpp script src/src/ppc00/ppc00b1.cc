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

//[include
#include <iostream> // <> Notwendig, damit man `std::cout << "ausgabe"` schreiben kann
#include <vector>   // <> Notwendig, damit man den _generischen_ Typ `std::vector<T>` verwenden kann
#include <string>   // <> Notwendig, damit man den Typ `std::string` verwenden kann.
#include <iterator>

using namespace std;


int foo(int i); //deklaration
int foo(int i); //deklaration

int foo(int i){
  i = 2;
  return 123;
}  //definition

int foo(int i){
  i = 2;
  return 123;
}  //definition




//[Hello
class Hello {
public:
    static void main(const std::vector<std::string> arguments) { // <> `arguments` ist Parametervariable der Funktion
        cout << "Hallo C++-Welt" << std::endl; // <> Ausgabe eines C-Strings
        for(std::string s: arguments) { // <> *Container-for-loop* (_range-based_-`for`) über den Container `arguments`
            cout << s << std::endl; // <> Ausgabe von `s` mit Zeilenvorschub
        }
    }
};
//]
//[main


// foo(111)
// foo(222, 43)

int main(const int argc, const char* const* const argv) {
    //[copy
    vector<std::string> args{argv, argv + argc};
    //]
    //[call
    Hello::main(args); // <> Aufruf der statischen Elementfunktion(Klassenmethode) `main(...)` der Klasse `Hello`
    //]
    return 0;
}


