#include <avr/cpufunc.h>
#include <util/atomic.h>
#include <stdint.h>

template<typename T>
volatile T& volatile_access(T& v) {
    return static_cast<volatile T&>(v);
}

namespace {
    char global_variable = 0;
    char global_variable2 = 0;
}

void bar() {
    global_variable2 += 1;
}

void foo(){
    global_variable += 1;
//    VPORTA.OUT = global_variable;
//    VPORTC.OUT = global_variable2;
}

int main(){
    while(true){
//        _MemoryBarrier();
//        VPORTA.OUT = ++volatile_access(global_variable);
//        VPORTA.OUT = ++global_variable;
        global_variable2 = ++global_variable;
//        VPORTC.OUT = ++global_variable2;
//        if (global_variable > 20) {
//            global_variable2 = 10;
//        }
//        if (global_variable > 40) {
//            global_variable2 = 11;
//        }
    }
}
