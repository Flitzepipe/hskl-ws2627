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

#include <type_traits>

#include <cstdint>

struct A{
    A square() const {
        return A{};
    }
};

template <typename T>
constexpr std::enable_if_t<std::is_floating_point<T>::value, T> squareX(const T& a) {
  return a * a;
}

template <typename T>
constexpr decltype (std::declval<const T> ().square ()) squareX(const T& a) {
  return a.square ();
}

//template<typename T>
//requires std::is_floating_point<T>::value
//auto squareX(const T& x) {
//    return x * x;
//}

//auto squareX(const A& x) {
//    return x.square();
//}

//template<typename T>
//T squareX (const T &x)
//{
//    if constexpr(std::is_floating_point<T>::value) {
//        return x * x;        
//    }
//    else {
//        return x.square();
//    }
    
//}

struct Z {
    Z(uint8_t) {}
};

class OLED 
{
public:
    void init();
private:
    uint8_t y_size;
    bool i2c_send(uint8_t byte);
};

bool OLED::i2c_send(uint8_t)
{  
    return true;
}

void OLED::init()
{
    #pragma GCC diagnostic push
//    #pragma GCC diagnostic ignored "-Wnarrowing"
//    #pragma GCC diagnostic ignored "-Wconversion"
    i2c_send(y_size-1);
    
    Z{y_size - 1};
    
    #pragma GCC diagnostic pop
}

int main() {
    double x = 1.0;
    squareX(x);
    
    squareX(A{});
//    squareX(1);
}