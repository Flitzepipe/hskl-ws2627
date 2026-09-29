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

targets += ppc0800 ppc0800.cc.extract ppc0800.aout ppc0800.valgrind pointlist00.h.extract pointlist00.cc.extract
targets += ppc0810 ppc0810.cc.extract ppc0810.aout ppc0810.valgrind pointlist10.h.extract pointlist10.cc.extract
targets += ppc0801 ppc0801.cc.extract ppc0801.aout ppc0801.valgrind pointlist01.h.extract pointlist01.cc.extract
targets += ppc0802 ppc0802.cc.extract ppc0802.aout ppc0802.valgrind pointlist02.h.extract pointlist02.cc.extract
targets += ppc0803 ppc0803.cc.extract ppc0803.aout ppc0803.valgrind pointlist03.h.extract pointlist03.cc.extract
targets += ppc0804 ppc0804.cc.extract ppc0804.aout ppc0804.valgrind pointlist04.h.extract pointlist04.cc.extract
targets += ppc0805 ppc0805.cc.extract ppc0805.aout ppc0805.valgrind pointlist05.h.extract pointlist05.cc.extract
targets += ppc0806 ppc0806.cc.extract ppc0806.aout ppc0806.valgrind pointlist06.h.extract pointlist06.cc.extract
targets += ppc0807 ppc0807.cc.extract ppc0807.aout ppc0807.valgrind pointlist07.h.extract pointlist07.cc.extract
targets += ppc0820 ppc0820.aout

ppc0800.aout: SIMPLETEST=output
ppc0810.aout: SIMPLETEST=output

ppc0800: ppc0800.o point70.o pointlist00.o svgfile.o string.o  math.o
ppc0810: ppc0810.o point70.o pointlist10.o  math.o

ppc0801: ppc0801.o point70.o pointlist01.o math.o
ppc0802: ppc0802.o point70.o pointlist02.o math.o
ppc0803: ppc0803.o point70.o pointlist03.o math.o
ppc0804: ppc0804.o point70.o pointlist04.o math.o
ppc0805: ppc0805.o point70.o pointlist05.o math.o
ppc0806: ppc0806.o point70.o pointlist06.o math.o
ppc0807: ppc0807.o point70.o pointlist07.o math.o

include ../Makefile.include

