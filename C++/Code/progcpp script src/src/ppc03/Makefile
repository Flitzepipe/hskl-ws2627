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

ppc0305.aout: SIMPLETEST=nooutput

targets += shtml

targets += ppc0301 ppc0302 ppc0305
targets += point20.h.extract point20.cc.extract ppc0301.cc.extract
targets += lifetime.h.extract lifetime.cc.extract ppc0302.cc.extract svgfile.h.extract svgfile.cc.extract
targets += ppc0305.cc.extract
targets += image01.png point.png
targets += ppc0302.aout
targets += ppc0305.aout
targets += ppc0303 ppc0303.aout ppc0303.cc.extract lifetime2.h.extract lifetime2.cc.extract
targets += ppc0310 ppc0310.aout ppc0310.cc.extract
targets += ppc0311 ppc0311.aout ppc0311.cc.extract
targets += ppc0320 ppc0320.aout ppc0321.cc.extract ppc0322.cc.extract

ppc0301: ppc0301.o point20.o math.o simpletest.o

ppc0302: ppc0302.o lifetime.o math.o

ppc0303: ppc0303.o lifetime.o lifetime2.o math.o

ppc0305: ppc0305.o point20.o math.o svgfile.o lifetime.o simpletest.o

ppc0310: ppc0310.o lifetime.o

ppc0311: ppc0311.o lifetime.o

ppc0302.aout: ppc0302



ppc0320: ppc0321.o ppc0322.o lifetime3.o
	$(LINK.cc) -o $@ $?

image01.png: image01.svg

image01.svg: ppc0305
	./ppc0305

point.png: point.svg

point.svg: ppc0301
	./ppc0301

include ../Makefile.include

