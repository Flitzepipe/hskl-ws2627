#include <cstdint>

volatile uint8_t r;
volatile bool    flag;

#ifdef ANS
namespace { // ohne anon NS geht die de-virt nicht so gut wie bei LTO
#endif
    
struct A {
    virtual void f() {
        r = 1;
    }
};
struct B : A {
    void f() {
        r = 2;
    }
};
struct C : A {
    void f() {
        r = 3;
    }
};
struct D : A {
    void f() {
        r = 4;
    }
};
struct E : A {
    void f() {
        r = 5;
    }
};
struct F final : A {
    void f() {
        r = 6;
    }
};
#ifdef ANS
}
#endif
void test(E& e) {
    e.f();
}

void test(F& f) {
    f.f();
}

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
