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

//[same1
template<typename T, typename U>
struct isSame { // <> Das allgemeine Template definiert ein konstantes Datenelement `value`
    inline static constexpr bool value = false;
};
//]
//[same2
template<typename T>
struct isSame<T, T> { // <> Diese Spezialisierung detektiert gleiche Datentypen
    inline static constexpr bool value = true;
};
//]

int main() {
    //[main
    static_assert(isSame<int, int>::value);
    static_assert(!isSame<int, char>::value);
    //]
}
