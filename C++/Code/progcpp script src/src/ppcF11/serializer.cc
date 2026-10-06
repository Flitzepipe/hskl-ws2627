/*
 * ++C - C++ introduction
 * Copyright (C) 2013, 2014, 2015, 2016, 2017, 2018 - 2022 Wilhelm Meier <wilhelm.meier@hs-kl.de>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "serializer.h"

FProg::SerializerTransaction::SerializerTransaction(Serializer& serializer, const std::string& name) : mSerializer(serializer) {
    mSerializer.start(name);
}

void FProg::SerializerTransaction::write(const Attribute& attr) {
    mSerializer.write(attr);
}

FProg::SerializerTransaction::~SerializerTransaction() {
    mSerializer.stop();
}

void FProg::Serializer::start(const std::string& classname) {
    assert(!mStarted);
    start_impl(classname);
    mStarted = true;
}

void FProg::Serializer::write(const Attribute& attr) {
    assert(mStarted);
    write_impl(attr);
}

void FProg::Serializer::stop() {
    assert(mStarted);
    stop_impl();
    mStarted = false;
}
