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

targets += shtml
targets += complexnumberlist20.h.extract complexnumberlist20.cc.extract
targets += complexnumberA0.h.extract complexnumberA0.cc.extract
targets += svgelement.cc.extract svgelement.h.extract
targets += color10.cc.extract color10.h.extract
targets += part01

part01: part01.o complexnumberA0.o complexvector70.o trace10.o complexpolygon40.o ../lib/simpletest.o math.o \
	objectserial.o string10.o pair.o svgfile20.o dgeometry.o svgelement.o complexnumberlist20.o svgshape10.o \
	svgconvertible10.o color10.o serializable10.o

include ../Makefile.include

