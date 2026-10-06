#include "avr5531.h"

volatile uint8_t r;
volatile bool    flag;

void a() {
    asm(";=A"); //-
    A a;
    a.f();
}
void b() {
    asm(";=B"); //-
    B b;
    b.f();
}
void c() {
    asm(";=C"); //-    
    C c;
    A* p1 = &c;
    p1->f();
}
void d() {
    asm(";=D"); //-    
    D d1;
    D d2;
    A* p2 = flag ? &d1 : &d2;
    p2->f();
}
void e() {
    asm(";=E"); //-
    E e;
    test(e);
}
void f() {
    asm(";=F"); //-
    F f;
    test(f);
}
int main() {
    a();
    b();
    c();
    d();
    e();
    f();
}
