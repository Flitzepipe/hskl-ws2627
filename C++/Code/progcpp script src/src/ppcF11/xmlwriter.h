#pragma once

#include <iostream>
#include <stack>
#include <sstream>

#include "serializer.h"
#include "xml.h"

namespace FProg {
    class XMLWriter final {
        friend std::string to_string(const XMLWriter&);
    public:
        ~XMLWriter();
        void start(const std::string& token);
        void write(const Attribute& av) ;
        void end();
        
    private:
//        FProg::Xml::Document mDocument;
        
        std::string indent();
//        std::stringstream mData;
//        std::stack<std::string> mStartTokenStack;
    };
    
    std::string to_string(const XMLWriter&);
    std::ostream& operator<<(std::ostream& os, const XMLWriter& s);
}
