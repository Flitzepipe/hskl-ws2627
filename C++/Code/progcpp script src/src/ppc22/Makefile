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

PARGS =

SIMPLETEST = nooutput

targets += shtml

targets += ppc2200 ppc2200.cc.extract
targets += ppc2201 ppc2201.cc.extract
targets += heaparray30.h.extract heaparray30.cc.extract heaparray30.comp
targets += heaparray31.h.extract heaparray31.cc.extract
targets += heaparray32.h.extract heaparray32.cc.extract
targets += heaparray35.h.extract heaparray35.cc.extract
#targets += heaparray30.o
targets += heaparray31.o
targets += ppc2202 ppc2202.cc.extract
targets += ppc2203 ppc2203.cc.extract ppc2203.aout
targets += ppc2204 ppc2204.cc.extract ppc2204.aout
targets += ppc2205 ppc2205.cc.extract ppc2205.aout
targets += ppc2207 ppc2207.cc.extract ppc2207.aout list13.h.extract
targets += ppc2208 ppc2208.cc.extract
targets += ppc2206.cc.extract ppc2206.comp
targets += ppc2209 ppc2209.cc.extract
targets += ppc2210 ppc2210.cc.extract list12.h.extract
targets += ppc2211 ppc2211.cc.extract ppc2211.aout
targets += ppc2215 ppc2215.cc.extract ppc2215.aout
targets += ppc2216 ppc2216.cc.extract ppc2216.aout
targets += ppc2217 ppc2217.cc.extract ppc2217.aout
targets += ppc2218 ppc2218.cc.extract ppc2218.aout
targets += ppc2220 ppc2220.cc.extract ppc2220.aout
targets += ppc2221 ppc2221.cc.extract ppc2221.aout
targets += ppc2222 ppc2222.cc.extract ppc2222.aout
targets += ppc2223 ppc2223.cc.extract ppc2223.aout
targets += ppc2224 ppc2224.cc.extract ppc2224.aout

targets += ppc2230 ppc2230.cc.extract ppc2230.aout
targets += ppc2231 ppc2231.cc.extract ppc2231.aout
targets += ppc2232 ppc2232.cc.extract ppc2232.aout

targets += ppc2240 ppc2240.cc.extract ppc2240.aout

targets += ppc2250 ppc2250.cc.extract ppc2250.aout
targets += ppc2251 ppc2251.cc.extract ppc2251.aout
targets += ppc2252 ppc2252.cc.extract ppc2252.aout

targets += ppc2260

ppc2202: ppc2202.o heaparray31.o math.o 

ppc2203: ppc2203.o heaparray31.o math.o 

ppc2204: ppc2204.o heaparray32.o math.o 

ppc2205: ppc2205.o heaparray31.o math.o 

ppc2209: ppc2209.o heaparray35.o math.o 

ppc2210: ppc2210.o list12.o math.o 

ppc2207: ppc2207.o list13.o math.o 

ppc2240: ppc2240.o heaparray40.o inserter.o math.o 


heaparray30.comp: heaparray30.cc
	-$(COMPILE.cc) $(STDFLAGS) -o $@.o $< > $@ 2>&1; true

ppc2206.comp: ppc2206.cc
	-$(COMPILE.cc) $(STDFLAGS) -o $@.o $< 2>&1 | head -20 > $@; true

include ../Makefile.include


