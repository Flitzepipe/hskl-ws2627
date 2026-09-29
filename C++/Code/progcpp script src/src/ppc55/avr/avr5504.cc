#include <avr/interrupt.h>
#include <atomic>
#include <avr/memory.h>

namespace {
    int v;
}
 
ISR(TCA0_OVF_vect) {
    v += 1;
}

int main() {
    while(true) {
        Atomic::access([]{
            if (v == 42) {
                v += 1;
            }
        });
    }    
}
