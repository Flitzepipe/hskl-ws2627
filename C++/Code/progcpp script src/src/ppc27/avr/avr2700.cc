#include <cstdint>
#include <cstddef>

//using a_t = std::byte;
using a_t = float;

a_t foo(uint16_t* const f, a_t* const i) { 
    *i = a_t{1};               
    *f = 0;            
    return *i;
}

int main() {
    a_t x{0};
    
    auto y = foo(reinterpret_cast<uint16_t*>(&x), &x);
    
    return static_cast<int>(y);
}
