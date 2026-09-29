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
#include <string>
#include <vector>

namespace detail {

template<typename T>
struct StringConverter;

template<>
struct StringConverter<int> {
    static int value(const std::string& s) {
        return std::stoi(s);
    }
};
template<>
struct StringConverter<double> {
    static double value(const std::string& s) {
        return std::stod(s);
    }
};

}

class Parameter final {
    struct InvalidType {};
public:
    Parameter(const std::string& raw) : mData(raw) {}
    template<typename T>
    T valueAs() const {
        return detail::StringConverter<T>::value(mData);        
    }
    template<typename T>
    T valueAs2() const { // Alternative
        if constexpr(std::is_same<T, int>::value) {
            return std::stoi(mData);
        }
        else if constexpr(std::is_same<T, double>::value) {
            return std::stod(mData);
        }
        else {
            return InvalidType();
        }
    }
private:
    const std::string mData;    
};

int main() {
    std::vector<Parameter> parameters;

    parameters.push_back({"1"});    
    parameters.push_back({"2.2"});    
//    parameters.push_back({"bla"});    // exception below
    
    for(const auto& p : parameters) {
        std::cout << p.valueAs<int>() << '\n';
        std::cout << p.valueAs<double>() << '\n';
//        std::cout << p.valueAs<float>() << '\n'; // compilation error
    }
    for(const auto& p : parameters) {
        std::cout << p.valueAs2<int>() << '\n';
        std::cout << p.valueAs2<double>() << '\n';
//        std::cout << p.valueAs2<float>() << '\n'; // compilation error
    }
}
