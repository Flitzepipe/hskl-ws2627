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

namespace BMCPP {
    namespace AVR {
        //[struct
        struct ATMega328 final {
            ATMega328() = delete;
            struct PortB final {
                PortB() = delete;
                volatile uint8_t in;  // <> Wichtig: `volatile` für Prozessorregister, da diese sich _spontan_ ändern können           
                volatile uint8_t ddr; // <> Problem: Die Modellierung als vorzeichenloser 8-Bit-Wert ist nicht sinnvoll
                volatile uint8_t out;    
                inline static constexpr uintptr_t address = 0x23; // <> Die Anfangsadresse der Struktur, wenn sie als Schablone für den Registerzugriff genutzt werden soll. Ein `static` Datenelement wird nicht im Objekt realisiert. Zudem ist dies eine Compilezeit-Konstante.
            };
        } __attribute__((packed)); // <> Zusammenschieben der Datenelemente (mit 1-Byte-Ausrichtung)
        //]
    } //! AVR
} //! BMCPP

using namespace BMCPP::AVR;

int main() {
    //[main
    auto portb = reinterpret_cast<ATMega328::PortB*>(ATMega328::PortB::address); // <> Durch das `reinterpret_cast<>()` ist ein `constexpr` hier leider nicht möglich, weil ein `reinterpret_cast` per-definitionem nicht `constexpr` ist.
    uint8_t input = portb->in; // <> Lesen aller Pin-Zustände des Ports
    portb->ddr = 0x01; // <> Umschalten des Pins `PB0` in den Ausgangsmodus.
    portb->out = 0x01; // <> Schalten des Pins `PB0` hin den _high_-Zustand.
    //]
}
