#include "deserializer.h"

#include "cassert"

bool FProg::Deserializer::start(const std::string& classname) {
    assert(!mStarted);
    if (start_impl(classname)) {
        mStarted = true;
        return true;
    }
    return false;
}

bool FProg::Deserializer::stop() {
    assert(mStarted);
    if (stop_impl()) {
        mStarted = false;
        return true;
    }
    return false;
}

std::optional<FProg::Attribute> FProg::Deserializer::read(const std::string& name) {
    assert(mStarted);
    return read_impl(name);
}

FProg::DeserializerTransaction::DeserializerTransaction(Deserializer& deserializer, const std::string classname) : mDeserializer(deserializer) {
    mOk = mDeserializer.start(classname);
}

FProg::DeserializerTransaction::~DeserializerTransaction() {
    if (mOk) {
        mDeserializer.stop();
    }
}

std::optional<FProg::Attribute> FProg::DeserializerTransaction::read(const std::string& token) {
    if (mOk) {
        if (auto attr = mDeserializer.read(token)) {
            return attr;
        }
        else {
            mOk = false;
            return {};
        }
    }
    return {};
}
