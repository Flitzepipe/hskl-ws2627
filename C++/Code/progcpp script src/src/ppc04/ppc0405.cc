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

class A
{
public:
    void setX(const int& x) // <> ein _setter_ (Mutator) ist `non-const`
    {
        mX = x;
    }
    int getX() const // <> ein _getter_ (Observator) ist *immer* `const`
    {
        return mX;
    }
private:
    int mX{0};
};

int main()
{
    A a; // <> `a` ist eine `non-const` Referenz für das Objekt
    a.setX(42);

    const A& ca = a; // <> `ca` ist eine `const`-Referenz für dasselbe Objekt (`a`)
    // ca.setX(3); // <> nicht möglich
    std::cout << "a.x = " << ca.getX() << std::endl; // <> `const` Elementfunktion für `const`-Referenz ist ok
}
