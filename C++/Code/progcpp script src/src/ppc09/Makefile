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

ppc0922e.aout: SIMPLETEST=notests
ppc0922.aout: SIMPLETEST=notests

targets += shtml

targets += ppc0900 ppc0900.cc.extract ppc0900.aout point80.h.extract point80.cc.extract svgshape.h.extract svgshape.cc.extract
targets += svgfile.h.extract svgfile.cc.extract line00.h.extract line00.cc.extract dgeometry.h.extract dgeometry.cc.extract

targets += ppc0910 ppc0910.cc.extract test.svg
targets += ppc0920 test2.svg ppc0920.aout ppc0920.out ppc0920.cc.extract
targets += ppc0930 test3.svg

targets += ppc0922 ppc0922.cc.extract ppc0922.aout ppc0922e ppc0922e.aout ppc0922e.valgrind pointlist20.h.extract pointlist20.cc.extract list00.cc.extract list00.h.extract

targets += ppc0925 ppc0925.aout ppc0925.cc.extract string.cc.extract string.h.extract

ppc0900: ppc0900.o point80.o line00.o svgfile.o math.o string.o dgeometry.o svgshape.o

ppc0910: ppc0910.o point80.o line00.o svgfile.o math.o string.o dgeometry.o svgshape.o svgscene.o 

ppc0930: ppc0930.o point90.o line10.o svgfile.o math.o string.o dgeometry.o svgshape.o extendedsvgshape.o svgscene.o 

ppc0922: ppc0922.o pointlist20.o list00.o point80.o math.o svgshape.o dgeometry.o 

ppc0922e: ppc0922e.o pointlist20.o list00.o point80.o math.o svgshape.o dgeometry.o 

ppc0922e.o: ppc0922.cc
	$(COMPILE.cc) -DWITH_ERROR $(STDFLAGS) $(DEBUGFLAGS) $(EXTRAFLAGS) $(OUTPUT_OPTION) $<

test.svg: ppc0900
	./ppc0900

test2.svg: ppc0910
	./ppc0910

test3.svg: ppc0930
	./ppc0930

include ../Makefile.include

objects += ppc0922e.o

