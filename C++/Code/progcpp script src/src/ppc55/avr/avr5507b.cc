#include <avr/interrupt.h>
#include <atomic>
#include <avr/memory.h>

//[ns
namespace {
    int v; // <> Übersetzungseinheit-globale Variable `v` wird nebenläufig, gemeinsam genutzt von `isr()` und `main()`
    void f(); // <> Deklaration einer nur lokal sichtbaren _non-inline_ Funktion `f()`
}
void isr() __asm__("__vector_5") __attribute__ ((__signal__, __used__, __externally_visible__)); 
void isr() { 
    v += 1; // <> Es kann nicht davon ausgegangen werden, dass dieses RMW _atomar_ stattfindet.
}
//]
//[main
int main() {
    while(true) {
        f(); // <> Der Aufruf einer non-inline Funktion unterbindet hier die _Escape-Analyse_ des Compilers: als Konsequenz kann der Compiler hier nicht mehr davon ausgehen, dass `v` unverändert bleibt.
        // <> Der folgende Code kann durch einen Interrupt _unterbrochen_ werden: somit findet die Ausführung der `isr()` _nebenläufig_ statt.
        if (v == 42) { // <> Es kann nicht davon ausgegangen werden, dass das Lesen von `v` _atomar_ stattfindet. Weiterhin besteht hier ggf. ein semantisches Problem, weil natürlich auch das folgende Inkrement nicht atomar mit dem Vergleich stattfindet, also auch andere Werte als `43` entstehen können.
            v += 1; // <> Es kann nicht davon ausgegangen werden, dass dieses RMW _atomar_ stattfindet.
        }
    }    
}
//]
