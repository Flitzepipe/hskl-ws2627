#define NDEBUG
#include <cstdint>
#include <vol_access>
#include <type_traits>
#include <atomic>
#include <avr/interrupt.h>
#include <util/atomic.h>

namespace {
    uint16_t g;
    std::atomic<uint8_t> counter;
    volatile auto& vCounter{counter};
      
    inline void isr() {
        counter.operator++<std::UnSafe>();
    }
}

int main() {
    for(uint8_t i = 0; i < 20; i++) {
        g += vCounter;
    }
}
 
ISR(USART0_RXC_vect) {
    isr();
}


