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

targets += part01 part01.aout part01.cc.extract complexnumber30.cc.extract complexnumber30.h.extract complexvector00.cc.extract complexvector00.h.extract
targets += part02 part02.aout part02.cc.extract

part01: part01.o complexnumber30.o ../lib/simpletest.o math.o ../lib/tracer.o

part02: part02.o complexnumber30.o complexvector00.o ../lib/simpletest.o math.o ../lib/tracer.o

include ../Makefile.include

