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
#include <cassert>
#include <limits>
#include <iostream>
#include <type_traits>

//[mintype
template<size_t N>
struct minimalType { // <> Meta-Funktion: bildet die Compilezeit-Konstante `N` auf einen _Datentyp_ ab.
    typedef typename std::conditional<N <= std::numeric_limits<uint8_t>::max(), uint8_t, 
                                 typename std::conditional<N <= std::numeric_limits<uint16_t>::max(), uint16_t,
                                            typename std::conditional<N <= std::numeric_limits<uint32_t>::max(), uint32_t, 
                                                      uint64_t>::type
                                            >::type
                                 >::type type; // <> Der Typ-Alias `type` ist der Ergebnistyp dieser Meta-Funktion
};
//]
//[class -a
template<size_t Min, size_t Max, // <> Die Nicht-Typ-Parameter bekommen den immer ausreichenden Typ `size_t`
         typename T = typename minimalType<Max>::type> // <> Der Typ-Parameter `T` erhält einen Vorgabe-Wert, der von der Meta-Funktion `minimalType<>` bestimmt wird.
class uint_ranged {
    static_assert(Min <= Max, "wrong range"); // <> Compilezeit-Zusicherung für die Ordnung von `Min` und `Max`
public:
    typedef T value_type; // <> Der zugrunde liegende Type wird zurück gespiegelt.
    explicit uint_ranged(T v = Min) : mValue{v} { 
        assert(v >= Min); // <> Laufzeit-Assertion für die Erzeugung eines Objektes mit einem passenden Wert aus dem Intervall [Min, Max].
        assert(v <= Max);
    }
    //[a
    operator T() const { 
        return mValue;
    } 
    uint_ranged& operator++() {
        if (mValue < Max) {
            ++mValue;
        }
        return *this;
    }
    uint_ranged& operator--() { 
        if (mValue > Min) {
            --mValue;
        }
        return *this;
    }
    //]
private:
    T mValue{Min};
};
//]
//[limits
namespace std { 
    template<size_t Min, size_t Max, typename T> 
    struct numeric_limits<uint_ranged<Min, Max, T>> { 
        static inline T min() {
            return Min; 
        }
        static inline T max() {
            return Max; 
        }
    };
}
//]
//[foo
template<typename T>
void foo() {
    std::cout << __PRETTY_FUNCTION__ << '\n';
}
//]
int main()
{
    //[main
    uint_ranged<10, 20> v1;
    foo<decltype(v1)::value_type>();
    uint_ranged<200, 300> v2;
    foo<decltype(v2)::value_type>();
    uint_ranged<100000, 900000> v3;
    foo<decltype(v3)::value_type>();
    //]
}
