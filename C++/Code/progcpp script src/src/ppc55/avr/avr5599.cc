#include <avr/cpufunc.h>
#include <util/atomic.h>
#include <stdint.h>

//static uint32_t seconds;

//static uint32_t getSeconds() {
//    ATOMIC_BLOCK(ATOMIC_RESTORESTATE) {
//        return seconds;
//    }
//    return 0;
//}

//ISR(TCA0_OVF_vect) {
//    seconds += 1;
//}

//int main(void) {
//    while (true) {
//        if (getSeconds() > 100) {
//            GPR_GPR0 = 0x01;            
//        }
//    }
//}
 
static void isr() __asm__("__vector_5") __attribute__ ((__signal__, __used__, __externally_visible__)); 
void isr() {
    // ...
}
int main() {while(true){}}
