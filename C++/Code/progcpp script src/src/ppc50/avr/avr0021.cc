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

#include <stdint.h>

// Variante, um auch WriteOnly unterscheiden zu können

struct ReadOnly {};
struct WriteOnly {};
struct ReadWrite : ReadOnly, WriteOnly {};

template<typename T, typename Type>
class DataRegister final {
public:
    DataRegister() = default;
    DataRegister(const DataRegister&) = delete;
    DataRegister& operator=(const DataRegister&) = delete;
    DataRegister(DataRegister&&) = delete;
    DataRegister& operator=(DataRegister&&) = delete;
    
    operator T() const {
        return read(Type{});
    }
    void operator=(const T& v) {
        write(Type{}, v);
    }
private:
    const volatile T& read(ReadOnly) const {
        return hwRegister;
    }
    void write(WriteOnly, const T& v) {
        hwRegister = v;
    }
    volatile T hwRegister{0};
};

int main() 
{
    DataRegister<uint8_t, ReadOnly> a;
    DataRegister<uint8_t, WriteOnly> b;
    DataRegister<uint8_t, ReadWrite> c;

    uint8_t a1 = a;
//    a = a1;
    
//    uint8_t b1 = b;
    b = 1;
    
    uint8_t c1 = c;
    c = c1;
}