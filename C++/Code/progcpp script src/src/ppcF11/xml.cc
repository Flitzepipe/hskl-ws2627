#include "xml.h"

std::string FProg::Xml::encode(const std::string& data) {
    std::string buffer;
    buffer.reserve(data.size());
    for(size_t pos{0}; pos != data.size(); ++pos) {
        switch(data[pos]) {
        case '&':  buffer.append("&amp;");       break;
        case '\"': buffer.append("&quot;");      break;
        case '\'': buffer.append("&apos;");      break;
        case '<':  buffer.append("&lt;");        break;
        case '>':  buffer.append("&gt;");        break;
        default:   buffer.append(&data[pos], 1); break;
        }
    }
    return buffer;    
}
std::string FProg::Xml::decode(const std::string& data) {
    FProg::Xml::String::Decoder decoder;
    for(const auto& c : data) {
        decoder.process(c);
    }    
    return decoder.value();
}

//FProg::Xml::TokenParser& FProg::Xml::TokenParser::process(const char c){
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

