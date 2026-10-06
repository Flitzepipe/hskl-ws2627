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

#include <avr/io.h>

//[main
int main() {
    //[main1
    TIFR0  |= 0x01; // <> ok, aber welche Bedeutung hat das?
    //]
    //[main2
    TIFR0  |= (1 << OCF0B); // <> ok
    TIMSK0 |= _BV(OCIE1B) | _BV(OCIE0A); // <> Abgekürzte Schreibweise durch das Makro `_BV()`, jedoch semantisch falsch, das es das Bit `OCIE1B` im Register `TIMSK0` nicht gibt.
    TIFR0  |= (1 << PCIF0); // <> Das Bit `PCIF0` existiert in dem Register `TIFR0` nicht!!!
    //]
    //[main3
    *((volatile unsigned char*)0x35) |= 0x01; // <> Welches Register ist das? Welche Bedeutung hat das Bit `0` hierin?
    //]
}
//]