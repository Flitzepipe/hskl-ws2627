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

#include <array>
#include <algorithm>

namespace PPC {
    //[sort
    template<typename Container>
    constexpr Container& sort(Container& c) {
        for(size_t i = 1; i < c.size(); ++i) {
            if (c[i - 1] > c[i]) {
                using std::swap;
                swap(c[i - 1], c[i]);
                i = 0;
            }
        }
        return c;
    }
    //]
}
//[gen
template<typename T, size_t Size>
constexpr std::array<T, Size> generate() {
    std::array<T, Size> a = {};
    for(int i = Size - 1; i > 0; --i) { //<> Die Befüllung des Arrays hier mit Werten dient nur als Beispiel
        a[i] = i; 
    }
    return PPC::sort(a); //<> Weil auch `sort()` `constexpr` ist, belibt auch `generate()` `constexpr`
}
//]
int main() {
    //[main1
    std::array<int, 10> a1 = {3, 2, 1}; //<> `a1` ist _nicht_ `constexpr`
    auto a2 = PPC::sort(a1); //<> `sort()` wird daher zur Laufzeit ausgeführt.
    //]
    //[main2
    constexpr auto b1 = generate<int, 10>();
    constexpr auto s = b1.size();
    //]
    return s;
}
