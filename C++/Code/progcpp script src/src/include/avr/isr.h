#pragma once

#include <concepts>
#include <avr/memory.h>

namespace Interrupt {
    
    struct non_atomic {};
    
    template<typename T>
    class volatile_atomic;
    
    template<std::integral T>
    requires (sizeof(T) > 1)
    class volatile_atomic<T> {
    public:
        constexpr volatile_atomic() = default;
        volatile_atomic(const volatile_atomic&) = delete;
        void operator=(const volatile_atomic&) = delete;
        
        void operator=(const T v) {
            mValue = v;
        }
        void operator=(const T v) volatile {
            Atomic::DisableInterruptsRestore di;
            mValue = v;
        }
        void operator++() volatile {
            Atomic::DisableInterruptsRestore di;
            mValue = mValue + 1; // <> read-modify-write: possible lost-update -> DisableInterrupts
        }
        void operator++() {
            ++mValue;
        }
        void operator+=(const T v) {
            mValue += v;
        }
        void operator+=(const T v) volatile {
            Atomic::DisableInterruptsRestore di;
            mValue = mValue + v; // <> read-modify-write: possible lost-update -> DisableInterrupt
        }
        operator T() const {
            return mValue;
        }
        operator T() const volatile {
            Atomic::DisableInterruptsRestore di;
            return mValue;
        }
        const volatile T& value() const volatile {
            Atomic::DisableInterruptsRestore di;
            return mValue;            
        }
        const T& value() const {
            Atomic::DisableInterruptsRestore di;
            return mValue;            
        }
        volatile T& value(non_atomic) volatile {
            return mValue;
        }
        const volatile T& value(non_atomic) const volatile {
            return mValue;
        }
    private:
        T mValue{}; 
    };
    
    template<typename T>
    requires (sizeof(T) == 1)
    class volatile_atomic<T> {
    public:
        constexpr volatile_atomic() = default;
        
        volatile_atomic(const volatile_atomic&) = delete;
        void operator=(const volatile_atomic&) = delete;
        
        void operator=(const T v) {
            mValue = v;
        }
        void operator=(const T v) volatile {
            mValue = v;
        }
        void operator++() {
            ++mValue; 
        }
        void operator++() volatile {
            Atomic::DisableInterruptsRestore di;
            ++mValue; // <> read-modify-write: possible lost-update -> DisableInterrupts
        }
        operator T() const {
            return mValue;
        }
        operator T() const volatile {
            return mValue;
        }
        void on(const T v, auto f) volatile {
            Atomic::DisableInterruptsRestore di;
            if (mValue == v) {
                f(mValue);
            }
        }
        void on(const T v, non_atomic, auto f) volatile {
            if (mValue == v) {
                f(mValue);
            }
        }
        void on(const T v, auto f) {
            if (mValue == v) {
                f(mValue);
            }
        }
    private:
        T mValue{}; 
    };
}
