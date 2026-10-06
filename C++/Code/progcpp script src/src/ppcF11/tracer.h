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

#include "common.h"

#if !(defined(NDEBUG) || defined(NO_TRACE))
# define TRACE FProg::Tracer __t(std::string(__PRETTY_FUNCTION__))
# define TRACE1(s) FProg::Tracer __t1(s);
#else
# define TRACE
# define TRACE1
#endif

#include <iostream>

namespace FProg {
    class Tracer;
    Tracer trace(); // fuer friend-Deklaration
    class Tracer final {
        friend Tracer trace();
    public:
        explicit Tracer(const char* name);
        explicit Tracer(const std::string& name);
        ~Tracer();
        void setNestingPrefix(const std::string& prefix);
#ifndef NDEBUG
        template<typename T>
        const Tracer& operator<<(const T& value) const {
            for(unsigned int i = 0; i <= mNestingLevel; ++i) {
                std::cout << mNestingPrefix;
            }
            std::cout << value << std::endl;
            return *this;
        }
#else
        template<typename T>
        const Tracer& operator<<(const T&) const {
            return *this;
        }
#endif
    private:
        explicit Tracer(bool fixed = false);
        void print(std::ostream& o) const;
        bool mFixed{false};
        const std::string mName;
        inline static std::string mNestingPrefix{"   "};
        inline static size_t mNestingLevel{0};
        inline static const char* const mEntryMarker{"-->"};
        inline static const char* const mExitMarker{"<--"};
    };
}
