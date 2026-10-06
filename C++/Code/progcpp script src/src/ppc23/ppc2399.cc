//#include <iostream>
#include <cstdint>
#include <type_traits>
#include <bit>

#include <cstdlib>

struct C {
    static_assert(sizeof(C*) == sizeof(uintptr_t));
    inline static constexpr uintptr_t address = 0x100;
//    inline static constexpr C* ptr1 = std::bit_cast<C*>(address);
    inline static /*constexpr*/ C* ptr2 = reinterpret_cast<C*>(address);
};


struct A {};
struct B {};

#if 1

template<typename T>
struct X {
    int value() const {
        if constexpr(std::is_same_v<T, A>) {
            return x1 + x2;
        }
        else {
            return x1;
        }
    }
private:
    int x1{0};    
    int x2{1};    
};

int* p();

template<int* P>
struct F {
    friend int* p() {
        return P;
    }
};

#endif

#if 0
template<typename T>
struct Base {};

template<>
struct Base<A> {
    int x2{1};    
};

template<typename T>
struct X : private Base<T> {
    int value() const {
        if constexpr(std::is_same_v<T, A>) {
            return x1 + Base<T>::x2;
        }
        else {
            return x1;
        }
    }
private:
    int x1{0};    
};
#endif

#if 0
namespace detail {

    struct XA {
        int x1{0};    
        int x2{0};    
    };
    
    struct XB {
        int x1{0};  
    };   
}

template<typename T>
struct X : private std::conditional_t<std::is_same_v<T, A>, detail::XA, detail::XB>{
    int value() const {
        if constexpr(std::is_same_v<T, A>) {
            return detail::XA::x1 + detail::XA::x2;
        }
        else {
            return detail::XB::x1;
        }
    }   
};
#endif

X<A> a;
X<B> b;

template struct F<&a.x1>;

int main() {
    *p() = 42;
    
    
//    std::cout << sizeof(a) << '\n';
//    std::cout << sizeof(b) << '\n';
    return a.value() + b.value();
}

