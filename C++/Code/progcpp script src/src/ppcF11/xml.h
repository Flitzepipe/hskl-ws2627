#pragma once

#include "common.h"
#include "attribute.h"
#include "algorithm.h"
#include <iostream>
#include <vector>
#include <stack>
#include <cassert>
#include <functional>

#include "xmlstring.h"

namespace FProg {
    namespace Xml {
        std::string encode(const std::string&);
        std::string decode(const std::string&);

        class Parser {
            enum class State {Undefined, StartTag, OTag, CTag, TagWhitespace, Content, Attr};
        public:
            Parser& atOpening(const auto& f) {mOpenCB = f; return *this;}
            Parser& atClosing(const auto& f) {mCloseCB = f; return *this;}
            Parser& atAttribute(const auto& f) {mAttrCB = f; return *this;}
            Parser& atContent(const auto& f) {mContentCB = f; return *this;}
            void process(const char c) {
                using namespace FProg;
                const State oldState = mState;
                switch(mState) {
                case State::Undefined:
                    if (c == '<') {
                        mState = State::StartTag;
                        mData.clear();
                    }
                    break;
                case State::StartTag:
                    if (c == '/') {
                        mState = State::CTag;
                    }
                    else if (c != any_of{' ', '\t', '\n'}) {
                        mData += c;
                        mState = State::OTag;
                    }
                    break;
                case State::OTag:
                    if (c == '>') {
                        mOpenCB(mData);
                        mState = State::Content;
                        mData.clear();
                    }
                    else if (c == any_of{' ', '\t', '\n'}) {
                        mOpenCB(mData);
                        mState = State::TagWhitespace;
                        mData.clear();
                    }
                    else {
                        mData += c;
                    }
                    break;
                case State::TagWhitespace:
                    if (c == '>') {
                        mState = State::Content;
                    }
                    else if (c != any_of{' ', '\t', '\n'}) {
                        mState = State::Attr;
                    }
                    break;
                case State::Attr:
                    if (c == '>') {
                        mAttrCB(mData);
                        mState = State::Content;
                        mData.clear();
                    }
                    else if (c == any_of{' ', '\t', '\n'}) {
                        mAttrCB(mData);
                        mState = State::TagWhitespace;
                        mData.clear();
                    }
                    else {
                        mData += c;
                    }
                    break;
                case State::CTag:
                    if (c == '>') {
                        mCloseCB(mData);
                        mState = State::Undefined;
                        mData.clear();
                    }
                    else {
                        mData += c;
                    }
                    break;
                case State::Content:
                    if (c == '<') {
                        mContentCB(mData);
                        mState = State::StartTag;
                        mData.clear();
                    }
                    else {
                        mData += c;
                    }
                    break;
                }
                if (oldState != mState) {
                    
                }
            }
        private:
            State mState{State::Undefined};
            FProg::Xml::String mData;
            std::stack<State> mStateStack;
            std::function<void(std::string)> mOpenCB;
            std::function<void(std::string)> mCloseCB;
            std::function<void(std::string)> mAttrCB;
            std::function<void(std::string)> mContentCB;
        };
        
        
        template<typename... TT>
        std::string indent(const size_t i, const TT&... ss) {
            return (std::string(i, '\t') + ... + static_cast<std::string>(ss));
        }
        
        struct Opening;
        struct Closing;
        
        template<typename T>
        class Tag {
        public:
            Tag(const std::string& name) : mName{name}{}
            operator std::string() const {
                if constexpr(std::is_same_v<T, Closing>) {
                    return std::string{"</"} + encode(mName) + '>';
                }
                else {
                    return std::string{"<"} + encode(mName) + '>';
                }
            }
        private:
            const std::string mName;
        };
        
        template<template<typename> typename C = std::vector>
        class Element;
        
        template<template<typename> typename C = std::vector, typename E = Element<C>>
        class Document;
        template<template<typename> typename C, typename E>
        std::string to_string(const Document<C, E>& d);
        
        template<template<typename> typename C, typename E>
        class Document {
            friend std::string to_string<>(const Document<C, E>&);
        public:
            Document() = default;
            Document(const std::string& data);
            Document& operator+=(const E&);
            static C<E> parse(const std::string& data);
        private:
            C<E> mElements;
        };
        template<template<typename> typename C, typename E>
        Document<C, E>::Document(const std::string &data) : mElements{parse(data)} {}

        template<template<typename> typename C, typename E>
        C<E> Document<C, E>::parse(const std::string &data) {
            C<E> result;
            std::stack<Element<C>> elementStack;
            
            Parser p;
            p.atOpening([&](const std::string& name){
                elementStack.push(Element<C>{name});
            });
            p.atClosing([&](const std::string& name){
                assert(!elementStack.empty());
                if (elementStack.top().name() == name) {
                    if (elementStack.size() == 1) {
                        result.push_back(elementStack.top());
                    }
                    else {
                       auto top = elementStack.top();
                       elementStack.pop();
                       elementStack.top() += top;
                       
                    }
                }
                elementStack.pop();
            });
            p.atAttribute([&](const std::string& avString){
                const Attribute attr = FProg::Attribute::from_string(avString);
                assert(!elementStack.empty());
                elementStack.top() += attr;
            });
            p.atContent([&](const std::string& data){
                assert(!elementStack.empty());
                elementStack.top() = data;
            });
            
            for(const auto& c : data) {
                p.process(c);
            }
        }
        
