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
#include <utility>
#include <array>

namespace Util {
    namespace detail {
        template<typename To, size_t... II>
        constexpr To convert_impl(const std::array<std::byte, sizeof(To)>& data, std::index_sequence<II...>) {
            constexpr auto maxShift = sizeof(To) - 1;
            return ((static_cast<To>(data[maxShift - II]) << ((maxShift - II) * 8)) | ... );        
        }
    }
    template<typename To>
    constexpr To convert(const std::array<std::byte, sizeof(To)>& data) {
        return detail::convert_impl<To>(data, std::make_index_sequence<4>{});
    }
}

using namespace std::literals;

volatile std::byte a{1};
volatile std::byte b{2};
volatile std::byte c{3};
volatile std::byte d{4};

int main() {
    std::array<std::byte, sizeof(uint32_t)> data{a, b, c, d};
//    constexpr std::array<std::byte, sizeof(uint32_t)> data{std::byte{1}, std::byte{2}, std::byte{3}, std::byte{4}};
    
    auto x = Util::convert<uint32_t>(data);
    return x / 2;
}