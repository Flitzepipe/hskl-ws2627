# -*- mode: makefile-gmake; -*-
# $Id: Makefile 1258 2017-10-17 06:57:14Z wimalopaan $

targets += shtml

%.html: %
	$(EXTRACTOR) -x --eb --io $< | $(SRCHI) -scpp > $@

targets += array.html
targets += atomic.html
targets += cassert.html
targets += cstddef.html
targets += cstdint.html
targets += initializer_list.html
targets += limits.html
targets += memory.html
targets += type_traits.html
targets += utility.html

targets += cstddef.extract

include ../../../Makefile.include
