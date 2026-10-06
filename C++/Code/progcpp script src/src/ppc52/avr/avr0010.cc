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
#include <cstddef>

//[t -v
template<typename... V> struct Tuple {}; // <> _Empty-Base-Class_-Optimization
template<typename T, typename... V>
struct Tuple<T, V...> : Tuple<V...> { 
    constexpr Tuple(T t, V... vs) : //<> wichtig ist hier `constexpr`, damit dies ein _LiteralType_ ist
        Tuple<V...>{vs...}, mData{t} { 
    }
    template<size_t N>
    auto constexpr get() const  {
        static_assert(N < sizeof...(V) + 1);
        if constexpr(N == 0) {
            return mData;
        }
        else {
            return Tuple<V...>::template get<N-1>();
            
        }
    }
    //[v
    template<size_t N>
    auto get() const volatile {
        static_assert(N < sizeof...(V) + 1);
        if constexpr(N == 0) {
            return mData;
        }
        else {
            return Tuple<V...>::template get<N-1>();
            
        }
    }
    //]
    const T mData{};
};
//]

//[main
constexpr Tuple<uint8_t, char, double> t1{1, 'a', 1.0};
volatile  Tuple<uint8_t, char, double> t2{2, 'b', 2.0};

int main() {
    constexpr uint8_t x1 = t1.get<0>(); // <> Dies ist ein `contexpr`-Kontext
    volatile char x2 = t2.get<1>(); // <> Laufzeitberechnung
    volatile auto x3 = x1; // <> `x1` ist `constexpr`
    
    while(true) {}
}
//]