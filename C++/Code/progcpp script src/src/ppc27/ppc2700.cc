#include <iostream>
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wstrict-aliasing"

int foo(float* const f, int* const i) { 
    *i = 1;               
    *f = 0.f;            
    return *i;
}

int main() {
    int x{0};
    
    std::cout << x << "\n";   // Expect 0
    x = foo(reinterpret_cast<float*>(&x), &x);
    std::cout << x << "\n";   // Expect 0?
}
#pragma GCC diagnostic pop
