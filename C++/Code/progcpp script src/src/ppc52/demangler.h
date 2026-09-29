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

#include <typeinfo>
#include <cxxabi.h>

namespace PPC {
    template<typename T> class Demangler;
    template<typename T> std::ostream& operator<<(std::ostream&, const Demangler<T>&);
    
    template<typename T>
    class Demangler {
        friend std::ostream& operator<< <>(std::ostream&, const Demangler<T>&);
    public:
        Demangler() {
            int status = 0;
            mName = abi::__cxa_demangle(typeid(T).name(), 0, 0, &status);
        }
        ~Demangler() {
            free(mName);
        }
    private:
        char* mName = 0;
    };
    template<typename T>
    Demangler<T> demangle(T) {
        return Demangler<T>();
    }
    template<typename T>
    std::ostream& operator<<(std::ostream& out, const Demangler<T>& d) {
        return out << d.mName;
    }
} // !PPC
