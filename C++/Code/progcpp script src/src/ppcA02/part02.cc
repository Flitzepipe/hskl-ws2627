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
#include <cassert>

#include "complexnumber11.h"

int main()
{
    ComplexNumber cn1; // <> _non-const_ wegen der folgenden Veränderung

    cn1.real(1.0);
    assert(cn1.isReal());
    assert(!cn1.isImag());

    cn1.real(0.0);
    cn1.imag(2.0);
    assert(!cn1.isReal());
    assert(cn1.isImag());

    cn1.add(ComplexNumber{1.0, 2.0});

    assert(cn1.real() == 1.0); // <> Das direkte Vergleichen von _Fließkommawerten_ ist immer _falsch_!
    assert(cn1.imag() == 4.0);

    cn1.add({2.0, 3.0});

    assert(cn1.real() == 3.0);
    assert(cn1.imag() == 7.0);

    ComplexNumber cn2;
    cn2 = ComplexNumber::add(cn1, cn1);

    assert(cn2.real() == 6.0);
    assert(cn2.imag() == 14.0);
}
