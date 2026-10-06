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
struct A; // <> Nur Deklaration des allgemeines Klassentemplate `A`: damit ist eine Instanziierung nicht möglich.

template<typename T>
requires FloatingPoint<T>
struct A<T> { // <> (Vollständige) Spezialisierung durch den Constraint `FloatingPoint`
};

template<typename T>
requires Unsigned<T>
struct A<T> { // <> (Vollständige) Spezialisierung durch den Constraint `Unsigned`
};
//]

int main() {
    A<float> a1;
    A<double> a2;
    A<uint8_t> a3;
    A<uint16_t> a4;
    
#if 0
    A<int> a5; // <> nicht möglich
#endif
}
