#define NDEBUG
#include <cstdint>
#include <vol_access>
#include <avr/interrupt.h>
#include <util/atomic.h>

//#define USE_BARRIER
#define USE_VOLACCESS

template<auto N = 0>
struct Usart {
    struct RxHandler {
        friend class Usart<N>;
        static void isr() {
#ifdef USE_VOLACCESS
            std::experimental::volatile_store(flag, true);
#endif
#ifdef USE_BARRIER
            __asm__ __volatile__ ("" : "+m" (flag)); // funktioniert nicht korrekt, kein vollst. Optimierung
            flag = true;
#endif
        }
        static void disableInterrupt() {
            
        }
        static void enableInterrupt() {
            
        }
    private:
        static inline bool flag{};  
    };
    static void func() {
        for(uint8_t i=0; i<20; i++) {
            ++g;
//            --g;
#ifdef USE_BARRIER
            __asm__ __volatile__ ("" : "+m" (RxHandler::flag)); // funktioniert nicht korrekt, kein vollst. Optimierung
            if (RxHandler::flag) {
                RxHandler::flag = false;
            }
#endif
#ifdef USE_VOLACCESS
                if (std::experimental::volatile_load(&RxHandler::flag)) {
                    std::experimental::volatile_store(RxHandler::flag, false);
            }
#endif
        }
    }
private:
    static inline uint8_t g{};
};

int main() {
    Usart<0>::func();
}

ISR(USART0_RX_vect) {
    Usart<0>::RxHandler::isr();
}

