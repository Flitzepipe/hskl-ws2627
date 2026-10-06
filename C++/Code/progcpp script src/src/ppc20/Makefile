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

SIMPLETEST =

targets += shtml

targets += ppc2000 ppc2000.cc.extract
targets += ppc2001 ppc2001.cc.extract ppc2001.aout
targets += ppc2002 ppc2002.cc.extract ppc2002.aout
targets += ppc2003 ppc2003.cc.extract ppc2003.cc.extractnc
targets += ppc2004 ppc2004.cc.extract ppc2004.cc.extractnc
targets += ppc2005.cc.extract ppc2005.comp
targets += ppc2006 ppc2006.cc.extract integer.cc.extract integer.h.extract templates.h.extract
targets += ppc2007 ppc2007.cc.extract ppc2007.aout
targets += ppc2008 ppc2008.cc.extract
targets += ppc2009 ppc2009.cc.extract ppc2009.aout
targets += ppc2010 ppc2010.cc.extract ppc2010.aout
targets += ppc2011 ppc2011.cc.extract ppc2011.aout
targets += ppc2012 ppc2012.cc.extract ppc2012.aout
targets += ppc2013 ppc2013.cc.extract ppc2013.aout
targets += ppc2020 ppc2020.cc.extract ppc2020.aout
targets += ppc2021 ppc2021.cc.extract ppc2021.aout
targets += ppc2022 ppc2022.cc.extract ppc2022.aout
targets += ppc2025 ppc2025.cc.extract ppc2025.aout
targets += ppc2026 ppc2026.cc.extract ppc2026.aout
targets += ppc2027 ppc2027.cc.extract ppc2027.aout
targets += ppc2099 ppc2099.cc.extract ppc2099.aout
targets += ppc2028a ppc2028.cc.extract ppc2028a.aout
targets += ppc2028b ppc2028b.aout
targets += ppc2028c ppc2028c.aout
targets += ppc2028d ppc2028d.aout
targets += ppc2030 ppc2030.cc.extract ppc2030.aout point100.h.extract point100.cc.extract double.h.extract double.cc.extract math.h.extract math.cc.extract
targets += ppc2040 ppc2040.cc.extract ppc2040.aout heaparray.h.extract
targets += ppc2041 ppc2041.cc.extract ppc2041.aout heaparray01.h.extract
targets += ppc2050 ppc2050.cc.extract ppc2050.aout 
targets += ppc2051 ppc2051.cc.extract ppc2051.aout 

ppc2040: ppc2040.o point90.o double.o math.o svgshape.o extendedsvgshape.o dgeometry.o heaparray.o ../lib/simpletest.o

ppc2041: ppc2041.o point90.o double.o math.o svgshape.o extendedsvgshape.o dgeometry.o heaparray01.o ../lib/simpletest.o

ppc2030: ppc2030.o point100.o double.o math.o ../lib/simpletest.o

ppc2006: ppc2006.o integer.o

ppc2007: ppc2007.o integer.o

ppc2005.comp: ppc2005.cc
	-g++ -o $@.o $< > $@ 2>&1; true

ppc2028a: ppc2028.cc
	$(CXX) $(STDFLAGS) -DA -o $@ $<

ppc2028b: ppc2028.cc
	$(CXX) $(STDFLAGS) -DA -DB -o $@ $<

ppc2028c: ppc2028.cc
	$(CXX) $(STDFLAGS) -DA -DB -DC -o $@ $<

ppc2028d: ppc2028.cc
	$(CXX) $(STDFLAGS) -DA -DB -DC -DD -o $@ $<

include ../Makefile.include


