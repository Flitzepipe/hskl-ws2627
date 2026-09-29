#include "util.h"
#include <cmath>
#include <limits>

namespace PPC {
    void replace(std::string& subject, const std::string& search, const std::string& replace) {
        size_t pos = 0;
        while((pos = subject.find(search, pos)) != std::string::npos) {
            subject.replace(pos, search.length(), replace);
            pos += replace.length();
        }
    }
    
    //[valuesAreClose
    bool valuesAreClose(const double a, const double b)
    {
        if (a == b) {
            return true;
        }
        const double absoluteDifference = std::fabs(a - b);
        const double maximum = std::max(fabs(a), fabs(b));
        const double relativeDifference = absoluteDifference / maximum;
        return relativeDifference <= std::numeric_limits<double>::epsilon();
    }
    //]
}
