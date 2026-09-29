#include "xmlwriter.h"
#include "xmlreader.h"
#include "xml.h"

#include <sstream>
#include <iomanip>

namespace FProg {
    void XMLWriter::write(const Attribute& av) {
//        mData << indent();
//        mData << Xml::asXml(av);
//        mData << to_xml(av);
    }
    
    void XMLWriter::start(const std::string& startToken) {
//        mData << indent();
//        mData << "<" << startToken << ">\n";
//        mStartTokenStack.push(startToken);
    }
    
    void XMLWriter::end() {
//        std::string startToken{mStartTokenStack.top()};
//        mStartTokenStack.pop();
//        mData << indent();
//        mData << "</" << startToken << ">\n";
    }
    
    XMLWriter::~XMLWriter() {
//        while(mStartTokenStack.size() > 0) {
//            end();
//        }
    }
    
//    std::string XMLWriter::indent() {
//        return std::string(mStartTokenStack.size(), '\t'); // runde Klammern, damit nicht der init-list ctor benutzt wird
//    }
    
//    std::string to_string(const XMLWriter& w) {
//        return w.mData.str();
//    }
    
    std::ostream& operator<<(std::ostream& out, const XMLWriter& w) {
//        return out << to_string(w);
    }
}
