#include "xmlserializer.h"

void FProg::XmlSerializer::start_impl(const std::string& name) {
    mActual = FProg::Xml::Element{name};
}

void FProg::XmlSerializer::write_impl(const FProg::Attribute& av) {
    *mActual += FProg::Xml::Element{av};
}

void FProg::XmlSerializer::stop_impl() {
    mData += *mActual;
}

std::ostream& FProg::operator<<(std::ostream& os, const FProg::XmlSerializer& s) {
    return os << to_string(s);
}

std::string FProg::to_string(const FProg::XmlSerializer& s) {
    return to_string(s.mData);
}
