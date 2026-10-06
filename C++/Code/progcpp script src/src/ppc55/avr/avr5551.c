#include <avr/io.h>
#include <avr/cpufunc.h>
#include <avr/interrupt.h>
#include <stdint.h>

// 1) register vs structure mapping
// 2) non-inline function
// 3) allg. memory-barrier
// 4) spezielle memory-barrier

// a) Anwendung sei/cli mit Zustandssicherung: SREG vs Cpu_t
// b) ATOMIC_BLOCK

typedef struct C {
    volatile uint8_t r; 
} C_t;

#define VC (*(C_t *) 0x0008) 

#define C_r  (*(volatile uint8_t *)(0x0008))

static uint16_t g; 

int main() {
    for(uint8_t i = 0; i < 20; i++) {
        ++g;
//        VC.r; // <1> OK
//        C_r; // <2> suppresses optimization
//        VPORTC.DIR; // <1> OK
//        VPORTC_DIR; // <2> suppresses optimization
    }
}

