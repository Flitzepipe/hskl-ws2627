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

targets += part01 part01.aout part01.cc.extract complexnumber90.cc.extract complexnumber90.h.extract objectserial.h.extract
targets += objectserial.cc.extract complexvector60.cc.extract complexvector60.h.extract
targets += complexpolygon30.h.extract complexpolygon30.cc.extract
targets += svgfile.h.extract svgfile.cc.extract
targets += dgeometry.h.extract dgeometry.cc.extract
targets += string10.h.extract string10.cc.extract
targets += pair.h.extract pair.cc.extract
targets += part01.aout

part01: part01.o complexnumber90.o complexvector60.o trace10.o complexpolygon30.o ../lib/simpletest.o math.o \
	objectserial.o string10.o pair.o svgfile.o dgeometry.o svgelement.o

include ../Makefile.include

