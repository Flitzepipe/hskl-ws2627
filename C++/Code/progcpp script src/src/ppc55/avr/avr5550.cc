#define NDEBUG
#include <cstdint>
#include <vol_access>
#include <type_traits>
#include <atomic>
#include <avr/interrupt.h>
#include <util/atomic.h>

#include <avr/isr.h>
 
template<auto N = 0>
struct Usart {
    struct RxHandler {
        static void isr() {
            counter += 1;
            if (counter > 100) {
                flag = true;
            }
        }
    private:
        static inline bool flag{};  
        static inline uint16_t counter{};
    public:
        static inline volatile auto& vFlag{flag};
        static inline volatile auto& vCounter{counter};
    };
    static uint16_t count() {
       return std::atomic_volatile_load(RxHandler::vCounter);
    }
    static void func() {    
        for(uint8_t i = 0; i < 20; i++) {
            g += count();
            if (std::atomic_volatile_load(RxHandler::vFlag)) {
                std::atomic_volatile_store(RxHandler::vFlag, false);
            }
        }
    }
private:
    static inline uint16_t g{};
};

int main() {
    Usart<0>::func();
}

ISR(USART0_RXC_vect) {
    Memory::Barrier barrier;
    Usart<0>::RxHandler::isr();
}

