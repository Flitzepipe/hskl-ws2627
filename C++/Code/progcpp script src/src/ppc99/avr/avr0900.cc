/*
 * ++C - C++ introduction
 * Copyright (C) 2013, 2014, 2015, 2016, 2017, 2018 - 2022 Wilhelm Meier <wilhelm.meier@hs-kl.de>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <cstdint>
#include <utility>
#include <initializer_list>
volatile uint8_t x;

namespace detail {
    template<auto... II, typename F>
    void repeat_impl(std::index_sequence<II...>, F&& f) {
        ( ((void)II, f()) , ...);
    }
}

template<auto N, typename F>
void repeat(F&& f) {
    detail::repeat_impl(std::make_index_sequence<N>{}, static_cast<F&&>(f));
}

inline __attribute__((always_inline)) void f() {
    x /= 2;
}    

template<auto... I>
void loop(std::index_sequence<I...>) {
    (((void)I, x /= 2),...);
}

template<typename I, typename F> struct Looper;
template<auto... II, typename F>
struct Looper<std::index_sequence<II...>, F> {
    inline static /*__attribute__((always_inline))  */void loop() {
        (((void)II, F::f()), ...);
    }
};

template<typename = void>
struct F {
    inline static /*__attribute__((always_inline))*/ void f() {
        x /= 2;
    }
};

using ff = F<>;

int main() {
    repeat<10>([]{ // not optimized / inlined with -Os, only with O2
        x /= 2;
    });
//    repeat<10>(f);
//    for(uint8_t i = 0; i < 10; ++i) {
//        x /= 2;
//    }
//    loop(std::make_index_sequence<10>{});
    
//    Looper<std::make_index_sequence<10>, ff>::loop();
}

