#include <avr/interrupt.h>
#include <atomic>
#include <avr/memory.h>

//[f
void f() {} // <> Definition: aber `f()` hat keinen Zugriff auf `v`. 
//]
