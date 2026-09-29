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

targets += shtml

targets += ppc0100 ppc0100.cc.extract ppc0100.aout
targets += ppc0102 ppc0102.cc.extract ppc0102.aout
targets += ppc0103 ppc0103.cc.extract ppc0103.aout
targets += ppc0104 ppc0104.cc.extract
targets += ppc0105 ppc0105.cc.extract

targets += point00.h.extract point00.cc.extract
targets += point01.h.extract point01.cc.extract
targets += point02.h.extract point02.cc.extract
targets += point03.h.extract point03.cc.extract
targets += point04.h.extract point04.cc.extract
targets += point05.h.extract point05.cc.extract

targets += ppc0103.comp

ppc0103.comp: ppc0103.cc
	-$(CXX) $(CXXFLAGS) -DWITH_ERROR -o ppc0103x $< > $@ 2>&1; true

ppc0100: ppc0100.o point00.o

ppc0102: ppc0102.o point02.o

ppc0103: ppc0103.o point03.o

ppc0104: ppc0104.o point04.o

ppc0105: ppc0105.o point05.o

include ../Makefile.include

