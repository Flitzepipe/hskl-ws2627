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

#pragma once

#include <string>
#include <iosfwd>
#include <vector>

#include <fstream>
#include <algorithm>
#include <functional>
#include <iterator>

#include "stringserializer.h"
#include "concepts.h"

namespace FProg {

template<typename C>
requires Container<C> // <> _constraint_ für den Template-Typ-Parameter `C`: `C` muss _Container_-Requirements erfüllen 
class Database final {
public:
    typedef typename C::value_type item_type;

    explicit Database(const std::string& filename) :
        mFilename(filename),
        mItems() {
        std::ifstream istream(mFilename);
        if (istream.is_open()) {
            StringDeserializer deserializer{std::string{std::istreambuf_iterator<char>(istream), std::istreambuf_iterator<char>()}};
            // todo: remove explicit instantiation
            FProg::deserialize<item_type>(deserializer, std::back_inserter(mItems));
            // maybe op>> / iterator style
        }
    }

    ~Database() {
        std::ofstream ostream(mFilename);
        if (ostream.is_open()) {
            StringSerializer serializer;
            std::for_each(std::begin(mItems), std::end(mItems), [&](const auto& i){i.serialize(serializer);});
            ostream << serializer << '\n';
        }
    }

    Database& operator+=(const item_type& item) {
        mItems.push_back(item);
        return *this;
    }

    C find(const item_type& search) const {
        C result;
        std::copy_if(mItems.begin(), mItems.end(), std::back_inserter(result), search);
        return result;
    }

    C find(const std::function<bool(const item_type&)>& f) const {
        C result;
        std::copy_if(mItems.begin(), mItems.end(), std::back_inserter(result), f);
        return result;
    }

    std::string toString() const {
        std::stringstream ss;
        std::copy(std::begin(mItems), std::end(mItems), std::ostream_iterator<item_type>(ss, "\n")); // <> Verwendet `operator<<()` des Elementtyps
        return ss.str();
    }

    size_t size() const {
        return mItems.size();
    }

    const C& items() const {
        return mItems;
    }

private:
    std::string mFilename;
    C mItems;
};

template<typename C>
std::ostream& operator<<(std::ostream& out, const Database<C>& db) {
    return out << db.toString();
}

}
