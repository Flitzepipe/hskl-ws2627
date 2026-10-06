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

#pragma once

#include <memory>

#if __cplusplus >= 201402L
#else
# ifndef _MSC_VER
#  warning "using self-defined std::cbegin(), std::cend() (not yet in libstdc++)"
template<typename C>
auto cbegin(const C& c ) -> decltype(c.begin()) {
    return c.begin();
}
template<typename C>
auto cend(const C& c ) -> decltype(c.end()) {
    return c.end();
}
# endif
#endif

// use boost features
//#define PPC_USE_BOOST

#ifdef PPC_USE_BOOST
# define PPC_USE_BOOST_OPTIONAL
# define PPC_USE_BOOST_REGEX
# define PPC_USE_BOOST_TEST
#else
//# define PPC_USE_BOOST_OPTIONAL
//# define PPC_USE_BOOST_REGEX
//# define PPC_USE_BOOST_TEST
#endif

namespace std {
#if __cplusplus > 201103L
#else
# ifndef _MSC_VER
#  warning "using self-defined std::make_unique() (not yet in libstdc++)"
template<typename T, typename... Args>
std::unique_ptr<T> make_unique(Args&&... args)
{
    return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
}
# endif
#endif
} // namespace std

#ifdef __CYGWIN__
#include <cmath>
#include <sstream>
namespace std {
# warning "using self-defined std::round(), std::to_string()"
  /*
inline double round(double v) {
    return ::round(v);
}
inline double hypot(double a, double b) {
    return ::hypot(a, b);
}
  */
template<typename T>
string to_string(const T& v) {
    stringstream ss;
    ss << v;
    return ss.str();
}
template<>
inline string to_string<unsigned char>(const unsigned char& v) {
    stringstream ss;
    ss << static_cast<int>(v);
    return ss.str();
}
}
#endif

#ifdef _MSC_VER
# define __PRETTY_FUNCTION__ __FUNCTION__
#endif

namespace PPC {
} // namespace PPC

