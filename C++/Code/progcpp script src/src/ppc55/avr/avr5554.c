#include <stdint.h>
#include <util/atomic.h>
#include <avr/interrupt.h>
#include <avr/cpufunc.h>

#define ACCESS_ONCE(x) (*(volatile typeof(x)*)&(x))

static uint8_t  flag;
static uint16_t counter;
static uint16_t g1; 
static uint16_t g2; 

static uint16_t count() {
    // besser mit structure-mapping wie in avr5528.c für SREG / sei / cli
    ATOMIC_BLOCK(ATOMIC_RESTORESTATE) { // direkter register-access und / oder gloale memory-barrier führen hier zu schlechter Optimierung bzgl. g1 / g2.
        return counter;
//        return ACCESS_ONCE(counter);
    }
    return 0;
}
static void func(void) {
    for(uint8_t i = 0; i < 20; i++) {
        g1 += count();
        if (ACCESS_ONCE(flag)) {
            ACCESS_ONCE(flag) = 1;
            ++g2;
        }
    }
}

ISR(USART0_RXC_vect) {
    _MemoryBarrier();
    counter += 1;
    if (counter >= 100) {
        flag = 1;
    }
}

int main() {
    func();
}
