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

#include "common.h"
#include "concepts.h"
#include "stringserializer.h"
#include <fstream>
#include <algorithm>
#include <functional>
#include <iterator>
#include <sstream>

namespace FProg {
    class StringSerializer;
    template<typename C, typename Ser = StringSerializer>
    requires Container<C> // <> _constraint_ für den Template-Typ-Parameter `C`: `C` muss _Container_-Requirements erfüllen 
    class Database final {
    public:
        using value_type = C::value_type;
        using serializer = Ser;
        using deserializer = makeDeserializer<Ser>::type; // Metafunktion
        
        explicit Database(const std::string& filename);
        ~Database();
        Database& operator+=(const value_type& item);
        C find(const value_type& search) const;
        C find(const auto& f) const;
        size_t size() const;
        const C& items() const;
    private:
        std::string mFilename;
        C mItems;
    };
    
    template<typename C, typename Ser> requires Container<C>
    Database<C, Ser>::Database(const std::string& filename) : mFilename{filename} {
        std::ifstream istream{mFilename};
        if (istream.is_open()) {
            deserializer deserializer{std::string{std::istreambuf_iterator<char>(istream), std::istreambuf_iterator<char>()}};
            deserialize<value_type>(deserializer, std::back_inserter(mItems));
        }
    }
    
    template<typename C, typename Ser> requires Container<C>
    Database<C, Ser>::~Database() {
        std::ofstream ostream{mFilename};
        if (ostream.is_open()) {
            serializer serializer;
            std::for_each(std::begin(mItems), std::end(mItems), [&](const auto& i){i.serialize(serializer);});
            ostream << serializer << '\n';
        }
    }
    
    template<typename C, typename Ser> requires Container<C>
    Database<C, Ser>& Database<C, Ser>::operator+=(const value_type& item) {
        mItems.push_back(item);
        return *this;
    }
    
    template<typename C, typename Ser> requires Container<C>
    C Database<C, Ser>::find(const value_type& search) const {
        C result;
        std::copy_if(mItems.begin(), mItems.end(), std::back_inserter(result), search);
        return result;
    }
    
    template<typename C, typename Ser> requires Container<C>
    C Database<C, Ser>::find(const auto& f) const {
        C result;
        std::copy_if(mItems.begin(), mItems.end(), std::back_inserter(result), f);
        return result;
    }
    
    template<typename C, typename Ser> requires Container<C>
    size_t Database<C, Ser>::size() const {
        return mItems.size();
    }
    
    template<typename C, typename Ser> requires Container<C>
    const C& Database<C, Ser>::items() const {
        return mItems;
    }
    
    template<typename C, typename S>
    std::string to_string(const Database<C, S>& db){
        using value_type = Database<C>::value_type;
        std::stringstream ss;
        std::copy(std::begin(db.items()), std::end(db.items()), std::ostream_iterator<value_type>(ss, "\n")); // <> Verwendet `operator<<()` des Elementtyps
        return ss.str();
    }
    
    template<typename C, typename S>
    std::ostream& operator<<(std::ostream& out, const Database<C, S>& db) {
        return out << to_string(db);
    }
}
