#include <type_traits>
#include <cstdint>

//[concept
template<typename T>
concept FloatingPoint = std::is_floating_point_v<T>;

template<typename T>
concept Unsigned = std::is_unsigned_v<T>;
//]
//[A
template<typename T>
struct A; // <> Nur Deklaration des allgemeines Klassentemplate `A`: damit ist eine Instanziierung nicht möglich.

template<FloatingPoint T>
struct A<T> { // <> (Vollständige) Spezialisierung durch den Constraint `FloatingPoint`
};

template<Unsigned T>
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
