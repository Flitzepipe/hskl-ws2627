#pragma once

#include <cstdint>

extern volatile uint8_t r;
extern volatile bool    flag;

struct A {
    virtual void f();
};

struct B : A {
    void f();
};

struct C : A {
    void f();
};

struct D : A {
    void f();
};

struct E : A {
    void f();
};

struct F final : A {
    void f();
};

void test(E& c);

void test(F& d);
