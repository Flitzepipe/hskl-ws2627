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

targets += ppc2300 ppc2300.cc.extract
targets += ppc2301 ppc2301.cc.extract
targets += ppc2302 ppc2302.cc.extract
targets += ppc2303 ppc2303.cc.extract
targets += ppc2304 ppc2304.cc.extract
targets += ppc2305 ppc2305.cc.extract ppc2305.aout
targets += ppc2306 ppc2306.cc.extract ppc2306.aout
targets += ppc2310 ppc2310.cc.extract
targets += ppc2311 ppc2311.cc.extract
targets += ppc2320 ppc2320.cc.extract
targets += ppc2315 ppc2315.cc.extract
targets += ppc2316 ppc2316.cc.extract
targets += ppc2350 ppc2350.cc.extract
targets += ppc2351 ppc2351.cc.extract
targets += ppc2352 ppc2352.cc.extract
targets += ppc2353 ppc2353.cc.extract
targets += ppc2354 ppc2354.cc.extract
targets += ppc2355 ppc2355.cc.extract
targets += ppc2356 ppc2356.cc.extract
targets += ppc2357 ppc2357.cc.extract
targets += ppc2358 ppc2358.cc.extract
targets += ppc2359 ppc2359.cc.extract
targets += ppc2360 ppc2360.cc.extract
targets += ppc2398 ppc2398.c.extract
targets += ppc2399 ppc2399.cc.extract

ppc2206.comp: ppc2206.cc
	-$(COMPILE.cc) $(STDFLAGS) -o $@.o $< 2>&1 | head -20 > $@; true

include ../Makefile.include


