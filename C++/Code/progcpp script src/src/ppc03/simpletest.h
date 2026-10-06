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

#ifdef _MSC_VER
#  pragma warning(push)
#  pragma warning(disable: 4996)
#  pragma warning(disable: 4573)
#endif

//#ifdef __GNUC__
//# pragma GCC diagnostic push
//# pragma GCC diagnostic ignored "-Weffc++"
//#endif

// #include "common.h"
#include <iostream>
#include <cassert>
#include <cstdlib>
#include <cmath>
#include <limits>

#define CAT2(X, Y) X ## Y
#define CAT(X, Y) CAT2(X, Y)

#define SIMPLETEST(name) static FProg::SimpleTestCase CAT(SimpleTestCaseOnLine, __LINE__) = \
    FProg::SimpleTestCase(name, __FILE__, __LINE__) = []

namespace FProg {
    class SimpleTestCase final {
    public:
        explicit SimpleTestCase(const char* const name, const char* const file, const int line);
        
        SimpleTestCase& operator=(const auto lambda) {
            bool noOutput{false};
            bool noTests{false};
            if (const char* const env{getenv("SIMPLETEST")}) {
                const std::string envVar{env};
                if (envVar.find("nooutput") != std::string::npos) {
                    noOutput = true;
                }
                if (envVar.find("notests") != std::string::npos) {
                    noTests = true;
                }
            }
# ifndef NDEBUG
            if (!noOutput && !noTests) {
                std::cout << "Test(" << mName << "," << mFile << "," << mLine << ")";
            }
# endif
            if (!noTests) {
                ++mTestCount;
                if (lambda()) {
# ifndef NDEBUG
                    if (!noOutput) {
                        std::cout << " ok " << "(" << mTestCount << "/" << mFailureCount << ")" << std::endl;
                    }
# endif
                }
                else {
                    ++mFailureCount;
# ifndef NDEBUG
                    if (!noOutput) {
                        std::cout << " failed " << "(" << mTestCount << "/" << mFailureCount << ")" << std::endl;
                    }
                    else {
                        std::cerr << "Test(" << mName << "," << mFile << "," << mLine << ") failed " << "(" << mTestCount << "/" << mFailureCount << ")" << std::endl;
                    }
# endif
                }
            }
            return *this;
        }
        static bool equal(const double a, const double b);
    private:
        const char* mName{"undefined"};
        const int mLine{0};
        const char* mFile{"undefined"};
        inline static size_t mTestCount{0};
        inline static size_t mFailureCount{0};
    };
}
#ifdef _MSC_VER
#  pragma warning(pop)
#endif

//#ifdef __GNUC__
//# pragma GCC diagnostic pop
//#endif
