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

#include "person.h"

#include <sstream>
#include <iomanip>
#include <algorithm>

#include "../lib/simpletest.h"
#include "util.h"

#define NO_TRACE
#include "../lib/tracer.h"

using namespace std::literals::string_literals;
using namespace FProg;

SIMPLETEST("Ctor"){
    Person p{Person::Firstname{"Hugo"}, Person::Lastname{"Tester"}};

    if (p.firstname() != "Hugo") return false;
    if (p.lastname() != "Tester") return false;
    if (p.birthdate() != Date::today()) return false;

    return true;
};

SIMPLETEST("OutputOp"){
    Person p{Person::Lastname{"Tester"}, Person::Firstname{"Hugo"}};
    p.birthdate(Date{Day{1}, Month{2}, Year{1999}});
    std::stringstream sstream;
    sstream << p;
    if(sstream.str() != R"(Person["Hugo","Tester",1999-2-1])" ) return false;
    return true;
};

SIMPLETEST("Setter"){
    Person p{Person::Firstname{"Bernd"}, Person::Lastname{"Brot"}};

    p.firstname("Helmut");
    p.lastname("Kohl");
    p.birthdate(Date::today());

    if (p.firstname() != "Helmut") return false;
    if (p.lastname() != "Kohl") return false;
    if (p.birthdate() != Date::today()) return false;
    
    return true;
};

SIMPLETEST("equal1"){
    Person p1{Person::Firstname{"Hugo"}, Person::Lastname{"Tester"}};

    using namespace FProg::literals;

    Person p2{"Hugo"_first, "Tester"_last};

    if (p1 != p2) return false;
    if (!(p1 == p2)) return false;

    return true;
};

SIMPLETEST("equal2"){
    using namespace FProg::literals;

    Person p1{"Hugo"_first, "Tester"_last};
    Person p2{"Tester"_last, "Hugo"_first};

    if (p1 != p2) return false;
    if (!(p1 == p2)) return false;

    return true;
};

SIMPLETEST("equal3"){
    using namespace FProg::literals;
    Person p1{"Hugox"_first, "Tester"_last};
    Person p2{"Hugo"_first, "Tester"_last};

    if (p1 == p2) return false;
    if (!(p1 != p2)) return false;

    return true;
};

SIMPLETEST("equal4"){
    using namespace FProg::literals;
    Person p1{"Hugo"_first, "Testerx"_last};
    Person p2{"Hugo"_first, "Tester"_last};

    if (p1 == p2) return false;
    if (!(p1 != p2)) return false;

    return true;
};

SIMPLETEST("equal5"){
    using namespace FProg::literals;
    Person p1{"Hugo"_first, "Tester"_last};
    Person p2{"Hugo"_first, "Tester"_last};

    if (!(p1 == p2)) return false;
    if ((p1 != p2)) return false;

    return true;
};

SIMPLETEST("less1"){
    using namespace FProg::literals;
    Person p1{"Hugo"_first, "Tester"_last};
    Person p2{"Hugo"_first, "Tester"_last};

    if (p1 < p2) return false;
    if (!(p1 >= p2)) return false;

    return true;
};

SIMPLETEST("less2"){
    using namespace FProg::literals;
    Person p1{"Hugo"_first, "Sester"_last};
    Person p2{"Hugo"_first, "Tester"_last};

    if (!(p1 < p2)) return false;

    return true;
};

SIMPLETEST("less3"){
    using namespace FProg::literals;
    Person p1{"Fugo"_first, "Tester"_last};
    Person p2{"Hugo"_first, "Tester"_last};

    if (!(p1 < p2)) return false;

    return true;
};

SIMPLETEST("less4"){
    Person p1{Person::Firstname{"Hugo"}, Person::Lastname{"Tester"}};
    Person p2{Person::Firstname{"Hugo"}, Person::Lastname{"Tester"}};

    p2.birthdate(Date::julianDayNumberToDate(p1.birthdate().julianDay() + 1));
    
    if (!(p1 < p2)) return false;

    return true;
};

Person::Person(const Firstname& firstname, const Lastname& lastname, const Date& birthdate) :
    Person(firstname.mValue, lastname.mValue, birthdate){
    TRACE;
}

Person::Person(const Lastname& lastname, const Firstname& firstname, const Date& birthdate) :
    Person(firstname.mValue, lastname.mValue, birthdate){
    TRACE;
}

Person::Person(const std::string& firstname, const std::string& lastname, const Date& birthdate) :
    mFirstname{firstname},
    mLastname{lastname},
    mBirthdate{birthdate}{
    TRACE;
}

const std::string& Person::lastname() const{
    TRACE;
    return mLastname;
}

void Person::lastname(const std::string& lastname){
    TRACE;
    mLastname = lastname;
}

const std::string& Person::firstname() const{
    TRACE;
    return mFirstname;
}

void Person::firstname(const std::string& firstname){
    TRACE;
    mFirstname = firstname;
}

const Date& Person::birthdate() const{
    TRACE;
    return mBirthdate;
}

void Person::birthdate(const Date& birthdate){
    TRACE;
    mBirthdate = birthdate;
}

Serializer& Person::serialize(Serializer& serializer) const{
    SerializerTransaction st{serializer, mTokenStart};
    st.write(Attribute{mTokenFirstname}.value(mFirstname));
    st.write(Attribute{mTokenLastname}.value(mLastname));
    st.write(Attribute{mTokenBirthdate}.value(mBirthdate.julianDay()));
    return serializer;
}

std::optional<Person> Person::doDeserialize(Deserializer& deserializer){
    DeserializerTransaction dt{deserializer, mTokenStart};

    const auto firstAttr = dt.read(mTokenFirstname);
    if (!firstAttr) return {};
    const auto lastAttr = dt.read(mTokenLastname);
    if (!lastAttr) return {};
    const auto dateAttr = dt.read(mTokenBirthdate);
    if (!dateAttr) return {};

    assert(firstAttr);
    assert(lastAttr);
    assert(dateAttr);
    
    const Date birthdate = Date::julianDayNumberToDate(stoi(dateAttr->value()));
    return Person{firstAttr->value(), lastAttr->value(), birthdate};
}

std::string FProg::to_string(const Person& p) {
    std::stringstream ss;
    ss << p;
    return ss.str();    
}

std::ostream& FProg::operator<<(std::ostream& out, const Person& person){
    return out << "Person[" << std::quoted(person.mFirstname) << "," << std::quoted(person.mLastname)
               << "," << person.mBirthdate << "]";
}

bool FProg::operator==(const Person& lhs, const Person& rhs){
    return (lhs.mFirstname == rhs.mFirstname) && (lhs.mLastname == rhs.mLastname) && (lhs.mBirthdate == rhs.mBirthdate);
}

bool FProg::operator!=(const Person& lhs, const Person& rhs){
    return !(lhs == rhs);
}

bool FProg::operator<(const Person& lhs, const Person& rhs){
    if (lhs.mLastname < rhs.mLastname) {
        return true;
    }
    else if (lhs.mLastname > rhs.mLastname) {
        return false;
    }
    else {
        if (lhs.mFirstname < rhs.mFirstname) {
            return true;
        }
        else if (lhs.mFirstname > rhs.mFirstname) {
            return true;
        }
        else {
            if (lhs.mBirthdate < rhs.mBirthdate) {
                return true;
            }
            return false;
        }
    }
}

bool FProg::operator>=(const Person& lhs, const Person& rhs) {
    return !(lhs < rhs);
}
