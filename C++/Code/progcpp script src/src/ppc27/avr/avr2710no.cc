#include <cstdint>
#include <cstddef>

struct S1 {
    std::byte value{};
};
struct S2 {
    std::byte value{};
};

struct C1 {
    inline static constexpr uintptr_t address{0x20};
    void operator=(const std::byte v) {
        *reinterpret_cast<std::byte*>(address) = v;    
    }
    operator std::byte() const {
        return *reinterpret_cast<std::byte*>(address);
    }
};

struct C2 {
    inline static constexpr uintptr_t address{0x30};
    void operator=(const std::byte v) {
        *reinterpret_cast<std::byte*>(address) = v;    
    }    
    operator std::byte() const {
        return *reinterpret_cast<std::byte*>(address);
    }
};

// may alias -> reread value
std::byte foo(S1* const a, S1* const b) {
    a->value = std::byte{1};
    b->value = std::byte{2};
    return a->value;
}

// no aliasing, don't reread
std::byte foo(S1* const a, S2* const b) {
    a->value = std::byte{1};
    b->value = std::byte{2};
    return a->value;
}

// may alias -> reread
std::byte foo(std::byte* const a, std::byte* const b) {
    *a = std::byte{1};
    *b = std::byte{2};
    return *a;
}

// no aliasing, don't reread
std::byte foo(C1* const a, C2* const b) {
    *a = std::byte{1};
    *b = std::byte{2};
    return std::byte{*a};
}

// may alias
// write to constant addresses -> only second write, no reread
std::byte foo(C1* const a, C1* const b) {
    *a = std::byte{1};
    *b = std::byte{2};
    return std::byte{*a};
}

int main() {
    C1 c1;    
    C2 c2;    
    return (int)foo(&c1, &c2);
//    std::byte* const r1 = reinterpret_cast<std::byte*>(0x20);
//    std::byte* const r2 = reinterpret_cast<std::byte*>(0x30);
//    return foo(r1, r2);
}
