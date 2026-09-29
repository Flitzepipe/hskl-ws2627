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

#include "objectserial.h"

static size_t nextSerialCounter{1};

#include "../lib/simpletest.h"

SIMPLETEST("objectserial1"){
    size_t serial = nextObjectSerial();

    if (createObjectSerial() != serial) return false;
    return true;
};

SIMPLETEST("objectserial2"){
    size_t serial1 = createObjectSerial();
    size_t serial2 = createObjectSerial();

    if (serial1 == serial2) return false;

    return true;
};

size_t createObjectSerial()
{
    return nextSerialCounter++;
}

size_t nextObjectSerial()
{
    return nextSerialCounter;
}
