#include <avr/interrupt.h>
#include <atomic>
#include <avr/memory.h>

namespace {
    std::atomic<int> v;
}
 
ISR(TCA0_OVF_vect) {
    v.operator+=<std::UnSafe>(1);
}

int main() {
    while(true) {
        if (v == 42) {
            v += 1;
        }
    }    
}
