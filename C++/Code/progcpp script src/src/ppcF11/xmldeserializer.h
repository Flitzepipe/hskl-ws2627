#pragma once

#include "deserializer.h"
#include "xml.h"

namespace FProg {
    class XmlDeserializer final : public Deserializer {
    public:
        XmlDeserializer();
        inline explicit XmlDeserializer(const std::string& data) : mData{data} {}
    protected:
        bool start_impl(const std::string &name) override;
        std::optional<Attribute> read_impl(const std::string &name) override;
        bool stop_impl() override;
    private:
        FProg::Xml::Document<> mData;
    };
}
