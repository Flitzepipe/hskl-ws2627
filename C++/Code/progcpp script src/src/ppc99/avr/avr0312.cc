#include <stdint.h>

constexpr uint8_t BitValue = 1 << 1; // produces bst/bld instruction for avr
//constexpr uint8_t BitValue = 1 << 2; // produces and/and/or sequence

typedef uint8_t value_type;
value_type a, b;

//value_type merge1(value_type dst, value_type src) {
//    return (src & value_type{BitValue}) | (dst & ~value_type{BitValue});    
//}

//value_type merge2(value_type dst, value_type src) {
//    dst ^= (dst ^ src) & value_type{BitValue};
//    return dst;
//}

//template<typename T>
//T merge3(T dst, const T& src) __attribute__((noinline));

template<typename T>
T merge3(T dst, const T& src) {
    return (src & T{BitValue}) | (dst & ~T{BitValue});    
}

int main() {
//    a = merge1(a, b);
//    a = merge2(a, b);
    a = merge3(a, b);
}