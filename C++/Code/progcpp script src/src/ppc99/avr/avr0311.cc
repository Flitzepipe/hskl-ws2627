#include <cstdint>
#include <cstddef>
#include <type_traits>
#include <utility>

constexpr auto NumberOfTests = 8;

struct Algo {
    struct AndOr {};
    struct ExOr{};
};

template<typename T>
struct numberOfBits : std::integral_constant<uint8_t, sizeof(T) * 8> {};

template<auto N, typename A, typename T>
void merge(T& dst, const T& src) {
    asm(";merge");
    using RT = typename std::remove_cv<T>::type;
    static_assert(N < numberOfBits<T>::value);
    if constexpr(std::is_same<A, Algo::AndOr>::value) {
        dst = (src & RT{1 << N}) | (dst & ~RT{1 << N});    
    }
    else if constexpr(std::is_same<A, Algo::ExOr>::value){
        dst ^= (dst ^ src) & RT{1 << N};
    }
    else {
        static_assert(sizeof(A) == 0, "wrong algorithm");           
    }
}

typedef uint8_t value_type;
volatile value_type var_old, var_new;

template<typename A, size_t... II>
void tests(std::index_sequence<II...>) {
    (merge<II, A>(var_new, var_old), ...);
}

using bitsToTest = std::make_index_sequence<NumberOfTests>;

int main() {
    tests<Algo::AndOr>(bitsToTest{});    
    tests<Algo::ExOr>(bitsToTest{});    
}