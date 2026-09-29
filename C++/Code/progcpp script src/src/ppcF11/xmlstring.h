#pragma once

#include "common.h"

namespace FProg {
    namespace Xml {
        class String {
            friend std::string to_string(const String&);
        public:
            class Decoder {
                enum class State {Invalid, Normal, Meta1, Meta2, Amp, Quot, APos, Lt, Gt, Wait};
            public:
                void process(const char);
                std::string value() const;
            private:
                State mState{State::Normal};
                std::string mData;
            };
            
            String() = default;
            String(const std::string&);
            void clear();
            String& operator+=(const char c);
            operator std::string() const;
        private:
            std::string mData;
        };
        std::string to_string(const String&);
        std::ostream& operator<<(std::ostream&, const String&);
    }
}

