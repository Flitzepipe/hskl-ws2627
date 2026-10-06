#include <type_traits>
#include <cstdint>

//[concept
template<typename T>
concept FloatingPoint = std::is_same_v<T, float> || std::is_same_v<T, double>;

template<typename T>
concept Unsigned = std::is_same_v<T, uint8_t> || std::is_same_v<T, uint16_t>;
//]
//[A1
template<typename T>
requires FloatingPoint<T>
struct A {
};
//]

//[A2
#if 0 //-
template<typename T>
requires Unsigned<T> // <> Ein Redeklaration einer Klasse mit anderen Constraints ist _nicht_ möglich.
struct A {
};
#endif //-
//]

int main() {
    A<float> a1;
    A<double> a2;
//    A<uint8_t> a3; // <> nicht möglich
}
