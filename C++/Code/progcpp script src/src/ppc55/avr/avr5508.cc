#include <avr/interrupt.h>
#include <avr/memory.h>

//[main
namespace {
    int v; // <> Übersetzungseinheit-globale Variable `v` wird nebenläufig, gemeinsam genutzt von `isr()` und `main()`
    int x;
}

void isr() 
    __asm__("__vector_5") // <> Verändert den Namen zu `__vector_5`: Funktionen mit diesen speziellen Namen werden vom Linker in die Interrupt-Vector-Tabelle eingetragen.
    __attribute__ ((__signal__, __used__, __externally_visible__)); // <> Attribute können nur bei der Deklaration angegeben werden.
void isr() {
    _MemoryBarrier();
    v += 1; // <> Es kann nicht davon ausgegangen werden, dass dieses RMW _atomar_ stattfindet.
}

int main() {
    while(true) {
        ++x;
        Atomic::access([]{
            if (v == 42) { 
                v += 1; 
            }
        });
    }    
}
//]
