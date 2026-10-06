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

//[f
void f() {
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}
//]
int main()
{
    //[main1
    std::cout << f << std::endl; // <> Es gibt keine passende Überladung des Ausgabe-Operators für diesen Funktionszeigertyp, so daß die nächste Konvertierung die nach `bool`, was als `1` ausgegeben wird.
    std::cout << reinterpret_cast<void*>(f) << std::endl; // <> Um den Zeigerwert auszugeben, muss man den Typ auf `void*` konvertieren.
    std::cout << reinterpret_cast<void*>(&f) << std::endl; // <> Dies ist die _konsequente_ Notation für die obige Zeile.
    f(); // <> Der _Aufruf_-Operator ist auf Funktion-_Bezeichner_ anwendbar.
    (*f)(); // <> Wegen der impliziten Wandlung einer _Funktion_ in einen _Zeiger-auf-Funktion_ geht auch dies.
    (**f)(); // <> ... auch dies geht (per Definition)!
    (&f)(); // <> Der Adress-Operator kann auch auf _Funktionen_ angewendet werden: auf den resultierenden _Zeiger-auf-Funktion_ kann auch der _Aufruf_-Operator angewendet werden.
//    (&&f)(); // <> Geht nicht, da &f() ein rvalue liefert.
    //]
    //[main2
    void (*p)(){}; // <> Initialisieung mit `nullptr`.

    p = f; // <> `p` wird die Adresse von `f` zugeweisen: implizite Wandlung von _Funktion_  zu _Zeiger-auf-Funktion_.
    p = &f; // <> wie oben, allerdings _ohne_ die implizite Wandlung!

    std::cout << p << std::endl; // <> Es gibt keine Überladung: s.o.
    std::cout << reinterpret_cast<void*>(p) << std::endl; // <> So kann man den Adresswert in der Variablen `p` ausgeben.
    std::cout << reinterpret_cast<void*>(&p) << std::endl; // <> *Achtung*: dies ist nun die Ausgabe der Adresse der *Variablen* `p`!

    p();
    (*p)();
    (**p)();
//    (&p)(); // nicht möglich
    //]
    
    int array[10] {42};
    
    std::cout << "a1:" << array << std::endl;;    
    std::cout << "a2:" << &array << std::endl;;    
    
    int* ap1 = array;
    int (*ap2)[10] = &array;
//    int *ap3 = &array;

    std::cout << ap1[0] << std::endl;;    
    std::cout << (*ap2)[0] << std::endl;;    

//    decltype(f)::_;
//    decltype(&f)::_;

//    decltype(array)::_;
//    decltype(&array)::_;
    
    auto f1 = f;
    f1();
    auto f2 = &f;
    f2();

    auto a1 = array;
    std::cout << a1[0] << '\n';
    auto a2 = &array;
    std::cout << a2 << '\n';
    std::cout << a2[0] << '\n';
}
