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

PARGS = abc def

targets += shtml
targets += ppc00a0 ppc00a0.out ppc00a0.aout ppc00a0.cc.extract

targets += ppc00b0 ppc00b0.cc.extract ppc00b0.cc.extractnc ppc00b0.comp Hello.java.extract Hello3.java.extract
targets += Hello3.aout
targets += ppc00b1.cc.extract ppc00b1.cc.extractnc ppc00b1.aout
# Hinweis: 'ppc00b1' (Doppelte Definition, didaktisches Beispiel) ist absichtlich
# NICHT kompilierbar und daher nicht im Default-Build. Einzeln aufrufbar:
#   make ppc00b1   -> zeigt den erwarteten Compiler-Fehler

targets += ppc00c1 ppc00c1.cc.extract
targets += ppc00c2 ppc00c2.cc.extract hello.cc.extract hello.h.extract

targets += test

ppc00c2: ppc00c2.o hello.o

ppc00b0.comp: ppc00b0.cc
	-g++ -DNO_MAIN -o ppc00b0x $< > $@ 2>&1; true

include ../Makefile.include

