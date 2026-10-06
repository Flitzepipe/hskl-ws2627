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
    if (p.birthdate() != date::floor<date::days>(std::chrono::system_clock::now())) return false;

    return true;
};

SIMPLETEST("OutputOp"){
    using namespace date;
    Person p{Person::Lastname{"Tester"}, Person::Firstname{"Hugo"}};
    p.birthdate(2000_y/1/1);

    std::stringstream sstream;
    sstream << p;
    if(sstream.str() != R"(Person["Hugo","Tester",2000-01-01])" ) return false;
    return true;
};

SIMPLETEST("Setter"){
    using namespace date;

    Person p{Person::Firstname{"Bernd"}, Person::Lastname{"Brot"}};

    p.firstname("Helmut");
    p.lastname("Kohl");
    p.birthdate(year{1930}/apr/3);

    if (p.firstname() != "Helmut") return false;
    if (p.lastname() != "Kohl") return false;
    if (p.birthdate() != 1930_y/apr/3) return false;

    return true;
};

SIMPLETEST("equal1"){
    using namespace date;
    Person p1{Person::Firstname{"Hugo"}, Person::Lastname{"Tester"}, 2016_y/3/4};

    using namespace FProg::literals;

    Person p2{"Hugo"_first, "Tester"_last, 2016_y/3/4};

    if (p1 != p2) return false;
    if (!(p1 == p2)) return false;

    return true;
};

SIMPLETEST("equal2"){
    using namespace date;
    using namespace FProg::literals;

    Person p1{"Hugo"_first, "Tester"_last};
    Person p2{"Tester"_last, "Hugo"_first};

    if (p1 != p2) return false;
    if (!(p1 == p2)) return false;

    return true;
};

SIMPLETEST("equal3"){
    using namespace date;
    using namespace FProg::literals;
    Person p1{"Hugox"_first, "Tester"_last, 2016_y/3/4};
    Person p2{"Hugo"_first, "Tester"_last, 2016_y/3/4};

    if (p1 == p2) return false;
    if (!(p1 != p2)) return false;

    return true;
};

SIMPLETEST("equal4"){
    using namespace date;
    using namespace FProg::literals;
    Person p1{"Hugo"_first, "Testerx"_last};
    Person p2{"Hugo"_first, "Tester"_last};

    if (p1 == p2) return false;
    if (!(p1 != p2)) return false;

    return true;
};

SIMPLETEST("equal5"){
    using namespace date;
    using namespace FProg::literals;
    Person p1{"Hugo"_first, "Tester"_last, 2016_y/3/4};
    Person p2{"Hugo"_first, "Tester"_last, 2015_y/3/4};

    if (p1 == p2) return false;
    if (!(p1 != p2)) return false;

    return true;
};

SIMPLETEST("less1"){
    using namespace date;
    using namespace FProg::literals;
    Person p1{"Hugo"_first, "Tester"_last, 2015_y/3/4};
    Person p2{"Hugo"_first, "Tester"_last, 2015_y/3/4};

    if (p1 < p2) return false;
    if (!(p1 >= p2)) return false;

    return true;
};

SIMPLETEST("less2"){
    using namespace date;
    using namespace FProg::literals;
    Person p1{"Hugo"_first, "Sester"_last, 2015_y/3/4};
    Person p2{"Hugo"_first, "Tester"_last, 2015_y/3/4};

    if (!(p1 < p2)) return false;

    return true;
};

SIMPLETEST("less3"){
    using namespace date;
    using namespace FProg::literals;
    Person p1{"Fugo"_first, "Tester"_last, 2015_y/3/4};
    Person p2{"Hugo"_first, "Tester"_last, 2015_y/3/4};

    if (!(p1 < p2)) return false;

    return true;
};

SIMPLETEST("less4"){
    using namespace date;
    Person p1{Person::Firstname{"Hugo"}, Person::Lastname{"Tester"}, 2015_y/3/3};
    Person p2{Person::Firstname{"Hugo"}, Person::Lastname{"Tester"}, 2015_y/3/4};

    if (!(p1 < p2)) return false;

    return true;
};

const char* Person::mTokenStart = "person";
const char* Person::mTokenFirstname = "firstname";
const char* Person::mTokenLastname  = "lastname";
const char* Person::mTokenBirthdate = "birthdate";

