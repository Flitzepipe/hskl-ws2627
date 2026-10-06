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

targets += shtml

targets += point30.h.extract point30.cc.extract
targets += ppc0401 ppc0401.cc.extract svgfile.h.extract svgfile.cc.extract line.svg line.png string.h.extract string.cc.extract
targets += ppc0402 ppc0402.cc.extract ppc0402.aout
targets += ppc0403 ppc0403.cc.extract ppc0403.aout
targets += ppc0404 ppc0404.cc.extract ppc0404.aout
targets += ppc0405 ppc0405.cc.extract ppc0405.aout
targets += ppc0407.comp ppc0407.cc.extract
targets += ppc0406 ppc0406.cc.extract ppc0406.aout ppc0406.comp
targets += math.h.extract math.cc.extract

ppc0401: ppc0401.o point30.o math.o svgfile.o lifetime.o string.o

line.png: line.svg

line.svg: ppc0401
	./ppc0401

ppc0406.comp: ppc0406.cc
	-$(COMPILE.cc) -o /dev/null $< >$@ 2>&1

ppc0407.comp: ppc0407.cc
	-$(COMPILE.cc) -o /dev/null $< >$@ 2>&1

include ../Makefile.include

