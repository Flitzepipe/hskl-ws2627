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

#include <cassert>
#include <type_traits>

namespace PPC {
    //[meta1
    template<typename... T>
    struct List {
        inline static constexpr auto size = sizeof...(T); // <> Eine Möglichkeit die Länge zu bestimmen, als Wert
        typedef std::integral_constant<std::size_t, sizeof...(T)> size_type; // <> Die Länge als Typ
    }; 
    //]
    //[meta2
    namespace detail {
        template<typename L> struct size_impl; // <> Allg. Struktur einer Meta-Funktion mit einem Argument
        template<typename... I>
        struct size_impl<List<I...>> { // <> Partielle Spezialisierung für das _variadische_ Template `List<...>`
            typedef std::integral_constant<std::size_t, sizeof...(I)> type; // <> Darstellung eines Wertes als Typ
        };
    }
    template<typename L>
    using size = typename detail::size_impl<L>::type; // <> Alias-Template als Meta-Funktion
    //]
}
//[foo
template<typename... T>
void foo(T... tt) {
    using tl = PPC::List<T...>; 
    using s = PPC::size<tl>; 
#ifdef SHOW //-
    s::_; // <> Produziert einen Fehler, weil es das Element `_` im Typ `s` nicht gibt: die Fehlermeldung gibt den Typ von `s` an. 
#endif //-
}
//]
int main() {
    //[foo
    foo(1, 1.1, 'c');
    //]
}
