#include <avr/interrupt.h>
#include <atomic>
#include <avr/memory.h>

// Mist
// nach: https://erdani.org/publications/cuj-02-2001.php.html

struct UnSafe;

struct SHM final {
    template<typename C = void>
    int fetch_add(const int v) volatile {
        if constexpr(std::is_same_v<C, UnSafe>) {
            Memory::Barrier b;
            const auto t = mValue + v;
            mValue = t;
            return t;
        }
        else {
            Atomic::DisableInterruptsRestore di;
            const auto t = mValue + v;
            mValue = t;
            return t;
        }
    }
    void onValue(const int v, const auto f) volatile const {
        Atomic::DisableInterruptsRestore di;
        auto& t = const_cast<int&>(mValue);
        if (t == v) {
            f(t);
        }
    }
private:
    int mValue{0};
};

//[main
namespace {
    volatile SHM v; // <> Übersetzungseinheit-globale Variable `v` wird nebenläufig, gemeinsam genutzt von `isr()` und `main()`.
}

void isr() 
__asm__("__vector_5") // <> Verändert den Namen zu `__vector_5`: Funktionen mit diesen speziellen Namen werden vom Linker in die Interrupt-Vector-Tabelle eingetragen.
__attribute__ ((__signal__, __used__, __externally_visible__)); // <> Attribute können nur bei der Deklaration angegeben werden.
void isr() {
    v.fetch_add<UnSafe>(1); 
}

int main() {
    while(true) {
        v.onValue(42, [](auto& v){
            v += 1; 
        });
    }    
}
//]
