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
#include <cstddef>
#include <array>

#include "avr0320.h"

namespace Util {
    extern "C" {
    // must be in a different C TU to be compiled as C Code
    uint16_t read16(const Util::detail::ArrayIntegral16* u);
    uint32_t read32(const Util::detail::ArrayIntegral32* u); 
    uint64_t read64(const Util::detail::ArrayIntegral64* u);
    }
    inline uint16_t convert(const detail::ArrayIntegral16& data) {
        return read16(&data);
    }
    inline uint32_t convert(const detail::ArrayIntegral32& data) {
        return read32(&data);
    }
    inline uint64_t convert(const detail::ArrayIntegral64& data) {
        return read64(&data);
    }
    
}

using namespace std::literals;

volatile std::byte a{1};
volatile std::byte b{2};
volatile std::byte c{3};
volatile std::byte d{4};

int main() {
    Util::detail::ArrayIntegral32 data;
    data.small[0] = static_cast<uint8_t>(a);
    data.small[1] = static_cast<uint8_t>(b);
    data.small[2] = static_cast<uint8_t>(c);
    data.small[3] = static_cast<uint8_t>(d);
    
    auto x = Util::convert(data);
    return x / 2;
}