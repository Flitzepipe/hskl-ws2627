#include <avr/interrupt.h>
#include <atomic>
#include <avr/memory.h>

namespace {
    int v; // <> Übersetzungseinheit-globale Variable `v` wird nebenläufig, gemeinsam genutzt von `isr()` und `main()`
}

void isr() 
    __asm__("__vector_5") // <> Verändert den Namen zu `__vector_5`: Funktionen mit diesen speziellen Namen werden vom Linker in die Interrupt-Vector-Tabelle eingetragen.
    __attribute__ ((__signal__, __used__, __externally_visible__)); // <> Attribute können nur bei der Deklaration angegeben werden.
void isr() { 
    _MemoryBarrier(); // <> Fügt eine _Compiler-memory-barrier_ ein.
    v += 1; // <> Es kann nicht davon ausgegangen werden, dass dieses RMW _atomar_ stattfindet.
}

//[main
int main() {
    while(true) {
        _MemoryBarrier(); // <> Fügt eine _Compiler-memory-barrier_ ein.
        // <> Der folgende Code kann durch einen Interrupt _unterbrochen_ werden: somit findet die Ausführung der `isr()` _nebenläufig_ statt.
        if (v == 42) { // <> Es kann nicht davon ausgegangen werden, dass das Lesen von `v` _atomar_ stattfindet. Weiterhin besteht hier ggf. ein semantisches Problem, weil natürlich auch das folgende Inkrement nicht atomar mit dem Vergleich stattfindet, also auch andere Werte als `43` entstehen können.
            v += 1; // <> Es kann nicht davon ausgegangen werden, dass dieses RMW _atomar_ stattfindet.
        }
    }    
}
//]
