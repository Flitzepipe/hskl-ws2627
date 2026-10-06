#include <cassert>
#include <type_traits>

namespace Test {
    namespace detail {
        template<typename T> struct size_impl; 
        template<template<typename...> typename L, typename... I>  
        struct size_impl<L<I...>> { 
            typedef std::integral_constant<std::size_t, sizeof...(I)> type; 
        };
    }
    template<typename L>
    using size = typename detail::size_impl<L>::type;
    template<typename... T>
    struct List {}; 
}
template<typename... T>
void foo(T... tt) {
    using tl = Test::List<T...>; 
    using s = Test::size<tl>;  
#if SHOW 
    s::_; 
#endif 
}

template<typename>
inline static constexpr bool test = []{
    return true;
}();

//template<typename>
//inline static constexpr bool test = []{
//    return true;
//}();

int main() {
    foo(1, 1.1, 'c');
}
