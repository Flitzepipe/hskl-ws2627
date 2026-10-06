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

#pragma once

#include <stdint.h>

#ifdef __cplusplus
namespace Util::detail {
    extern "C" {
#endif
    union ArrayIntegral16 {
        uint8_t small[sizeof(uint16_t)];
        uint16_t big;
    };
    union ArrayIntegral32 {
        uint8_t small[sizeof(uint32_t)];
        uint32_t big;
    };
    union ArrayIntegral64 {
        uint8_t small[sizeof(uint64_t)];
        uint64_t big;
    };
#ifdef __cplusplus
    } //! extern "C"
} //! namespace
#endif
