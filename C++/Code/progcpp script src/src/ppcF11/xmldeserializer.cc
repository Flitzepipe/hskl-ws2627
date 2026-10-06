#include "xmldeserializer.h"

namespace FProg{
    bool XmlDeserializer::start_impl(const std::string& token) {
//        return mReader.start(token);
    }
    
    std::optional<Attribute> XmlDeserializer::read_impl(const std::string &name) {
//        return mReader.read(name);
    }
    bool XmlDeserializer::stop_impl() {
//        return mReader.end();
    }
}
