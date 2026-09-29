#include <avr/io.h>
#include <avr/cpufunc.h>

void g();

int a{};

int main() {
//    int a{};
    PORTA.OUT = 1;   
    a = 10;
//    g();
//    _MemoryBarrier();
    PORTA.OUT = 2;   
//    a = 20;
    return a;
}
