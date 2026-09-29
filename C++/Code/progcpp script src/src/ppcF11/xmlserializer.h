#pragma once

#include "common.h"
#include "serializer.h"
//#include "xmlwriter.h"
#include "xml.h"
#include <optional>

namespace FProg {
    class XmlDeserializer;
    class XmlSerializer;
    
    template<>
    struct makeDeserializer<XmlSerializer> { // Meta-Funktion
        using type = XmlDeserializer;  
    };
    
    class XmlSerializer final : public Serializer {
        friend std::string to_string(const FProg::XmlSerializer&);
    public:
        using deserializer = XmlDeserializer;
    protected:
        void start_impl(const std::string &name) override;
        void write_impl(const Attribute& av) override;
        void stop_impl() override;
    private:
        std::optional<FProg::Xml::Element<>>  mActual;
        FProg::Xml::Document<> mData;
    };
    std::string to_string(const XmlSerializer&);
    std::ostream& operator<<(std::ostream& os, const XmlSerializer& s);
}

