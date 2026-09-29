/*
 * ++C - C++ introduction
 * Copyright (C) 2013, 2014, 2015, 2016, 2017, 2018 - 2022 Wilhelm Meier <wilhelm.meier@hs-kl.de>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#define __PROG_TYPES_COMPAT__

#include <avr/pgmspace.h>

void foo(const prog_char* s) {}

void bar(const char __attribute__((__progmem__)) *s ) {}

const char p[] __attribute__((__progmem__)) = "xxx" ;

__flash const char t[] = "xxx" ;

int main() {
    const char s[] = "bla";
    
    foo(s);    
    foo(p);    
    foo(t);    

    bar(s);    
    bar(p);    
    bar(t);    
}