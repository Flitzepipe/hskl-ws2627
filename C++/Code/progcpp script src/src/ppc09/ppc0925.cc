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

#if __has_include("../ppc.h")
# include "../ppc.h"
#endif

#include <iostream>
#include <string>

#ifndef _MSC_VER
# pragma GCC diagnostic ignored "-Wreorder"
#endif

class LifeTime
{
public:
    LifeTime(const std::string& name) : mName(name) {
        std::cout << __PRETTY_FUNCTION__ << " : " << mName << std::endl;
    }
    ~LifeTime() {
        std::cout << __PRETTY_FUNCTION__ << " : " << mName << std::endl;
    }
private:
    std::string mName;
};

//[classes -a
class A
{
public:
    A() : mA1("A1"), mA2("A2") {
        std::cout << __PRETTY_FUNCTION__ <<  std::endl; //-
    }
    //[a
    virtual ~A() {
        std::cout << __PRETTY_FUNCTION__ <<  std::endl;
    }
    //]
private:
    LifeTime mA1;
    LifeTime mA2;
};

class B : public A
{
public:
    B() : mB("B"){
        std::cout << __PRETTY_FUNCTION__ <<  std::endl; //-
    }
    //[a
    ~B() {
        std::cout << __PRETTY_FUNCTION__ <<  std::endl;
    }
    //]
private:
    LifeTime mB;
};

class C : public B
{
public:
    C() : mC2("C2"), mC1("C1"){ // <> *Achtung*: Initialisierung erfolgt in der Reihenfolge der Definition der Datenelemente!
        std::cout << __PRETTY_FUNCTION__ <<  std::endl; //-
    }
    //[a
    ~C() {
        std::cout << __PRETTY_FUNCTION__ <<  std::endl;
    }
    //]
private:
    LifeTime mC1;
    LifeTime mC2;
};
//]
//[main
int main()
{
    C c;
}
//]
