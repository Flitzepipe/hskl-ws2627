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

targets += points.svg
targets += ppc0601 ppc0601.cc.extract point50.h.extract point50.cc.extract svgfile.h.extract svgfile.cc.extract
targets += ppc0602 ppc0602.cc.extract ppc0602.aout
targets += ppc0603 ppc0603.cc.extract ppc0603.aout
targets += ppc0604.cc.extract ppc0604.comp
targets += ppc0605 ppc0605.cc.extract ppc0605.aout
targets += ppc0607 ppc0607.cc.extract ppc0607.aout
targets += ppc0608 ppc0608.cc.extract ppc0608.aout
targets += ppc0609 ppc0609.cc.extract ppc0609.aout
targets += ppc0610 ppc0610.cc.extract ppc0610.aout
targets += ppc0611 ppc0611.cc.extract ppc0611.aout point51.h.extract point51.cc.extract
targets += ppc0612 ppc0612.cc.extract ppc0612.aout point52.h.extract point52.cc.extract
targets += ppc0613 ppc0613.cc.extract ppc0613.aout point53.h.extract point53.cc.extract
targets += ppc0614.comp ppc0614.cc.extract
targets += ppc0615 ppc0615.cc.extract ppc0615.aout point54.h.extract point54.cc.extract
targets += ppc0616 ppc0616.cc.extract ppc0616.aout point55.h.extract point55.cc.extract

ppc0601: ppc0601.o point50.o svgfile.o math.o string.o

ppc0605: ppc0605.o point50.o svgfile.o math.o string.o

ppc0607: ppc0607.o point50.o svgfile.o math.o string.o 

ppc0608: ppc0608.o point50.o svgfile.o math.o string.o 

ppc0609: ppc0609.o point50.o svgfile.o math.o string.o 

ppc0611: ppc0611.o point51.o svgfile.o math.o string.o 

ppc0612: ppc0612.o point52.o svgfile.o math.o string.o 

ppc0613: ppc0613.o point53.o svgfile.o math.o string.o 

#ppc0614: ppc0614.o point53.o svgfile.o math.o string.o 

ppc0615: ppc0615.o point54.o svgfile.o math.o string.o 

ppc0616: ppc0616.o point55.o svgfile.o math.o string.o 

ppc0604.comp: ppc0604.cc
	-$(COMPILE.cc) $(STDFLAGS) $(DEBUGFLAGS) $(EXTRAFLAGS) -o /dev/null $< > $@  2>&1

points.svg: ppc0601
	./ppc0601

ppc0614.comp: ppc0614.cc
	-$(COMPILE.cc) $(STDFLAGS) $(DEBUGFLAGS) $(EXTRAFLAGS) -o /dev/null $< > $@  2>&1

include ../Makefile.include

