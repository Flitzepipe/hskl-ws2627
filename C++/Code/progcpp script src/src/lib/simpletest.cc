/*
 * ++C - C++ introduction
 * Copyright (C) 2013  Wilhelm Meier <wilhelm.meier@hs-kl.de>
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

#include "simpletest.h"

namespace PPC {
#if (__cplusplus <= 201402L)
    size_t SimpleTestCase::mFailureCount = 0;
    size_t SimpleTestCase::mTestCount = 0;
#endif
#if 0
    static SimpleTestCase simpleTestCase = SimpleTestCase("t1", __FILE__, __LINE__) = []{
        return true;
    };
    
    SIMPLETEST("Test for SimpleTest"){
        return true;
    };
#endif
}
