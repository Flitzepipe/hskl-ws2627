#include <type_traits>
#include <cstdint>

//[concept
template<typename T>
concept FloatingPoint = std::is_same_v<T, float> || std::is_same_v<T, double>;

template<typename T>
concept Unsigned = std::is_same_v<T, uint8_t> || std::is_same_v<T, uint16_t>;
//]

//[A
template<typename T>
requires FloatingPoint<T>
struct A {
};
//]

int main() {
    A<float> a1; // <> Requirement ist erfüllt
    A<double> a2;
#if 0 //-
    A<int> a3; // <> nicht möglich wegen Requirement `FloatingPoint`
#endif //-
}
