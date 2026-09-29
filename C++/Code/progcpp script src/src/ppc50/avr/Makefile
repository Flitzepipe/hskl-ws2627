# -*- mode: makefile-gmake; -*-
# $Id: Makefile 1268 2018-09-20 08:36:44Z wimalopaan $
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

#CXXFLAGS += -DNDEBUG

avr0000.elf: LOADLIBES = simavr.o
avr0001.elf: LOADLIBES = simavr.o

avr0200.elf: LOADLIBES = simavr.o
avr0200.elf: CXXFLAGS += -g

targets += shtml
targets += simavr.o
targets += avr0000.s avr0000.S avr0000.elf avr0000.s.axtract avr0000.S.axtract avr0000.cc.extract simavr.c.extract
targets += avr0001.s avr0001.S avr0001.elf avr0001.s.axtract avr0001.S.axtract avr0001.c.extract
targets += avr0010.elf avr0010.s avr0010.S avr0010.cc.extract avr0010.S.axtract
targets += avr0012.elf avr0012.s avr0012.S
targets += avr0014.elf avr0014.s avr0014.S
targets += avr0015.elf avr0015.s avr0015.S avr0015.cc.extract avr0015.S.axtract
targets += avr0016.elf avr0016.s avr0016.S
targets += avr0017.elf avr0017.s avr0017.S avr0017.cc.extract avr0017.S.axtract
targets += avr0018.elf avr0018.s avr0018.S avr0018.cc.extract avr0018.S.axtract
targets += avr0020.elf avr0020.s avr0020.S avr0020.cc.extract avr0020.S.axtract
targets += avr0021.elf avr0021.s avr0021.S avr0021.cc.extract avr0021.S.axtract
targets += avr0022.elf avr0022.s avr0022.S avr0022.cc.extract avr0022.S.axtract
targets += avr0023.elf avr0023.s avr0023.S avr0023.c.extract avr0023.S.axtract
targets += avr0030.elf avr0030.s avr0030.S avr0030.cc.extract avr0030.S.axtract
targets += avr0031.elf avr0031.s avr0031.S avr0031.cc.extract avr0031.S.axtract
targets += avr0035.elf avr0035.s avr0035.S avr0035.cc.extract avr0035.S.axtract
targets += avr0036.elf avr0036.s avr0036.S avr0036.cc.extract avr0036.S.axtract
targets += avr0037.elf avr0037.s avr0037.S avr0037.cc.extract avr0037.S.axtract

targets += avr0100.elf avr0100.s avr0100.S avr0100.cc.extract avr0100.S.axtract
targets += avr0101.elf avr0101.s avr0101.S avr0101.cc.extract avr0101.S.axtract
targets += avr0102.elf avr0102.s avr0102.S avr0102.cc.extract avr0102.S.axtract
targets += avr0103.elf avr0103.s avr0103.S avr0103.cc.extract avr0103.S.axtract
targets += avr0104.elf avr0104.s avr0104.S avr0104.cc.extract avr0104.S.axtract
targets += avr0105.elf avr0105.s avr0105.S avr0105.cc.extract avr0105.S.axtract
targets += avr0106.elf avr0106.s avr0106.S avr0106.cc.extract avr0106.S.axtract
targets += avr0110.elf avr0110.s avr0110.S avr0110.cc.extract avr0110.S.axtract avr0110.s.axtract
targets += avr0111.elf avr0111.s avr0111.S avr0111.cc.extract avr0111.S.axtract
targets += avr0112.elf avr0112.s avr0112.S avr0112.cc.extract avr0112.S.axtract
targets += avr0112a.elf avr0112a.s avr0112a.S avr0112a.cc.extract avr0112a.S.axtract
targets += avr0112b.elf avr0112b.s avr0112b.S avr0112b.cc.extract avr0112b.S.axtract
targets += avr0113.elf avr0113.s avr0113.S avr0113.cc.extract avr0113.S.axtract
targets += avr0114.elf avr0114.s avr0114.S avr0114.cc.extract avr0114.S.axtract
targets += avr0115.elf avr0115.s avr0115.S avr0115.cc.extract avr0115.S.axtract
targets += avr0116.elf avr0116.s avr0116.S avr0116.cc.extract avr0116.S.axtract
targets += avr0117.elf avr0117.s avr0117.S avr0117.cc.extract avr0117.S.axtract
targets += avr0120.elf avr0120.s avr0120.S avr0120.cc.extract avr0120.S.axtract
targets += avr0121.elf avr0121.s avr0121.S avr0121.cc.extract avr0121.S.axtract
targets += avr0200.elf avr0200.s avr0200.S 

include ../../Makefile.avr.include


