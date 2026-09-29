#include <avr/cpufunc.h>
#include <avr/interrupt.h>
#include <util/atomic.h>
#include <stdint.h>

namespace Memory {
    template<typename T>
    volatile T& volatile_access(T& v) {
        return static_cast<volatile T&>(v);
    }
    struct Barrier final {
        inline Barrier() {
            _MemoryBarrier();
        }
        inline ~Barrier() {
            _MemoryBarrier();
        }
    };
    void barrier(const auto f) {
        Barrier b;
        f();
    }
}

namespace Atomic {
    struct DisableInterruptsRestore final {
        inline DisableInterruptsRestore() {
            cli(); // with barrier
        }
        inline ~DisableInterruptsRestore() {
            SREG = save;
            __asm__ volatile ("" ::: "memory");  // barrier added
        }
    private:
        uint8_t save{SREG};
    };
    
    void access(const auto f) {
        DisableInterruptsRestore di;
        Memory::barrier([&]{
            f();
        });
    }
}

namespace Devices {
    template<uint8_t N>
    struct TimerB {
        static inline void isr() {
//            Memory::barrier([]{
                ++a;
                if (!a) ++b;        
//            });
        }
    private:
        inline static uint8_t a;
        inline static uint8_t b;
    };
}

using devb0 = Devices::TimerB<0>;
using devb1 = Devices::TimerB<1>;

ISR(TCB0_INT_vect) {
    devb0::isr();
}
ISR(TCB1_INT_vect) {
    devb1::isr();
}

int main(void) {
    while (true) {
    }
}
