#include "simpletest.h"

FProg::SimpleTestCase::SimpleTestCase(const char* const name, const char* const file, const int line) :
    mName{name}, mLine{line}, mFile{file} {}

bool FProg::SimpleTestCase::equal(const double a, const double b)  {
    if (a == b) {
        return true;
    }
    const double diff = std::fabs(a - b);
    const double max = std::max(fabs(a), fabs(b));
    const double rdiff = diff / max;
    return (rdiff <= std::numeric_limits<double>::epsilon());
}
