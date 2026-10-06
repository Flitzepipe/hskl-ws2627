#include <stdint.h>
#include <util/atomic.h>
//#include <signal.h> // do not include that stub: Fehler in der DAtei: sig_atomic_t wird als Variable definiert.

typedef signed char sig_atomic_t; // __SIG_ATOMIC_TYPE__

#include <avr/interrupt.h>

//#define USE_VOLATILE_VAR
#define USE_BARRIER
//#define USE_VOLACCESS
//#define USE_ATOMIC_BLOCK

#ifdef USE_VOLACCESS
# define ACCESS_ONCE(x) (*(volatile typeof(x) *)&(x))
#endif

#ifdef USE_VOLATILE_VAR
static volatile sig_atomic_t flag;  
#else
static sig_atomic_t flag;
#endif

static uint8_t g; // the operations on g could be optimized out completely

void func(void) {
    for(uint8_t i = 0; i < 20; i++) {
        ++g; // Bei VOL_ACCESS wird diese Operation zu g+=20 zusammengefasst außerhalb der Schleife
//        --g; // damit wird g komplett wegoptimiert (was aber auch ohne dies Statement passieren sollte)
#ifdef USE_BARRIER
//        __asm__ __volatile__ ("" : : : "memory");
        __asm__ __volatile__ ("" : "+m" (flag)); // hoist the load, but does not sink the store out of the loop
#endif
#ifdef USE_VOLACCESS
        if (ACCESS_ONCE(flag)) {
            ACCESS_ONCE(flag) = 0;
        }
#endif
#if defined(USE_VOLATILE_VAR) || defined(USE_BARRIER)
        if (flag) {
            flag = 0;
        }
#endif
#ifdef USE_ATOMIC_BLOCK
        ATOMIC_BLOCK(ATOMIC_RESTORESTATE) { // not needed
            if (flag) {
                flag = 0;
            }
        }
#endif
#ifdef USE_BARRIER
//        __asm__ __volatile__ ("" : : : "memory");
        __asm__ __volatile__ ("" : "+m" (flag)); // hoist the load, but does not sink the store out of the loop
#endif
    }
}

ISR(USART0_RX_vect) {
#ifdef USE_BARRIER
//    __asm__ __volatile__ ("" : : : "memory");
    __asm__ __volatile__ ("" : "+m" (flag)); // hoist the load, but does not sink the store out of the loop
#endif
#ifdef USE_VOLACCESS
    ACCESS_ONCE(flag) = 1;
#endif
#if defined(USE_VOLATILE_VAR) || defined(USE_BARRIER)
    ++g;
    flag = 1;
#endif
#ifdef USE_BARRIER
//    __asm__ __volatile__ ("" : : : "memory");
     __asm__ __volatile__ ("" : "+m" (flag)); // hoist the load, but does not sink the store out of the loop
#endif
}

