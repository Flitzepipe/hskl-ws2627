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

targets += ppc2100 ppc2100.cc.extract heaparray10.h.extract heaparray10.cc.extract
targets += ppc2110 ppc2110.cc.extract heaparray20.h.extract heaparray20.cc.extract
targets += ppc2105 ppc2105.cc.extract heaparray15.h.extract heaparray15.cc.extract
targets += ppc2102 ppc2102.cc.extract heaparray12.h.extract heaparray12.cc.extract
targets += ppc2105.aout
targets += ppc2120 list10.cc.extract list10.h.extract
targets += ppc2130 ppc2130.cc.extract cartesian.cc.extract cartesian.h.extract polar.h.extract polar.cc.extract point100.cc.extract point100.h.extract
targets += ppc2131 list11.h.extract
targets += ppc2132 ppc2132.cc.extract cartesian10.cc.extract cartesian10.h.extract polar10.h.extract polar10.cc.extract point110.cc.extract point110.h.extract
targets += ppc2121
targets += ppc2150 ppc2150.cc.extract
targets += ppc2151 ppc2151.cc.extract
targets += ppc2152 ppc2152.cc.extract
targets += ppc2153 ppc2153.cc.extract
targets += ppc2154 ppc2154.cc.extract
targets += ppc2155 ppc2155.cc.extract
targets += ppc2160 ppc2160.cc.extract pointlist20.cc.extract pointlist20.h.extract

ppc2100: ppc2100.o heaparray10.o ../lib/simpletest.o

ppc2105: ppc2105.o heaparray15.o ../lib/simpletest.o

ppc2110: ppc2110.o heaparray20.o ../lib/simpletest.o

ppc2102: ppc2102.o heaparray12.o ../lib/simpletest.o

ppc2120: ppc2120.o list10.o ../lib/simpletest.o

ppc2121: ppc2121.o list11.o ../lib/simpletest.o

ppc2130: ppc2130.o cartesian.o polar.o point100.o list10.o svgshape.o extendedsvgshape.o dgeometry.o math.o ../lib/simpletest.o

ppc2131: ppc2131.o cartesian.o polar.o point100.o list11.o svgshape.o extendedsvgshape.o dgeometry.o math.o ../lib/simpletest.o

ppc2132: ppc2132.o cartesian10.o polar10.o point110.o list11.o svgshape.o extendedsvgshape.o dgeometry.o math.o ../lib/simpletest.o

ppc2160: ppc2160.o cartesian.o polar.o point100.o pointlist20.o svgshape.o extendedsvgshape.o dgeometry.o math.o ../lib/simpletest.o

include ../Makefile.include


