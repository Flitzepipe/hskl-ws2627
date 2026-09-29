#include <avr/interrupt.h>
#include <avr/memory.h>

#include <type_traits>

namespace etl {
    struct UnSafe;
    
    template<typename> class atomic;
    
    template<>
    struct atomic<uint16_t> final {
        template<typename C = void>
        uint16_t fetch_add(const uint16_t v) {
            if constexpr(std::is_same_v<C, UnSafe>) {
                Memory::Barrier b;
                return mValue += v;
            }
            else {
                Atomic::DisableInterruptsRestore di;
                return mValue += v;
            }
        }
        void onValue(const uint16_t v, const auto f) {
            Atomic::DisableInterruptsRestore di;
            if (mValue == v) {
                f(mValue);
            }
        }
    private:
        uint16_t mValue;
    };
    template<>
    struct atomic<uint8_t> final {
        template<typename C = void>
        uint8_t fetch_add(const uint8_t v) {
            if constexpr(std::is_same_v<C, UnSafe>) {
                Memory::Barrier b;
                return mValue += v;
            }
            else {
                Atomic::DisableInterruptsRestore di; // memory-barrier
                return mValue += v;
            }
        }
        void onValue(const uint8_t v, const auto f) {
            Memory::Barrier b;
            if (mValue == v) {
                f(mValue);
            }
        }
    private:
        uint8_t mValue;
    };
}

//[main
namespace {
    etl::atomic<uint16_t> v; // <> Übersetzungseinheit-globale Variable `v` wird nebenläufig, gemeinsam genutzt von `isr()` und `main()`
    etl::atomic<uint8_t> v2; // <> Übersetzungseinheit-globale Variable `v` wird nebenläufig, gemeinsam genutzt von `isr()` und `main()`
}

void isr() 
    __asm__("__vector_5") // <> Verändert den Namen zu `__vector_5`: Funktionen mit diesen speziellen Namen werden vom Linker in die Interrupt-Vector-Tabelle eingetragen.
    __attribute__ ((__signal__, __used__, __externally_visible__)); // <> Attribute können nur bei der Deklaration angegeben werden.
void isr() {
    v.fetch_add<etl::UnSafe>(1); // <> Es kann nicht davon ausgegangen werden, dass dieses RMW _atomar_ stattfindet.
}

int main() {
    while(true) {
        v.onValue(42, [](auto& v){
            v += 1; 
        });      
    }    
}
//]
