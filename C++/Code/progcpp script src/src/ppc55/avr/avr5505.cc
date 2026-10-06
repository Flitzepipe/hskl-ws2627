#include <avr/interrupt.h>
#include <atomic>
#include <avr/memory.h>

//[main
namespace {
    int v; // <> Übersetzungseinheit-globale Variable `v` wird nebenläufig, gemeinsam genutzt von `isr()` und `main()`
    
    void isr() // <> Kann diese Funktion wiederum von _anderen_ Interrupt-Service-Routinen unterbrochen werden?
    { // <> Weil diese Funktion nur übersetzungseinheit-global ist _und_ hier nicht benutzt wird, wird sie nicht erzeugt. Es besteht hier auch kein Zusammenhang zu einer Hardware-Komponente und dessen Interrupt-Möglichkeiten.
        v += 1; // <> Es kann nicht davon ausgegangen werden, dass dieses RMW _atomar_ stattfindet.
    }
}

int main() {
    while(true) {
        // <> Der folgende Code kann durch einen Interrupt _unterbrochen_ werden: somit findet die Ausführung der `isr()` _nebenläufig_ statt.
        if (v == 42) { // <> Es kann nicht davon ausgegangen werden, dass das Lesen von `v` _atomar_ stattfindet. Weiterhin besteht hier ggf. ein semantisches Problem, weil natürlich auch das folgende Inkrement nicht atomar mit dem Vergleich stattfindet, also auch andere Werte als `43` entstehen können.
            v += 1; // <> Es kann nicht davon ausgegangen werden, dass dieses RMW _atomar_ stattfindet.
        }
    }    
}
//]
