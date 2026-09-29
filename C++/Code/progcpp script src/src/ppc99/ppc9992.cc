#include <iostream>
#include <cassert>
#include <type_traits>
#include "../lib/meta.h"
#include "../lib/type_traits.h"

namespace detail {
    template<typename T, typename U>
    struct containing_type;
    
    template<typename T, typename U>
    requires (std::is_signed_v<T> && std::is_signed_v<U>)
    struct containing_type<T, U> {
        constexpr static inline uint8_t bits = std::max(etl::numberOfBits<T>(), etl::numberOfBits<U>());
        using type = etl::signedTypeForBits_t<bits>;        
    };
    template<typename T, typename U>
    requires (std::is_unsigned_v<T> && std::is_unsigned_v<U>)
    struct containing_type<T, U> {
        constexpr static inline uint8_t bits = std::max(etl::numberOfBits<T>(), etl::numberOfBits<U>());
        using type = etl::typeForBits_t<bits>;        
    };
    
}

template<typename T, typename U>
using containing_type_t = typename detail::containing_type<T, U>::type;

template<typename T, typename U>
requires (std::is_integral_v<T> && std::is_integral_v<U> && ((std::is_signed_v<T> && std::is_signed_v<T>) || (std::is_unsigned_v<T> && std::is_unsigned_v<U>)))
struct ClosedOrderedInterval {
    using value_type = containing_type_t<T, U>;
    constexpr ClosedOrderedInterval(T lower, U upper) : mLower{lower}, mUpper{upper} {
        if (mLower > mUpper) {
            using std::swap;
            swap(mLower, mUpper);
        }
        assert(mLower <= mUpper);
    }
    constexpr bool contains(T value) const {
        return (value >= mLower) && (value <= mUpper);
    }
    private:
    value_type mLower;
    value_type mUpper;
};

template<typename T>
struct Width {
    explicit Width(T v) : value{v} {}
    const T value;
};
template<typename T>
struct Left {
    explicit Left(T v) : value{v} {}
    const T value;
};

template<typename T>
struct ClosedInterval {
    using value_type = etl::enclosing_t<T>;

    explicit constexpr ClosedInterval(T left) : mLower{left} {}
    
    explicit constexpr ClosedInterval(Left<T> left, Width<T> width) : mLower{left.value}, mUpper{left.value + width.value} {
        if (mLower >= mUpper) {
            using std::swap;
            swap(mLower, mUpper);
        }
    }

    const ClosedInterval& width(T w) {
        mUpper = mLower + w;
        if (mLower >= mUpper) {
            using std::swap;
            swap(mLower, mUpper);
        }
        return *this;
    }
    constexpr bool contains(T value) const {
        return (value >= mLower) && (value <= mUpper);
    }
private:
    value_type mLower{0};
    value_type mUpper{0};
};


#define pmax(a,b)            (((a) > (b)) ? (a) : (b))
#define pmin(a,b)            (((a) < (b)) ? (a) : (b))

bool isdrin(int a, int b, int c)
{
    return (c>=pmin(a, a+b) && c<=pmax(a, a+b));
}

int main() {
    std::cout << std::boolalpha;
    
    using value_type = int;
    
    value_type a{0};
    value_type b{0};
    value_type c{0};
    
    std::cout << ClosedOrderedInterval{0, 2}.contains(1) << '\n';
    std::cout << ClosedInterval{0}.width(2).contains(1) << '\n';
    std::cout << ClosedInterval{Left{0}, Width{2}}.contains(1) << '\n';

    a = 2;
    b = -1;
    std::cout << ClosedOrderedInterval{a, etl::enclosing_t<value_type>{a} + b}.contains(c) << '\n';
    std::cout << ClosedInterval{a}.width(b).contains(c) << '\n';
    c = 1;    
    std::cout << ClosedOrderedInterval{etl::enclosing_t<value_type>{a} + b, a}.contains(c) << '\n';

    a = std::numeric_limits<int>::max() - 10;
    b = 20;
    
    std::cout << ClosedOrderedInterval{a, a + b}.contains(c) << '\n';
    std::cout << ClosedOrderedInterval{a, etl::enclosing_t<value_type>{a} + b}.contains(c) << '\n';
    std::cout << isdrin(a, b, c) << '\n';
    
    c = a + 5;


    std::cout << ClosedOrderedInterval{a, a + b}.contains(c) << '\n';
    std::cout << ClosedOrderedInterval{a, etl::enclosing_t<value_type>{a} + b}.contains(c) << '\n';
    std::cout << isdrin(a, b, c) << '\n';
    std::cout << ClosedInterval{a}.width(b).contains(c) << '\n';
}
