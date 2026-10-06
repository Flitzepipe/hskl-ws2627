#include <stdbool.h>
#include <signal.h>
#include <avr/interrupt.h>
#include <avr/cpufunc.h>

static int v;  

static volatile uint8_t v2;  
//static /*volatile*/ sig_atomic_t v3;  
static /*volatile*/ __SIG_ATOMIC_TYPE__ v3;  

void isr() __asm__("__vector_5") __attribute__ ((__signal__, __used__, __externally_visible__)); 
void isr() {
    v += 1;
}


void f() {
    static bool flag = false;
//    __asm__ __volatile__ ("" : "+m" (flag) );
    _MemoryBarrier();
    if (flag) {
        v += 1;
    }
    v2 += 1;
    v3 = !v3;
}

int main(void) {
    while(true) {
        _MemoryBarrier();
        if (v == 42) {  
            v += 1; 
        }
        f();
    }    
}
