# -*- mode: makefile-gmake; -*-
# $Id: Makefile 1261 2018-03-09 06:33:01Z wimalopaan $
#
# ++C - C++ introduction
# Copyright (C) 2013, 2014, 2015, 2016, 2017, 2018 - 2022 Wilhelm Meier <wilhelm.meier@hs-kl.de>
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.
#

MCU = atmega328p
F_OSC = 20000000

PARGS =
SIMPLETEST = nooutput

#avr0000.elf: LOADLIBES = simavr.o

targets += shtml
targets += simavr.o

targets += avr0000.elf avr0000.s avr0000.S avr0000.cc.extract avr0000.S.axtract
targets += avr0001.elf avr0001.s avr0001.S avr0001.cc.extract avr0001.S.axtract
targets += avr0002.elf avr0002.s avr0002.S avr0002.cc.extract avr0002.S.axtract
targets += avr0003.elf avr0003.s avr0003.S avr0003.cc.extract avr0003.S.axtract
targets += avr0010.elf avr0010.s avr0010.S avr0010.cc.extract avr0010.S.axtract

include ../../Makefile.avr.include


