#define NDEBUG
#include <cstdint>
#include <vol_access>
#include <type_traits>
#include <atomic>

#include <avr/interrupt.h>
#include <util/atomic.h>

template<typename Handler = void>
struct ScopedInterruptDisable;
template<typename Handler>
struct ScopedInterruptDisable {
    ScopedInterruptDisable() {
       Handler::disableInterrupt();
    }
    ~ScopedInterruptDisable() {
        Handler::enableInterrupt();
    }
};
  
template<>
struct ScopedInterruptDisable<void> {
    static inline constexpr auto cpu = AVR::getBaseAddr<AVR::Cpu>;
    ScopedInterruptDisable() {
        asm volatile("cli" : : :); // prevents reorder among other volatile accesses, but no memory barrier
    }
    ~ScopedInterruptDisable() {
        cpu()->sreg = save; // prevents reorder among other volatile accesses, but no memory barrier
    }
private:
    const uint8_t save{cpu()->sreg};
};

using std::experimental::volatile_load;
using std::experimental::volatile_store;
   
template<auto N = 0>
struct Usart {
    struct RxHandler {
        static inline constexpr uint8_t rxInterruptFlag = 0b1000'0000;
        friend class Usart<N>;
        static void isr() {
            counter += 1;
            if (counter > 100) {
                flag = true;
            }
        }
        static void disableInterrupt() {
            USART0.CTRLA &= ~rxInterruptFlag; // RMW Aufwand
        }
        static void enableInterrupt() {
            USART0.CTRLA |= rxInterruptFlag; // RMW Aufwand
        }
    private:  
        static inline bool flag{};  
//        static inline std::atomic<uint16_t> counter{};
        static inline uint16_t counter{};
    };
//    static uint16_t count() {
//        return volatile_load(RxHandler::counter);
////        return RxHandler::counter;
//    }
    static uint16_t count() {
        ScopedInterruptDisable<> lock;
        return volatile_load(RxHandler::counter);
    }
    static void func() {
        for(uint8_t i = 0; i < 20; i++) {
            g += count();
//            if (volatile_load(RxHandler::flag)) {
//                volatile_store(RxHandler::flag, false);
//            }
        }
    }
private:
    static inline uint16_t g{};
};

int main() {
    Usart<0>::func();
}

ISR(USART0_RXC_vect) {
    Usart<0>::RxHandler::isr();
}

