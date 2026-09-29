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
# pragma once
#endif

#include "common.h"

#include <limits>
#include <cmath>

namespace FProg
{
    
    class Math
    {
    public:
        template<typename T>
        static bool equal(T a, T b) {
            if (std::numeric_limits<T>::is_integer) {
                return (a - b) == T(0);
            }
            else {
                const T epsilon = std::numeric_limits<T>::epsilon();
                T difference = a - b;
                if ((difference > -epsilon) && (difference < epsilon)) {
                    return true;
                }
                
            }
            return false;
        }
        template<typename T>
        static int toInt(T value) {
            T roundedValue = std::round(value);
            return static_cast<int>(roundedValue);
        }
        
        template<typename To, typename From>
        static To toFixed(From value) {
            From roundedValue = std::round(value);
            return static_cast<To>(roundedValue);
        }

        inline static const double mPi = 2.0 * std::acos(0.0);
    };
}
