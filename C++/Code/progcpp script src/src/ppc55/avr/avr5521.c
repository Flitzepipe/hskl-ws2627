#include <stdbool.h>
#include <avr/interrupt.h>

//- s.a. avr5509.cc

static
volatile // `volatile` ist unnötig, denn es verhindert die sinnvolle Optimierung im KA
int v;  

void isr() __asm__("__vector_5") __attribute__ ((__signal__, __used__, __externally_visible__)); 
void isr() {
    v += 1; // explizite memory-barrier unnötig
}

int main(void) {
    while(true) {
        // KA Anfang (wegen nicht-atomarer Operationen auf DT `int`
        cli(); // beinhaltet notwendigerweise eine memory-barrier, damit die Operationen des KA nicht nach außen verschoben werden können.
        if (v == 42) {  
            v += 1; 
        }
        sei(); // beinhaltet notwendigerweise eine memory-barrier, damit die Operationen des KA nicht nach außen verschoben werden können.
        // KA Ende
    }    
}
