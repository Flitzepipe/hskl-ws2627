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

#include <cstdint>

#if __has_include(<avr/io.h>)
# include <avr/io.h>
#endif

//[main
volatile uint8_t x = 0;

int main() {
    DDRB = 0xff; // <> Alle Pins dieses Ports (`B`) werden als Ausgang konfiguriert
    DDRC = 0xff; // <> Ebenso für Port `C`
    DDRD = 0xff; // <> Ebenso für Port `D`
    
    for(uint8_t i = 0; i < 100; ++i) {
        x = i; // <> Auch die Werte dieser globalen Variablen `x` können im Simulator sichtbar gemacht werden.
        PORTB = i + 1; // <> Erzeugen eines Bitmusters an den Pins dieses Ports `B`
        PORTC = i + 2; // <> Erzeugen eines Bitmusters an den Pins dieses Ports `C`
        PORTD = i + 3; // <> Erzeugen eines Bitmusters an den Pins dieses Ports `D`
    }
}
//]