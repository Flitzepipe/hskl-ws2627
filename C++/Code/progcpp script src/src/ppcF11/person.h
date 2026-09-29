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

#include "serializable.h"
#include "util.h"
#include "date.h"

namespace FProg {
    class Person final : public Serializable<Person> { // CRTP
        friend constexpr std::unique_ptr<Person[]> std::make_unique<Person[]>(size_t s); // <> Benötigt den std-ctor

        friend std::ostream& operator<<(std::ostream& out, const Person& person);
        friend bool operator==(const Person& lhs, const Person& rhs);
        friend bool operator<(const Person& lhs, const Person& rhs);
    public:
        struct Firstname {
            const std::string mValue;
        };
        struct Lastname {
            const std::string mValue;
        };
        
        Person(const Firstname& firstname, const Lastname& lastname,
               const Date& birthdate = Date::today());
        
        Person(const Lastname& lastname, const Firstname& firstname,
               const Date& birthdate = Date::today());
        
        const std::string& lastname() const;
        void lastname(const std::string& lastname);
        
        const std::string& firstname() const;
        void firstname(const std::string& firstname);
        
        const Date& birthdate() const;
        void birthdate(const Date& birthdate);
        
        Serializer& serialize(Serializer& serializer) const override;
        
        static std::optional<Person> doDeserialize(Deserializer& deserializer);
        
        inline static auto makeFuzzyComparator(const std::string& s) {
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
        
    private:
        inline Person() = default; // fuer eigenes array wird der std-ctor benötigt
        
        Person(const std::string& firstname, const std::string& lastname,
               const Date& birthdate);
        
        std::string mFirstname;
        std::string mLastname;
        Date mBirthdate = Date::today();
        
        static inline const char* mTokenStart{"person"};
        static inline const char* mTokenFirstname{"firstname"}; 
        static inline const char* mTokenLastname{"lastname"};
        static inline const char* mTokenBirthdate{"birthdate"};
    };
    
    std::string to_string(const Person& p);
    std::ostream& operator<<(std::ostream& out, const Person& person);
    
    bool operator==(const Person& lhs, const Person& rhs);
    bool operator!=(const Person& lhs, const Person& rhs);
    bool operator<(const Person& lhs, const Person& rhs);
    bool operator>=(const Person& lhs, const Person& rhs);
    
    namespace literals {
        inline Person::Firstname operator"" _first(const char* s, size_t) {
            return Person::Firstname{s};
        }
        inline Person::Lastname operator"" _last(const char* s, size_t) {
            return Person::Lastname{s};
        }
        
    }
}
