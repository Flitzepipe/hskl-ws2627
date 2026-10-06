#pragma once

#include "common.h"
#include <sstream>
#include <stack>

#include "deserializer.h"
#include "attribute.h"

namespace FProg {
    class XMLReader final {
    public:
        explicit XMLReader(const std::string& data);
        std::optional<Attribute> read(const std::string& name);
        bool start(const std::string& token);
        bool end();
    private:
        std::optional<std::string> readNextTag();
        std::stringstream mData;
        std::stack<std::string> mStartTokenStack;
    };
}
