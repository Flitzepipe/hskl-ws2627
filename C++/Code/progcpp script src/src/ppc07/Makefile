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

SIMPLETEST = notests

# sollte eigentlich RVO abschalten -> kein Effekt
CXXFLAGS += -fno-elide-constructors

targets += shtml

targets += ppc0701 ppc0701.cc.extract ppc0701.aout
targets += ppc0702 ppc0702.cc.extract ppc0702.aout2
targets += ppc0703 ppc0703.cc.extract ppc0703.aout ppc0703.valgrind
targets += ppc0704 ppc0704.cc.extract ppc0704.aout ppc0704.valgrind
targets += ppc0705 ppc0705.cc.extract ppc0705.aout ppc0705.valgrind
targets += ppc0706 ppc0706.cc.extract ppc0706.aout ppc0706.valgrind
targets += ppc0707 ppc0707.cc.extract ppc0707.aout ppc0707.valgrind
targets += ppc0708 ppc0708.cc.extract ppc0708.aout ppc0708.valgrind
targets += ppc0710 ppc0710.cc.extract ppc0710.aout point60.cc.extract
targets += ppc0711 ppc0711.cc.extract ppc0711.aout
targets += ppc0720 ppc0720.cc.extract ppc0720.cc.extractnc ppc0720.aout
targets += ppc0721 ppc0721.cc.extract ppc0721.cc.extractnc ppc0721.aout
targets += ppc0730 ppc0730.cc.extract ppc0730.aout
targets += ppc0731 ppc0731.cc.extract ppc0731.aout

ppc0701: ppc0701.o point60.o math.o string.o svgfile.o 

ppc0703: ppc0703.o point60.o math.o string.o 

ppc0704: ppc0704.o point60.o math.o string.o 

ppc0705: ppc0705.o point60.o math.o string.o 

ppc0706: ppc0706.o point60.o math.o string.o 

ppc0707: ppc0707.o point60.o math.o string.o 

ppc0708: ppc0708.o point60.o math.o string.o 

ppc0710: ppc0710.o point60.o math.o

ppc0711: ppc0711.o point60.o math.o

ppc0720: ppc0720.o point61.o math.o

ppc0721: ppc0721.o point61.o math.o

ppc0730: ppc0730.o point61.o math.o

ppc0731: ppc0731.o point61.o math.o

include ../Makefile.include

