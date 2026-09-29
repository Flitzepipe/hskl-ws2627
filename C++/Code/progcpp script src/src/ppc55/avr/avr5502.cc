#include <avr/interrupt.h>
#include <util/atomic.h>

namespace {
    volatile int v; // <> `volatile` ist hier falsch
}

ISR(TCA0_OVF_vect) {
    v = v + 1;
}

int main() {
    while(true) {
        if (v == 42) {
            v = v + 1;
        }
        
    }    
}
