#include <optional>
#include <type_traits>
#include "meta.h"
using namespace BMCPP::Meta;

using value_type = unsigned int;
using result_type = std::optional<value_type>;

volatile value_type x1 = 1;
volatile value_type x2 = 2;
volatile value_type x3 = 0;

result_type func1() {
    return x1;
}
result_type func2() {
    return x2;
}
result_type func3() {
    return {};
}

template<typename... FF>
auto first_valid_result_of(FF... ff) {
    using first_type = front<List<decltype(ff())...>>;
    static_assert((std::is_same<first_type, decltype(ff())>::value && ...), "");
    result_type result;
    ((result = ff()) || ...);
    return result;
}

int main() {
//    auto r = first_valid_result_of([]{return 1;},[]{return 'x';});
    auto r = first_valid_result_of(func1, func1, func3);
    if (r) {
        return *r;
    }
    return 42;
}
