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

//[ff
int sum1(int a, int b) {
    return a + b;
}
constexpr int sum2(int a, int b) {
    return a + b;
}
//]
int main() {
    //[c1 
    const auto a1 = sum1(1, 2); // <> `sum1()` ist _nicht_ `constexpr` und wird für die Initialisierung von `a1` zur Laufzeit aufgerufen.
    constexpr auto a2 = sum2(1, 2); // <> Hier wird `a2` schon zur Compile-Zeit mit dem Ergebnis von `sum2()` initialisiert. 
    //]
    //[c2
#if WITH_ERROR //-
    constexpr auto b1 = sum2(a1, 1); // <> Nicht möglich, da `a1` nicht `constexpr` ist
#endif //-
    constexpr auto b2 = sum2(a2, 2); // <> Sowohl `a2` wie natürlich auch `2` sind `constexpr`, damit ist auch `sum2()` constexpr
    //]
    return a1 + a2 + b2;
}
