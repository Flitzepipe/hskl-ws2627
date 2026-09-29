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

#include <assert.h>
#include <stdint.h>

void f1(const char* p) {
    volatile char first = p[0];
}

void f2(const char (*p)[10]) {
    volatile char first = (*p)[0];
}

void g() {}

void h(void) {}

//enum States {
//    stop,
//    go,
//    slow1,
//    slow2,
//    ks1,
//    ks2,
//    ks3
//};

//enum States state = States::slow1;

//enum  States1 {
//    stop
//};

typedef struct _signalsystem {
  enum _states2
  {
    stop2,
    go2
  };
  
  uint8_t state;
  
  enum _states2 state2;
  
}signalsystem_t;

signalsystem_t signal;

uint8_t x;

struct {
unsigned int genau : 1;
unsigned int mitjein : 2;
} antwort;

int main(void) {
    antwort.genau = x & 1u; 
    
    antwort.mitjein = x & 2u;
    
    signal.state = go2;
    signal.state2 = go2;
    signal.state2 = 3;
    
    
    const char s1[] = "abc";
    const char s2[10] = "abc";
    
    f1(s1);
    f2(s1); // decay

    f1(s2);
    f2(s2); // decay

    f1(&s2); // incompatible
    f2(&s2); // ok!!!
    
    assert(s1 == &s1);
    assert(s2 == &s2);
    
    const char* cs1 = s1;
    const char* cs2 = s2; // decay

    f1(cs1); 
    f2(cs2); // decay
    
    assert(sizeof(s1) == 4);
    assert(sizeof(s2) == 10);

    assert(sizeof(cs1) == sizeof(char*));
    assert(sizeof(cs2) == sizeof(char*));

    g(5);
//    h(5);
}