Person::Person(const Firstname& firstname, const Lastname& lastname, const date::year_month_day& birthdate) :
    Person(firstname.mValue, lastname.mValue, birthdate)
{
    TRACE;
}

Person::Person(const Lastname& lastname, const Firstname& firstname, const date::year_month_day& birthdate) :
    Person(firstname.mValue, lastname.mValue, birthdate)
{
    TRACE;
}

Person::Person(const std::string& firstname, const std::string& lastname, const date::year_month_day& birthdate) :
    mFirstname{firstname},
    mLastname{lastname},
    mBirthdate{birthdate}
{
    TRACE;
}

const std::string& Person::lastname() const
{
    TRACE;
    return mLastname;
}

void Person::lastname(const std::string& lastname)
{
    TRACE;
    mLastname = lastname;
}

void Person::lastname(std::string&& lastname)
{
    TRACE;
    mLastname = std::move(lastname);
}

const std::string& Person::firstname() const
{
    TRACE;
    return mFirstname;
}

void Person::firstname(const std::string& firstname)
{
    TRACE;
    mFirstname = firstname;
}

void Person::firstname(std::string&& firstname)
{
    TRACE;
    mFirstname = std::move(firstname);
}

const date::year_month_day& Person::birthdate() const
{
    TRACE;
    return mBirthdate;
}

void Person::birthdate(const date::year_month_day& birthdate)
{
    TRACE;
    mBirthdate = birthdate;
}

void Person::birthdate(date::year_month_day&& birthdate)
{
    TRACE;
    mBirthdate = std::move(birthdate);
}

Serializer& Person::serialize(Serializer& serializer) const{
    SerializerTransaction st{serializer, mTokenStart};
    st.writeToken(Attribute{mTokenFirstname}.value(mFirstname));
    st.writeToken(Attribute{mTokenLastname}.value(mLastname));
    std::stringstream ss;
    ss << date::dateFormat(mBirthdate);
    st.writeToken(Attribute{mTokenBirthdate}.value(ss.str()));
    return serializer;
}

Optional<Person> Person::doDeserialize(Deserializer& deserializer){
    DeserializerTransaction dt{deserializer, mTokenStart};

    std::string firstname;
    if (!dt.readToken(mTokenFirstname, firstname)) return {};
    std::string lastname;
    if (!dt.readToken(mTokenLastname, lastname)) return {};
    std::string birthdateString;
    if (!dt.readToken(mTokenBirthdate, birthdateString)) return {};

    std::stringstream bss{birthdateString};

    int y = 0;
    int m = 0;
    int d = 0;
    date::year_month_day birthdate = date::year{y}/m/d;
    bss >> date::dateFormat(birthdate);

//    if (!deserializer.start(mTokenStart)) return{};
//    std::string firstname;
//    if (!deserializer.readToken(mTokenFirstname, firstname)) return {};
//    std::string lastname;
//    if (!deserializer.readToken(mTokenLastname, lastname)) return {};
//    std::string birthdateString;
//    if (!deserializer.readToken(mTokenBirthdate, birthdateString)) return {};

//    std::stringstream bss(birthdateString);

//    int y=0;
//    int m=0;
//    int d=0;
//    date::year_month_day birthdate = date::year{y}/m/d;
//    bss >> date::dateFormat(birthdate);

//    if (!deserializer.end()) return {};

    return Person{firstname, lastname, birthdate};
}

std::ostream& FProg::operator<<(std::ostream& out, const Person& person)
{
    TRACE;
    return out << "Person[" << std::quoted(person.mFirstname) << "," << std::quoted(person.mLastname)
               << "," << person.mBirthdate << "]";
}

bool FProg::operator==(const Person& lhs, const Person& rhs)
{
    return (lhs.mFirstname == rhs.mFirstname) && (lhs.mLastname == rhs.mLastname) && (lhs.mBirthdate == rhs.mBirthdate);
}

bool FProg::operator!=(const Person& lhs, const Person& rhs)
{
    return !(lhs == rhs);
}

bool FProg::operator<(const Person& lhs, const Person& rhs)
{
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

bool FProg::operator>=(const Person& lhs, const Person& rhs)
{
    return !(lhs < rhs);
}
