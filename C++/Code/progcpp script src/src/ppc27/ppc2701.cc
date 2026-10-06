#include <iostream>
#include <cstdint>

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wstrict-aliasing"

int foo(uint16_t& u, int& i) { 
    i = 1;               
    u = 0;            
    return i;
}

int main() {
    int x{0};
    
    std::cout << x << "\n";   // Expect 0
    x = foo(reinterpret_cast<uint16_t&>(x), x);
//    x = foo(x, x);
    std::cout << x << "\n";   // Expect 0?
}
#pragma GCC diagnostic pop
