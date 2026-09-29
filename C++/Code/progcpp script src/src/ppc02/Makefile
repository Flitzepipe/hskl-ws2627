# -*- mode: makefile-gmake; -*-
# $Id: Makefile 859 2015-01-20 12:05:40Z wimalopaan $
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

targets += shtml

targets += ppc0200 ppc0201 ppc0201.aout ppc0202 ppc0202.aout ppc0203 ppc0204 ppc0204.aout ppc0205 ppc0205.aout ppc0206 ppc0206.aout
targets += point10.h.extract point10.cc.extract ppc0200.cc.extract
targets += point11.h.extract point11.cc.extract ppc0201.cc.extract
targets += point12.h.extract point12.cc.extract ppc0202.cc.extract
targets += point13.h.extract point13.cc.extract ppc0203.cc.extract
targets += point14.h.extract point14.cc.extract ppc0204.cc.extract
targets += point15.h.extract point15.cc.extract ppc0205.cc.extract
targets += point16.h.extract point16.cc.extract ppc0206.cc.extract

targets += math.h.extract math.cc.extract
targets += mathe.comp

targets += test.svg

test.svg: ppc0206
	./ppc0206 | grep -v "^Test" > $@

ppc0200: ppc0200.o point10.o

ppc0201: ppc0201.o point11.o math.o

ppc0202: ppc0202.o point12.o math.o 

ppc0203: ppc0203.o point13.o math.o 

ppc0204: ppc0204.o point14.o math.o 

ppc0205: ppc0205.o point15.o math.o 

ppc0206: ppc0206.o point16.o math.o 

mathe.comp: math.cc
	$(COMPILE.cc) -DWITH_WARNING -o mathe.o $< >$@ 2>&1


include ../Makefile.include

