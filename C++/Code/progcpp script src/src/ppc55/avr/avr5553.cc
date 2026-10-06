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
    Usart() = delete;
    struct RxHandler {
        RxHandler() = delete;
        // Policy: innerhalb der isr() nur Interrupt::volatile_atomic<> verwenden (Vorraussetzung: MemoryBarrier um isr());
        static void isr() {
            counter += 1;
            if (counter > 100) {
                flag = true;
            }
        }
    private:
        static inline Interrupt::volatile_atomic<bool> flag;  
        static inline Interrupt::volatile_atomic<uint16_t> counter;
    public:
        // Policy: außerhalb der isr() nur die volatile& verwenden: damit volatile-access und(!) Atomarität
        static inline volatile auto& vFlag{flag};
        static inline volatile const auto& vCounter{counter};
    };
    static void func() {    
        for(uint8_t i = 0; i < 20; i++) {
            g1 += RxHandler::vCounter;
            if (RxHandler::vFlag) {
                RxHandler::vFlag = false;
                ++g2;
            }
//            RxHandler::vFlag.on(true, Interrupt::non_atomic{}, [](volatile bool& v){
//                v = false;
//                ++g2;            
//            });
//            {
//                Atomic::DisableInterruptsRestore di;
//                uint16_t v = RxHandler::vCounter.value(Interrupt::non_atomic{});
//                if (v > 100) {
//                    RxHandler::vCounter.value(Interrupt::non_atomic{}) = --v;
//                }
//            }
        }
    }
private:
    static inline uint16_t g1{0}; 
    static inline uint16_t g2{0}; 
};

int main() {
    Usart<0>::func();
}

ISR(USART0_RXC_vect) {
    Memory::Barrier barrier;
    Usart<0>::RxHandler::isr();
}

