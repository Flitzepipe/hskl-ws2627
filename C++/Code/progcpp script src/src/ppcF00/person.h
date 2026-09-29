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

#include <string>
#include <iosfwd>
#include <memory>

#include "../lib/date.h"

#include "serializable.h"
#include "util.h"
#include "namedtype.h"

namespace FProg {
    class Person final : public Serializable<Person> {
        friend constexpr std::unique_ptr<Person[]> std::make_unique<Person[]>(size_t s); // <> Benötigt den std-ctor
        
        friend std::ostream& operator<<(std::ostream& out, const Person& person);
        friend bool operator==(const Person& lhs, const Person& rhs);
        friend bool operator<(const Person& lhs, const Person& rhs);
    public:
        using FirstName = NamedType<std::string, struct FirstNameType>;
        using LastName  = NamedType<std::string, struct LastNameType>;
        
        Person(const FirstName& firstname, const LastName& lastname,
               const date::year_month_day& birthdate = date::floor<date::days>(std::chrono::system_clock::now())
                );
        Person(const LastName& firstname, const FirstName& lastname,
               const date::year_month_day& birthdate = date::floor<date::days>(std::chrono::system_clock::now())
                );
        
        const std::string& lastname() const;
        void lastname(const std::string& lastname);
        void lastname(std::string&& lastname);
        
        const std::string& firstname() const;
        void firstname(const std::string& firstname);
        void firstname(std::string&& firstname);
        
        const date::year_month_day& birthdate() const;
        void birthdate(const date::year_month_day& birthdate);
        void birthdate(date::year_month_day&& birthdate);
        
        Serializer& serialize(Serializer& serializer) const override;
        
        static Optional<Person> doDeserialize(Deserializer& deserializer);
        
        inline static auto fuzzyComparator(const std::string& s) {
            return [=](const Person& person) {
                std::string lower = FProg::toLower(s);
                if (FProg::toLower(person.firstname()) == lower) {
                    return true;
                }
                else if (FProg::toLower(person.lastname()) == lower) {
                    return true;
                }
                return false;
            };
        }
        
        Person() = default;
    private:
        
        Person(const std::string& firstname, const std::string& lastname,
               const date::year_month_day& birthdate);
        
        std::string mFirstname;
        std::string mLastname;
        date::year_month_day mBirthdate = date::floor<date::days>(std::chrono::system_clock::now());
        
        // inline
        static const char* mTokenStart;
        static const char* mTokenFirstname;
        static const char* mTokenLastname;
        static const char* mTokenBirthdate;
    };
    
    std::ostream& operator<<(std::ostream& out, const Person& person);
    
    bool operator==(const Person& lhs, const Person& rhs);
    bool operator!=(const Person& lhs, const Person& rhs);
    bool operator<(const Person& lhs, const Person& rhs);
    bool operator>=(const Person& lhs, const Person& rhs);
    
    namespace literals {
        inline Person::FirstName operator"" _first(const char* s, size_t) {
            return Person::FirstName{s};
        }
        inline Person::LastName operator"" _last(const char* s, size_t) {
            return Person::LastName{s};
        }
        
    }
    
}
