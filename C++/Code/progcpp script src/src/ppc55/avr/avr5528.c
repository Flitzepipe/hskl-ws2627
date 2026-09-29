#include <stdint.h>
#include <util/atomic.h>
#include <avr/interrupt.h>
#include <avr/cpufunc.h>

#define ACCESS_ONCE(x) (*(volatile typeof(x)*)&(x))

typedef struct Cpu { // this is missing in avr headers
    volatile uint8_t r0_3[4];
    volatile uint8_t ccp;
    volatile uint8_t r5_a[6];
    volatile uint8_t rampz;
    volatile uint8_t rc;
    volatile uint16_t sp;
    volatile uint8_t sreg;
} Cpu_t;

#define CPU (*(Cpu_t*) 0x0030) 


static uint8_t  flag;
static uint16_t counter;
static uint16_t g; 

static inline void __iRestoreNB(const  uint8_t* const s) {
    CPU.sreg = *s;
}
#define ATOMIC_FUNCTION uint8_t sreg_save __attribute__((__cleanup__(__iRestoreNB))) = CPU.sreg; \
    asm volatile("cli" : : :);

static uint16_t count_1() {
    ATOMIC_FUNCTION;
    return ACCESS_ONCE(counter);
}
static uint16_t count_2() {
    const uint8_t save = SREG; // suppresses optimization
    asm volatile("cli" : : :);
    const uint16_t t = ACCESS_ONCE(counter);
    SREG = save;
    return t;
}
static uint16_t count_3() {
    ATOMIC_BLOCK(ATOMIC_RESTORESTATE) {
        return ACCESS_ONCE(counter);
    }
}
static void func(void) {
    for(uint8_t i = 0; i < 20; i++) {
        g += count_1();
        if (ACCESS_ONCE(flag)) {
            ACCESS_ONCE(flag) = 1;
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
