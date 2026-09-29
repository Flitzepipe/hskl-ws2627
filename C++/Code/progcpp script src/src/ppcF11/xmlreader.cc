#include "xmlreader.h"
//#include "xmlstring.h"
#include "tracer.h"
#include "xml.h"

namespace FProg {
    XMLReader::XMLReader(const std::string& data) : mData{data} {}
    
    std::optional<Attribute> XMLReader::read(const std::string& token) {
        if (!start(token)) {
            return {};
        }
        Attribute attr{token};
//        mData >> Xml::asXml(attr);
        
//        Attribute av{token};
//        XmlString xmlDecoder;
//        mData >> xmlDecoder;
//        if (xmlDecoder) {
//            if (end()) {
//                return av.value(xmlDecoder.value());
//            }
//        }
        return {};
    }
    
    bool XMLReader::start(const std::string& token) {
        mStartTokenStack.push(token);
        if (const auto t = readNextTag(); !t || (*t != token)) {
            return {};
        }
        return true;        
    }
    
    bool XMLReader::end() {
        if (const auto t = readNextTag(); !t) {
            return false;
        }
        else if (t->at(0) != '/') {
            return false;
        }
        else if (t->substr(1) != mStartTokenStack.top()) {
            return false;
        }
        mStartTokenStack.pop();
        return true;
    }
    
    std::optional<std::string> XMLReader::readNextTag() {
        std::string value;
        bool inTag{false};
        while(!mData.eof()) {
            const char c{static_cast<char>(mData.get())};
            if (inTag) {
                if (c == '>') {
                    inTag = false;
                    return value;
                }
                value += c;
            }
            else {
                if (c == '<') {
                    inTag = true;
                }
            }
        }
        return {};
    }
    
}
