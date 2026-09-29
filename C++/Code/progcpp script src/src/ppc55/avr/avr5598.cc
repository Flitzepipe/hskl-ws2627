#include <avr/cpufunc.h>
#include <util/atomic.h>
#include <stdint.h>

template<typename T>
volatile T& volatile_access(T& v) {
    return static_cast<volatile T&>(v);
}

namespace Atomic {
    struct DisableInterruptsRestore final {
        inline DisableInterruptsRestore() {
            cli(); // memory-barrier inside
        }
        inline ~DisableInterruptsRestore() {
            SREG = save; // only-volatile
            __asm__ volatile ("" ::: "memory");  // barrier added
        }
    private:
        uint8_t save{SREG};
    };

    struct DisableInterruptsRestoreNoBarrier final {
        inline DisableInterruptsRestoreNoBarrier() {
            __asm__ __volatile__ ("cli"); // only volatile, no barrier
        }
        inline ~DisableInterruptsRestoreNoBarrier() {
            SREG = save; // only volatile, no barrier
        }
    private:
        uint8_t save{SREG};
    };
}

namespace {
    uint32_t seconds;
    
    uint32_t getSeconds() {
//        __atomic_load_n(&seconds, __ATOMIC_SEQ_CST); // nicht auf AVR
        Atomic::DisableInterruptsRestoreNoBarrier di; // volatile
        return volatile_access(seconds);// volatile
    }
//    uint32_t getSeconds() {
//        Atomic::DisableInterruptsRestore di; // is general memory-barrier
//        return seconds;
//    }
//    uint32_t getSeconds() {
//        ATOMIC_BLOCK(ATOMIC_RESTORESTATE) {
//            return seconds;
//        }
//        return 0;
//    }
}

ISR(TCA0_CMP1_vect) {
    seconds += 1;
}

int main(void) {
    while (true) {
        if (getSeconds() > 100) {
            GPR_GPR0 = 0x01;            
        }
    }
}
