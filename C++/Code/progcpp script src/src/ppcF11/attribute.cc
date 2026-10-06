#include "attribute.h"

#include <iostream> 
#include <sstream> 
#include <iomanip> 

#include "algorithm.h"

FProg::Attribute::Attribute(const std::string& name) : mName{name} {}

const std::string& FProg::Attribute::value() const {
    return mValue;
}

const std::string& FProg::Attribute::name() const {
    return mName;
}

FProg::Attribute FProg::Attribute::from_string(const std::string& s) {
    FProg::Attribute::Parser p;
    p.atName([](const std::string& s){
        
    });
    p.atValue([](const std::string& s){
        
    });
    for(const auto& c : s) {
        p.process(c);
    }
}

FProg::Attribute& FProg::Attribute::value(const std::string& value) {
    mValue = value; 
    return *this;
}

FProg::Attribute& FProg::Attribute::value(const size_t value) {
    using std::to_string;
    mValue = to_string(value); 
    return *this;
}

std::string FProg::to_string(const Attribute& attr) {
    std::stringstream ss;
    ss << attr;
    return ss.str();
} 

std::ostream& FProg::operator<<(std::ostream& out, const FProg::Attribute& attr) {
    return out << attr.name() << " = " << std::quoted(attr.value());
}

FProg::Attribute::Parser& FProg::Attribute::Parser::atName(const auto& f){
    mNameCb = f;
    return *this;
}

FProg::Attribute::Parser& FProg::Attribute::Parser::atValue(const auto& f){
    mValueCb = f;
    return *this;
}

void FProg::Attribute::Parser::process(const char c) {
    using namespace FProg;
    switch(mState) {
    case State::Undefined:
        if (c != any_of{' ', '\n', '\t'}) {
            mData.clear();
            mState = State::Name;
            mData += c;
        }
        break;
    case State::Name:
        if (c == '=') {
            mNameCb(mData);
            mState = State::Equal;
            mData.clear();
        }
        if (c != any_of{' ', '\n', '\t'}) {
            mData += c;
        }
        break;
    case State::Equal:
        if (c != any_of{' ', '\n', '\t'}) {
            mState = State::Value;
            mData.clear();
        }
        break;
    case State::Value:
        if (c == any_of{' ', '\n', '\t'}) {
            std::string unQuoted;
            std::stringstream ss{mData};
            ss >> std::quoted(unQuoted);
            mValueCb(unQuoted);
            mState = State::Undefined;
            mData.clear();
        }
        else {
            mData += c;
        }
        break;
    }    
}
