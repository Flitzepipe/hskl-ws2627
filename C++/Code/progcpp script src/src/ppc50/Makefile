# -*- mode: makefile-gmake; -*-
# $Id: Makefile 1263 2018-03-20 11:26:13Z wimalopaan $
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

CXXFLAGS += -fno-exceptions -fno-unwind-tables -fno-rtti -fno-threadsafe-statics
CXXFLAGS += -O3

targets += shtml ahtml
subdirs = avr

targets += ppc5000 ppc5000.S ppc5000.s ppc5000.cc.extract ppc5000.s.axtract ppc5000.S.axtract
targets += ppc5001 ppc5001.S ppc5001.cc.extract
targets += ppc5010 ppc5010.S ppc5010.cc.extract ppc5010.comp
targets += ppc5011 ppc5011.S ppc5011.cc.extract ppc5011.S.axtract ppc5011.comp
targets += ppc5012 ppc5012.S ppc5012.cc.extract 
targets += ppc5013 ppc5013.S ppc5013.cc.extract 
targets += ppc5014 ppc5014.S ppc5014.cc.extract 
targets += ppc5015 ppc5015.S ppc5015.cc.extract 
targets += ppc5020 ppc5020.S ppc5020.cc.extract ppc5020.comp
targets += ppc5098 ppc5098.cc.extract
targets += ppc5099 ppc5099.S ppc5099.cc.extract 

ppc5010.comp: ppc5010.cc
	-g++ -DWITH_ERROR $(STDFLAGS) $(DEBUGFLAGS) $(EXTRAFLAGS) -o $@.o $< > $@ 2>&1; true

ppc5011.comp: ppc5011.cc
	-g++ -DWITH_ERROR $(STDFLAGS) $(DEBUGFLAGS) $(EXTRAFLAGS) -o $@.o $< > $@ 2>&1; true

ppc5020.comp: ppc5020.cc
	-g++ -DWITH_ERROR $(STDFLAGS) $(DEBUGFLAGS) $(EXTRAFLAGS) -o $@.o $< > $@ 2>&1; true

include ../Makefile.include


