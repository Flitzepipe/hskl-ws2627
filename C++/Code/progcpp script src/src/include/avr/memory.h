#pragma once

#include <avr/cpufunc.h>
#include <util/atomic.h>

namespace AVR {
    template<typename Component>
    constexpr inline Component* getBaseAddr() {
        return reinterpret_cast<Component*>(Component::address);
    }
    
    struct Cpu { // this is missing in avr headers
        volatile uint8_t r0_3[4];
        volatile uint8_t ccp;
        volatile uint8_t r5_a[6];
        volatile uint8_t rampz;
        volatile uint8_t rc;
        volatile uint16_t sp;
        volatile uint8_t sreg;

        static inline constexpr uintptr_t address = 0x0030;
    };
}

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
    static inline constexpr auto cpu = AVR::getBaseAddr<AVR::Cpu>;
    struct DisableInterruptsRestore final {
        inline DisableInterruptsRestore() {
            asm volatile("cli" : : :); // prevents reorder among other volatile accesses, but no memory barrier
        }
        inline ~DisableInterruptsRestore() {
            cpu()->sreg = save; // prevents reorder among other volatile accesses, but no memory barrier
        }
    private:
        const uint8_t save{cpu()->sreg};
    };
    
    void access(const auto f) {
        DisableInterruptsRestore di; 
//        Memory::barrier([&]{
            f();
//        });
    }
}

