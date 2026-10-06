#include "xmlstring.h"
#include "xml.h"
#include <istream>
#include "tracer.h"

std::ostream& FProg::Xml::operator<<(std::ostream& out, const FProg::Xml::String& q) {
    return out << to_string(q);
}

std::string FProg::Xml::to_string(const FProg::Xml::String& q){
    return FProg::Xml::decode(q.mData);
}

FProg::Xml::String::String(const std::string& data) : mData{Xml::encode(data)}{}

void FProg::Xml::String::clear() {
    mData.clear();
}

FProg::Xml::String::operator std::string() const {
    return to_string(mData);
}

FProg::Xml::String& FProg::Xml::String::operator+=(const char c) {
    mData += c;
    return *this;
}

//FProg::XmlDecoder::operator bool() const{
//    return !mData.empty() && (mState != State::Invalid);
//}

//std::string FProg::XmlDecoder::value() const{
//    return mData;
//}

//FProg::XmlDecoder& FProg::XmlDecoder::process(const char c){
//    switch(mState) {
//    case State::Normal:
//        if (c == '&') {
//            mState = State::Meta1;
//        }
//        else {
//            mData += c;
//        }
//        break;
//    case State::Meta1:
//        if (c == 'a') {
//            mState = State::Meta2;
//        }
//        else if (c == 'q') {
//            mState = State::Quot;
//        }
//        else if (c == 'l') {
//            mState = State::Lt;
//        }
//        else if (c == 'g') {
//            mState = State::Gt;
//        }
//        else {
//            mState = State::Invalid;
//        }
//        break;
//    case State::Meta2:
//        if (c == 'm') {
//            mState = State::Amp;
//        }
//        else if (c == 'p') {
//            mState = State::APos;
//        }
//        else {
//            mState = State::Invalid;
//        }
//        break;
//    case State::Amp:
//        mData += '&';
//        mState = State::Wait;
//        break;
//    case State::APos:
//        mData += '\'';
//        break;
//    case State::Gt:
//        mData += '>';
//        mState = State::Wait;
//        break;
//    case State::Lt:
//        mData += '<';
//        mState = State::Wait;
//        break;
//    case State::Quot:
//        mData += '\"';
//        mState = State::Wait;
//        break;
//    case State::Wait:
//        if (c == ';') {
//            mState = State::Normal;
//        }
//        break;
//    case State::Invalid:
//        break;
//    }
//    return *this;
//}

//std::istream& FProg::operator>>(std::istream& in, XmlDecoder& d) {
//    while(!in.eof()) {
//        const char c = static_cast<char>(in.peek());
//        if (c == '<') {
//            return in;
//        }
//        in.get();
//        d.process(c);
//    }
//    return in;
//}

void FProg::Xml::String::Decoder::process(const char c){
    switch(mState) {
    case State::Normal:
        if (c == '&') {
            mState = State::Meta1;
        }
        else {
            mData += c;
        }
        break;
    case State::Meta1:
        if (c == 'a') {
            mState = State::Meta2;
        }
        else if (c == 'q') {
            mState = State::Quot;
        }
        else if (c == 'l') {
            mState = State::Lt;
        }
        else if (c == 'g') {
            mState = State::Gt;
        }
        else {
            mState = State::Invalid;
        }
        break;
    case State::Meta2:
        if (c == 'm') {
            mState = State::Amp;
        }
        else if (c == 'p') {
            mState = State::APos;
        }
        else {
            mState = State::Invalid;
        }
        break;
    case State::Amp:
        mData += '&';
        mState = State::Wait;
        break;
    case State::APos:
        mData += '\'';
        break;
    case State::Gt:
        mData += '>';
        mState = State::Wait;
        break;
    case State::Lt:
        mData += '<';
        mState = State::Wait;
        break;
    case State::Quot:
        mData += '\"';
        mState = State::Wait;
        break;
    case State::Wait:
        if (c == ';') {
            mState = State::Normal;
        }
        break;
    case State::Invalid:
        break;
    }
}

std::string FProg::Xml::String::Decoder::value() const{
    return mData;    
}
