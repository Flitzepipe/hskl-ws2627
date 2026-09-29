#include "avr5531.h"

void A::f() {
    r = 1;
}
void B::f() {
    r = 2;
}
void C::f() {
    r = 3;
}
void D::f() {
    r = 4;
}
void E::f() {
    r = 5;
}
void F::f() {
    r = 6;
}

void test(E& e) {
    e.f();
}

void test(F& f) {
    f.f();
}

