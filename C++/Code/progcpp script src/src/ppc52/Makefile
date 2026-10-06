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

CXXFLAGS += -fno-exceptions -fno-unwind-tables -fno-threadsafe-statics
CXXFLAGS += -O3

CFLAGS += -fno-unwind-tables 
CFLAGS += -O3

targets += shtml

targets += ppc5200 ppc5200.cc.extract ppc5200.aout
targets += ppc5201 ppc5201.cc.extract
targets += ppc5202 ppc5202.cc.extract
targets += ppc5203 ppc5203.cc.extract
targets += ppc5204 ppc5204.cc.extract
targets += ppc5205 ppc5205.cc.extract
targets += ppc5210 ppc5210.cc.extract
targets += ppc5211 ppc5211.cc.extract
targets += ppc5220 ppc5220.cc.extract ppc5220.aout
targets += ppc5221 ppc5221.cc.extract
targets += ppc5222 ppc5222.cc.extract
targets += ppc5225 ppc5225.cc.extract
targets += ppc5226 ppc5226.cc.extract
targets += ppc5230 ppc5230.cc.extract
targets += ppc5235 ppc5235.cc.extract
targets += ppc5240 ppc5240.cc.extract
targets += ppc5241 ppc5241.cc.extract
targets += ppc5242 ppc5242.cc.extract ppc5242.comp
targets += ppc5243 ppc5243.cc.extract
targets += ppc5244 ppc5244.cc.extract
targets += ppc5245 ppc5245.cc.extract
targets += ppc5246 ppc5246.cc.extract
targets += ppc5247 ppc5247.cc.extract
targets += ppc5248 ppc5248.cc.extract
targets += ppc5250 ppc5250.cc.extract ppc5250.comp
targets += ppc5251 ppc5251.cc.extract
targets += ppc5252 ppc5252.cc.extract
targets += ppc5253 ppc5253.cc.extract ppc5253.comp

subdirs += avr

include ../Makefile.include

ppc5242.comp: ppc5242.cc
	-g++ -DSHOW $(STDFLAGS) $(DEBUGFLAGS) $(EXTRAFLAGS) -o $@.o $< > $@ 2>&1; true

ppc5250.comp: ppc5250.cc
	-g++ -DERROR $(STDFLAGS) $(DEBUGFLAGS) $(EXTRAFLAGS) -o $@.o $< > $@ 2>&1; true

ppc5253.comp: ppc5253.cc
	-g++ -DERROR $(STDFLAGS) $(DEBUGFLAGS) $(EXTRAFLAGS) -o $@.o $< > $@ 2>&1; true
