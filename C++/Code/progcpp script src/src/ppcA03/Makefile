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

#SIMPLETEST = nooutput

targets += shtml

targets += part01 part01.aout part01.cc.extract complexnumber20.cc.extract complexnumber20.h.extract
targets += part02 part02.aout part02.cc.extract complexnumber21.cc.extract complexnumber21.h.extract
targets += part03 part03.aout part03.cc.extract complexnumber22.cc.extract complexnumber22.h.extract

part01: part01.o complexnumber20.o ../lib/simpletest.o math.o

part02: part02.o complexnumber21.o ../lib/simpletest.o math.o

part03: part03.o complexnumber22.o ../lib/simpletest.o math.o

include ../Makefile.include

