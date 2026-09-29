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

#include <iostream> // <> Präprozessor `include`-Anweisung, damit die Ausgabe möglich ist

//[Hello
class Hello { // <> Beginn der Klassendefinition
public:       // <> Beginn der `public`-Sektion
    static void main() { // <> Definition der Klassenmethode `void main()` (statische Elementfunktion)
        std::cout << "Hallo Welt\n"; // <> Ausgabe mit Hilfe des sog. Ausgabe-Operators `<<`
    }
}; // <> das *Semikolon* ist hier *ganz wichtig*!!!
//]
#ifndef NO_MAIN // <> Präprozessoranweisung (nur zu Demonstrationszwecken)
//[main
int main() { // <> *Jedes* Programm beginnt in der freien Funktion `int main()`
    Hello::main(); // <> Aufruf der Klassenmethode (statische Elementfunktion) `void main()` aus der Klasse `Hello`
}
//]
#endif // <> gehört zu `#ifndef` von oben