        template<template<typename> typename C, typename E>
        Document<C, E>& Document<C, E>::operator+=(const E& e) {
            mElements.push_back(e);
            return *this;
        }
        template<template<typename> typename C, typename E>
        std::string to_string(const Document<C, E>& d) {
            std::string result;
            for(const auto& e : d.mElements) {
                result += to_string(e);
                result += '\n';
            }
            return result;
        }
        template<template<typename> typename C>
        std::ostream& operator<<(std::ostream& o, const Document<C>& d){
            return o << to_string(d);
        }        

        template<template<typename> typename C>
        std::string to_string(const Element<C>& e, size_t = 0);

        template<template<typename> typename C>
        class Element {
            friend std::string to_string<>(const Element& e, size_t);
        public:
            explicit Element(const std::string&);
            explicit Element(const FProg::Attribute&);
            Element& operator+=(const Element&);
            Element& operator+=(const Attribute&);
            Element& operator=(const std::string& content);
            std::string name() const {return mName;}
        private:
            std::string mName;
            std::string mContent;
            C<Element<C>> mElements;
            C<Attribute> mAttributes;            
        };
        template<template<typename> typename C>
        Element<C>::Element(const std::string& n) : mName{n}{}

        template<template<typename> typename C>
        Element<C>::Element(const Attribute& a) : mName{a.name()}, mContent{a.value()}{}
        
        template<template<typename> typename C>
        Element<C>& Element<C>::operator+=(const Element<C>& e) {
            mElements.push_back(e);
            return *this;
        }
        template<template<typename> typename C>
        Element<C>& Element<C>::operator+=(const Attribute& a) {
            mAttributes.push_back(a);
            return *this;
        }
        template<template<typename> typename C>
        Element<C>& Element<C>::operator=(const std::string& content) {
            mContent = content;
            return *this;
        }
        template<template<typename> typename C>
        std::string to_string(const Element<C>& element, const size_t ind) {
            std::string result = indent(ind, FProg::Xml::Tag<Opening>{element.mName}, "\n");
            if (!element.mContent.empty()) {
                result += indent(ind + 1, FProg::Xml::encode(element.mContent), "\n");
            }
            for(const auto& e : element.mElements) {
                result += to_string(e, ind + 1);
            }
            result += indent(ind, FProg::Xml::Tag<Closing>{element.mName}, "\n");
            return result;
        }
        template<template<typename> typename C>
        std::ostream& operator<<(std::ostream& o, const Element<C>& e) {
            return o << to_string(e);
        }
    }
}

//namespace FProg {
//    namespace Xml {
//        std::string encode(const std::string&);
//        std::string decode(const std::string&);

//        class TokenParser {
//            friend std::istream& operator>>(std::istream&, TokenParser&);
//            enum class State {Invalid, Normal, Meta1, Meta2, Amp, Quot, APos, Lt, Gt, Wait};
//        public:
//            explicit operator bool() const;
//            std::string value() const;
//            TokenParser& process(char);
//        private:
//            State mState{State::Normal};
//            std::string mData;
//        };
//        class ClosingTag;
//        class OpeningTag {
//        public:
//            static OpeningTag extractFrom(std::istream& in) {

//            }
//            bool operator==(const ClosingTag& ct) {

//            }
//            std::string name() const {

//            }
//        private:
//        };
//        class ClosingTag {
//        public:
//            static ClosingTag extractFrom(std::istream& in) {

//            }
//            std::string name() const {

//            }
//        private:
//        };

//        class Value {
//        public:
//            static Value extractFrom(std::istream& in) {

//            }
//            std::string value() const {

//            }
//        private:
//        };

//        template<typename D> class Attribute;
//        template<typename D> std::istream& operator>>(std::istream& in, FProg::Xml::Attribute<D>&& a);
//        template<typename D>
//        class Attribute {
//            friend std::istream& operator>><>(std::istream& in, Attribute&& a);
//        public:
//            explicit Attribute(D& data) : mData{data} {}
//            const auto& name() const {
//                return mData.name();
//            }
//            const auto& value() const {
//                return mData.value();
//            }
//        private:
//            void name(const std::string& v) {
//                mData.name(v);
//            }
//            void value(const std::string& v) {
//                mData.value(v);
//            }
//            D& mData;
//        };

//        template<typename T>
//        Attribute<T> asXml(T& data) {
//            return Attribute<T>{data};
//        }

//        template<typename D>
//        std::istream& operator>>(std::istream& in, FProg::Xml::Attribute<D>&& a) {
//            OpeningTag openingTag = OpeningTag::extractFrom(in);
//            Value v = Value::extractFrom(in);
//            ClosingTag closingTag = ClosingTag::extractFrom(in);

//            if (openingTag == closingTag) {
//                a.name(openingTag.name());
//                a.value(v.value());
//            }

//            return in;

//            TokenParser parser;
//            while(!in.eof()) {
//                const char c = static_cast<char>(in.peek());
//                if (c == '<') {

//                    return in;
//                }
//                in.get();
//                parser.process(c);
//            }
//            return in;
//        }
//        template<typename D>
//        std::ostream& operator<<(std::ostream& out, FProg::Xml::Attribute<D>&& a) {
//            return out << '<' << FProg::Xml::encode(a.name()) << '>' << FProg::Xml::encode(a.value()) << "</" << a.name() << ">\n";
//        }
//    }
//}
