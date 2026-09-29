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
#include <string>

class A
{
public:
    const std::string& value() const { // <> Ein Datenelement (hier: UDT) *darf* von einer *Observator*-Funktion als `const`-Referenz zurückgegeben werden
        return mValue;
    }
//    std::string& value() const { // <> Nicht möglich! Denn damit würde ein _Observator_ ggf. zu einem _Mutator_
//        return mValue;
//    }
    std::string& wrong() { // <> Zwei *Fehler* in diesem _Observator_: Rückgabe als non-`const`-Referenz, Observator *muss* `const` sein -> s.a Fehler in `main()`
        return mValue;
    }
    const std::string& wrong2() const { // <> *Fehler* ergibt leider nur eine Warnung bei der Kompilierung
        return mValue + "epilog"; // <> Durch den `+`-Operator entsteht ein *temporäres* (anonymes) Objekt auf dem Stack, dass beim Verlassen der Funktion zerstört wird
    }
private:
    std::string mValue = "gaaanz lange Zeichenkette";
};

int main()
{
    A a;
    std::cout << "value = " << a.value() << std::endl; // <> Lies: `a.value()` ist ein _weiterer_ Name für das Datenelement `mValue`
    a.wrong() = "Ups"; // <> Erscheint ungewöhnlich, ist tatsächlich aber nicht selten. Aber: der *Fehler* liegt in Klasse `A`
    std::cout << "value = " << a.value() << std::endl;
    std::string& s = a.wrong(); // <> Weniger ungewöhnlich: `s` ist nun eine non-`const`-Referenz für das Datenelement `A::mValue`
    s = "Ups2"; // <> wieder der *Fehler* wie oben
    std::cout << "value = " << a.value() << std::endl;
}
