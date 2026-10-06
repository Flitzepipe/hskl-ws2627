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

#include "point100.h"

//[pointint
template<> // <> Leere Template-Präambel
class Point<float> {  // <> Vollständige Spezialisierung (setzt ein allgemeines Template voraus)
    friend std::ostream& operator<< <float>(std::ostream& out, const Point<float>& p);
public:
    Point(const float& x, const float& y) // <> Der Template-Typ-Parameter `T` wird ersetzt durch den konkreten Typ `float`  
        : mX(x), mY(y) {}

    const float& getX() const {return mX;}
    const float& getY() const {return mY;} //-

    Point& setX(const float& x) {mX = x; return *this;}
    Point& setY(const float& y) {mY = y; return *this;} //-
private:
    float mX = 0;
    float mY = 0;
    bool test = true; //-    
};
//]
template<>
std::ostream& operator<< <float>(std::ostream& out, const Point<float>& p) { // <> _Definition_ einer Spezialisierung für `Point<float>' 
    if (p.test) {}
    out << "Pointf[" << p.mX << ',' << p.mY << ']';
    return out;
}
//[foo
template<typename T>
void foo(const T&) {
    std::cout << __PRETTY_FUNCTION__ << '\n';    
}
//]
int main() 
{
    //[main
    Point<double> p1{0.0, 0.0};    
    Point<float>  p2{0.0, 0.0};    
    
    std::cout << p1 << '\n';
    std::cout << p2 << '\n';
    //]
    foo(p1);
    foo(p2);
}
