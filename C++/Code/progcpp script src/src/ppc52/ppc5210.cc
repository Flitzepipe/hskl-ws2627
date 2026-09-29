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
#include <cassert>

//[tuple -get
//[allg
template<typename... V> struct Tuple { // <> Zunächst definieren wir das allgemeine Template. Dies dient auch als Rekursionsende, da es auch mit einer _leeren_ Parameterliste instaziiert werden kann.
};
//]
//[spez -get
template<typename T, typename... V>
struct Tuple<T, V...> : // <> Spezialisierung für mindesten _einen_ Typ-Parameter
        Tuple<V...> { // <> Da es ein `struct` ist, ist die eine _öffentliche_ (rekursive) Vererbung
    Tuple(T t, V... vs) : //<> Der Konstruktor mit mindestens einem Pflicht-Parameter
        Tuple<V...>{vs...}, // <> Initialisierung des eingebetteten Basisklassenobjektes mit den restlichen Parametern
        mData{t} { // <> Initialisierung des Datenelemente `mData` mit dem ersten Objekt der Parameterliste
    }
    //[get
    template<size_t N>
    auto get() {
        if constexpr(N == 0) { // <> Unterste Hierrachiestufe
            return mData;
        }
        else {
            return Tuple<V...>::template get<N-1>(); // <> Aufruf von `get<>()` der nächsten Hierarchiestufe
        }
    }
    //]
    const T mData;
};
//]
//]
// Version mit partielle Spezialisierung bei Funktionen nicht möglich
//template<int N, typename T, typename... TT>
//auto get(const Tuple<T, TT...>& tuple) {
//    const Tuple<TT...>& base = tuple;
//    return get<N - 1>(base);
//}
//template<typename T>
//auto get<0, T>(const Tuple<T>& tuple) {
//    return tuple.mTail;
//}

template<size_t N, typename T, typename... TT>
auto get(const Tuple<T, TT...>& tuple) {
    if constexpr(N == 0) {
        return tuple.mData;
    }    
    else {
        const Tuple<TT...>& base = tuple;
        return get<N - 1>(base);
    }
}


int main()
{
    //[main1
    Tuple<int, char> t1(1, 'a');
    //]
    auto x1 = get<0>(t1);
    auto x2 = get<1>(t1);
    
    assert(x1 == 1);
    assert(x2 == 'a');
    
    auto x11 = t1.get<0>();
    auto x21 = t1.get<1>();

    assert(x11 == 1);
    assert(x21 == 'a');
    
    Tuple<> t2;
}
