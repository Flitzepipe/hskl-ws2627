#include <cstdint>
#include <cstddef>

using namespace std::literals;

constexpr uintptr_t registerAdress{0x0400};
volatile std::byte* const mcuRegister = reinterpret_cast<volatile std::byte*>(registerAdress);

uint8_t g;

int main() {
    while(true) {
        ++g;
        if (g > 10) *mcuRegister = 1_byte;
    }
}
