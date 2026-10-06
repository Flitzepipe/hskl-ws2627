# -*- mode: makefile-gmake; -*-
# $Id: Makefile 1268 2018-09-20 08:36:44Z wimalopaan $
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

MCU = avr128da32
F_OSC = 32000000

PARGS =
SIMPLETEST = nooutput

#CXXFLAGS += -DNDEBUG

avr5531lto.elf: OPTFLAGS += -flto

avr5540.elf: OPTFLAGS += -flto -fwhole-program
avr5540.S: OPTFLAGS += -flto -fwhole-program

avr5506_O3.S: OPTFLAGS = -O3
avr5507b_O3.S: OPTFLAGS = -O3
avr5507c_O3.S: OPTFLAGS = -O3
avr5507d_O3.S: OPTFLAGS = -O3
avr5507e.elf: OPTFLAGS += -flto -fwhole-program
avr5507e_O3.elf: OPTFLAGS = -O3 -flto -fwhole-program

avr5526.s: MCU = atmega644
avr5526_O3.s: MCU = atmega644 
avr5526_O3.s: OPTFLAGS = -O3
avr5526.elf: MCU = atmega644

#avr5528.s: MCU = atmega644
#avr5528_O3.s: MCU = atmega644 
avr5528_O3.s: OPTFLAGS = -O3
avr5528_O3.elf: OPTFLAGS = -O3
#avr5528.elf: MCU = atmega644

avr5529_O3.s: OPTFLAGS = -O3
avr5529_O3.elf: OPTFLAGS = -O3

avr5550_O3.s: OPTFLAGS = -O3
avr5550_O3.elf: OPTFLAGS = -O3

avr5527.s: MCU = atmega644
avr5527_O3.s: MCU = atmega644 
avr5527_O3.s: OPTFLAGS = -O3
avr5527.elf: MCU = atmega644

#avr5520.elf: OPTFLAGS += -flto -fwhole-program
#avr5520.S: OPTFLAGS += -flto -fwhole-program

targets += shtml
targets += avr5500.elf avr5500.S
targets += avr5501.elf avr5501.S
targets += avr5502.elf avr5502.S
targets += avr5503.elf avr5503.S
targets += avr5504.elf avr5504.S
targets += avr5505.elf avr5505.S avr5505.cc.extract avr5505.S.axtract
targets += avr5506.elf avr5506.S avr5506.cc.extract avr5506.S.axtract avr5506_O3.S avr5506_O3.S.axtract 
targets += avr5507.elf avr5507.S avr5507.cc.extract avr5507.S.axtract avr5507_O3.S avr5507_O3.S.axtract 
targets += avr5507b.S avr5507b.cc.extract avr5507b.S.axtract avr5507b_O3.S avr5507b_O3.S.axtract 
targets += avr5507c.S avr5507c.cc.extract avr5507c.S.axtract avr5507c_O3.S avr5507c_O3.S.axtract 
targets += avr5507d.S avr5507d.cc.extract avr5507d.S.axtract avr5507d_O3.S avr5507d_O3.S.axtract 
targets += avr5507e.elf avr5507e_O3.elf avr5507e1.cc.extract avr5507e2.cc.extract avr5507e.dis avr5507e_O3.dis
targets += avr5508.elf avr5508.S avr5508.cc.extract avr5508.S.axtract
targets += avr5509.elf avr5509.S avr5509.cc.extract avr5509.S.axtract
targets += avr5510.elf avr5510.S avr5510b.S
targets += avr5520.elf avr5520.S 
targets += avr5521.elf avr5521.S 
targets += avr5522.elf avr5522.S 
targets += avr5523.elf avr5523.S 
targets += avr5525.elf avr5525.S 
targets += avr5526.S avr5526_O3.S 
targets += avr5528.S avr5528_O3.S avr5528.elf avr5528_O3.elf 
targets += avr5527.S avr5527_O3.S 
targets += avr5529.S avr5529_O3.S avr5529.elf avr5529_O3.elf 
targets += avr5530.elf avr5530.S avr5530.S.axtract
targets += avr5530ans.elf avr5530ans.S avr5530ans.S.axtract
targets += avr5531lto.elf avr5531.elf avr5531a.S avr5531b.S 
targets += avr5540.elf avr5540.S avr5540.S.axtract
targets += avr5550.S avr5550_O3.S avr5550.elf avr5550_O3.elf 
targets += avr5551.S avr5551.elf
targets += avr5552.S avr5552.elf
targets += avr5553.S avr5553.elf
targets += avr5554.S avr5554.elf

targets += avr5596.elf avr5596.S
targets += avr5597.elf avr5597.S
targets += avr5598.elf avr5598.S
targets += avr5599.elf avr5599.S

avr5506_O3.s: avr5506.cc
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $(ASMFLAGS) -S -o $@ $<

avr5507_O3.s: avr5507.cc
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $(ASMFLAGS) -S -o $@ $<

avr5507b_O3.s: avr5507b.cc
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $(ASMFLAGS) -S -o $@ $<

avr5507c_O3.s: avr5507c.cc
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $(ASMFLAGS) -S -o $@ $<

avr5507d_O3.s: avr5507d.cc
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $(ASMFLAGS) -S -o $@ $<

avr5526_O3.s: avr5526.c
	$(CC) $(CPPFLAGS) $(CFLAGS) $(ASMFLAGS) -S -o $@ $<

avr5528_O3.s: avr5528.c
	$(CC) $(CPPFLAGS) $(CFLAGS) $(ASMFLAGS) -S -o $@ $<

avr5528_O3.elf: avr5528.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -o $@ $<

avr5527_O3.s: avr5527.cc
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $(ASMFLAGS) -S -o $@ $<

avr5529_O3.s: avr5529.cc
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $(ASMFLAGS) -S -o $@ $<

avr5529_O3.elf: avr5529.cc
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -o $@ $? 

avr5550_O3.s: avr5550.cc
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $(ASMFLAGS) -S -o $@ $<

avr5550_O3.elf: avr5550.cc
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -o $@ $? 

avr5510.elf: avr5510.cc avr5510b.cc
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -o $@ $? 

avr5531.elf: avr5531a.o avr5531b.o
	$(LINK.c) $(LDFLAGS)  -o $@ $? 

avr5531lto.elf: avr5531a.cc avr5531b.cc
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -o $@ $? 

avr5507e.elf: avr5507e1.cc avr5507e2.cc
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -o $@ $? 

avr5507e_O3.elf: avr5507e1.cc avr5507e2.cc
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -o $@ $? 

avr5507e.dis: avr5507e.elf
	echo "[source]" > $@
	echo "----" >> $@
	a=$$(avr-nm $< | awk '/main/ {print $$1}') && avr-objdump -dCS --start-address=0x$$a $< >> $@
	echo "----" >> $@
	
avr5507e_O3.dis: avr5507e_O3.elf
	echo "[source]" > $@
	echo "----" >> $@
	a=$$(avr-nm $< | awk '/main/ {print $$1}') && avr-objdump -dCS --start-address=0x$$a $< >> $@
	echo "----" >> $@

include ../../Makefile.avr.include


