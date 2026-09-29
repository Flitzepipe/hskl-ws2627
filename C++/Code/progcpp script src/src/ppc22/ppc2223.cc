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

#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

//[at
template<typename T> // <> Definition eines allgemeinen Templates
class Equals
{
public:
    explicit Equals(const T& v) : mValue(v) {}

    bool operator()(const T& v) {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
        return v == mValue; // <> Hier im allgemeinen Fall benutzt dieses Template den _natürlichen_ Vergleich-Operator des Datentyps `T`
    }
private:
    T mValue{};
};
//]
//[st
template<>
class Equals<double> // <> Als _Ausnahme_ fügen wir eine _Spezialisierung_ für den Datentyp `double` hinzu
{
public:
    explicit Equals(double v) : mValue(v) {}

    bool operator()(double v) {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
        return (std::fabs(v - mValue) <= std::numeric_limits<double>::epsilon()); // <> Hier wird dann abweichend vom Standardfall ein _Epsilon_-Vergleih durchgeführt.
    }
private:
    double mValue{};
};
//]
//[st2
template<>
class Equals<float> // <> Ein Ausnahem für den DT `float`
{
public:
    explicit Equals(float v) : mValue(v) {}

    bool operator()(float v) {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
        return (std::fabs(v - mValue) <= std::numeric_limits<float>::epsilon());
    }
private:
    float mValue{};
};
//]
//[ct
template<typename T>
Equals<T> make_equals(const T& v) {
    return Equals<T>(v);
}
//]
int main()
{
    //[double
    std::vector<double> v{1.0, 2.0, 3.0, 1.0};
    auto n = std::count_if(std::begin(v), std::end(v), Equals<double>(1.0));
    std::cout << n << std::endl;
    //]
    //[int
    std::vector<double> w{1, 2, 3, 1};
    auto m = std::count_if(std::begin(v), std::end(v), Equals<int>(2));
    std::cout << m << std::endl;
    //]
    //[double2
    auto n2 = std::count_if(std::begin(v), std::end(v), make_equals(2.0));
    std::cout << n2 << std::endl;
    //]
#if __GNUC__ >= 7
    //[double3
    auto n3 = std::count_if(std::begin(v), std::end(v), Equals(2.0)); // <> Automatische Ableitung von `double` als Typ-Parameter
    std::cout << n3 << std::endl;
    //]
#endif
}
