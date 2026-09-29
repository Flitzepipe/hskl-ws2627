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


#include <cstddef>
#include <cstdint>
#include <type_traits>
#include <limits>
#include <cassert>

#include <avr/register.h>
#include <avr/mega.h>
#include <avr/pins.h>

#include <util/delay.h>

// avrdude -p m328p -c arduino -b 57600 -P /dev/ttyUSB0 -U flash:w:nano0000.elf

using PortB = BMCPP::AVR::Port<BMCPP::AVR::ATMega328::Port, BMCPP::AVR::B>;
using PortC = BMCPP::AVR::Port<BMCPP::AVR::ATMega328::Port, BMCPP::AVR::C>;

using led = BMCPP::AVR::Pin<PortB, 5>;

namespace std {
    
    template<intmax_t Nom, intmax_t Denom>
    struct ratio {
        static inline constexpr intmax_t nom = Nom;
        static inline constexpr intmax_t denom = Denom;
    };
    using milli = ratio<1, 1'000>;    
    using micro = ratio<1, 1'000'000>;    
    
    template<typename Representation, typename Period = ratio<1, 1>>
    class duration {
    public:
        typedef Representation rep;
        typedef Period perios;
        explicit constexpr duration(const rep& d) : mValue{d} {}
        constexpr rep count() const {return mValue;}
    private:
        Representation mValue{};
    };
    
    using milliseconds = duration<uint16_t, milli>;
    using microseconds = duration<uint16_t, micro>;
    
    namespace literals {
        inline constexpr microseconds operator"" _us(unsigned long long v) {
            assert(v <= std::numeric_limits<microseconds::rep>::max());
            return microseconds{static_cast<microseconds::rep>(v)};
        }
        inline constexpr milliseconds operator"" _ms(unsigned long long v) {
            assert(v <= std::numeric_limits<milliseconds::rep>::max());
            return milliseconds{static_cast<milliseconds::rep>(v)};
        }
    }
}

namespace BMCPP {
    namespace Util {
        template<typename R, typename P> 
        void delay(const std::duration<R, P>& d) {
            static_assert((F_CPU * P::nom) / P::nom == F_CPU, "overflow");
            static_assert((F_CPU * P::nom) / P::denom != 0, "wrong");
            static_assert((((F_CPU * P::nom) / P::denom) * std::numeric_limits<R>::max()) / std::numeric_limits<R>::max() 
                          == ((F_CPU * P::nom) / P::denom), "wrong");
            __builtin_avr_delay_cycles((F_CPU * P::nom / P::denom) * d.count());
        }
    }
    
}
int main() {
    using namespace std::literals; 
    using namespace BMCPP::AVR; 
    
    led::dir<Output>();
    constexpr std::milliseconds offTime = 500_ms;
    constexpr auto onTime = 10_ms;
    
    while(true) {
        led::on();     
        BMCPP::Util::delay(onTime);
        led::off();        
        BMCPP::Util::delay(offTime);
    }
}

inline void __assert_fail(bool, const char*, unsigned int) noexcept {
    while(true) {}
}
