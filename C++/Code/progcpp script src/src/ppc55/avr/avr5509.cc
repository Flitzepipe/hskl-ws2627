#include <avr/interrupt.h>
#include <atomic>
#include <avr/memory.h>

//[main
namespace {
    volatile // <>  `volatile` ist hier *falsch*
    int v; // <> Übersetzungseinheit-globale Variable `v` wird nebenläufig, gemeinsam genutzt von `isr()` und `main()`.
}

void isr() 
__asm__("__vector_5") // <> Verändert den Namen zu `__vector_5`: Funktionen mit diesen speziellen Namen werden vom Linker in die Interrupt-Vector-Tabelle eingetragen.
__attribute__ ((__signal__, __used__, __externally_visible__)); // <> Attribute können nur bei der Deklaration angegeben werden.
void isr() {
    v += 1; // <> Es kann nicht davon ausgegangen werden, dass dieses RMW _atomar_ stattfindet.
}

int main() {
    while(true) {
        Atomic::DisableInterruptsRestore di; // <> Abschalten der Nebenläufigkeit: happens-before Relation
        if (v == 42) { // <> Dieser Wert kann nicht als stabil gesehen werden, daher muss ...
            v += 1; // <> ... hier ein RMW ausgeführt werden, statt einfach `43` in `v` zu speichern.
        }
    }    
}
//]
