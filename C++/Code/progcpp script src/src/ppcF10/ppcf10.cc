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

#include <iostream>
#include <vector>
#include <list>

#include "person.h"
#include "database.h"
#include "heaparray40.h"

#include "../lib/tracer.h"

using namespace FProg;

int main(const int argc, const char* const* const argv) {
    TRACE;
//    std::vector<std::string_view> args1{argv + 1, argv + argc};
    std::vector<std::string> args{argv + 1, argv + argc};

    Database<FProg::HeapArray<Person, int>> db("db.txt");
//    Database<std::vector<Person>> db("db.txt");

    if (args.size() == 0) {
        std::cout << "Database:\n";
        std::cout << db << '\n';
    }
    else if (args.size() == 1) {
        if (args[0] == "sorted") {
            auto items = db.items();
            FProg::sort(items);
            for (const Person& p: items) {
                std::cout << p << '\n';
            }
        }
        else {
            std::cerr << "wrong command\n";
        }
    }
    else if (args.size() == 2) {
        if (args[0] == "search") {
            std::cout << "Search results:\n";
            auto result = db.find(Person::fuzzyComparator(args[1]));
            FProg::sort(result);
            for(const Person& p: result) {
                std::cout << p << '\n';
            }
        }
        else {
            std::cerr << "wrong command\n";
        }
    }
    else if (args.size() == 3) {
        if (args[0] == "add") {
            db += Person(Person::Firstname{args[1]}, Person::Lastname{args[2]});
        }
        else {
            std::cerr << "wrong command\n";
        }
    }
    else {
        std::cerr << "too many arguments\n";
    }
}
