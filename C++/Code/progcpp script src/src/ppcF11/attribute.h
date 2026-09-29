#pragma once

#include "common.h"

#include <functional>

namespace FProg {
    class Attribute final {
        class Parser {
            enum class State {Undefined, Name, Equal, Value};
        public:
            Parser& atName(const auto& f);
            Parser& atValue(const auto& f);
            void process(const char c);
        private:
            std::function<void(std::string)> mNameCb;            
            std::function<void(std::string)> mValueCb;            
            State mState{State::Undefined};
            std::string mData;
        };
    public:
        explicit Attribute(const std::string& name);
        Attribute& value(const std::string& value);
        Attribute& value(size_t value);
        const std::string& value() const;
        
        Attribute& name(const std::string& n);
        const std::string& name() const;
        
        static Attribute from_string(const std::string&);
    private:
        const std::string mName;
        std::string mValue;
    };
    std::string to_string(const Attribute&);
    std::ostream& operator<<(std::ostream&, const Attribute&);
}
