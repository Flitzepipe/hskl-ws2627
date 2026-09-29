#include "tracer.h"

#include <iostream>

namespace FProg {
    Tracer::Tracer(const std::string& name) :
        mFixed{false},
        mName{name}
    {
        print(std::cout << mEntryMarker);
        if (!mFixed) {
            ++mNestingLevel;
        }
    }
    
    Tracer::Tracer(const char* const name) :
        Tracer{std::string(name)} {
    }
      
    Tracer::~Tracer()
    {
        if (mNestingLevel > 0) {
            if (!mFixed) {
                --mNestingLevel;
                print(std::cout << mExitMarker);
            }
        }
    }
    
    void Tracer::setNestingPrefix(const std::string& prefix)
    {
        mNestingPrefix = prefix;
    }
    
    Tracer::Tracer(const bool fixed) :
        mFixed{fixed},
        mName{}
    {
    }
    
    void Tracer::print(std::ostream& o) const {
        for(size_t i = 0; i < mNestingLevel; ++i) {
            o << mNestingPrefix;
        }
        o << mName << std::endl;
    }
    
    Tracer trace() {
        return Tracer{true};
    }
}
