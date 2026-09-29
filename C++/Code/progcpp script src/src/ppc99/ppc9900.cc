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


#include <utility>
#include <vector>
#include <iostream>

#include <experimental/memory>

class A
{
public:
    A() {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
    }
    A(A&&) {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
    }
    A(const A&) {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
    }

    A& operator==(A&&) {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
        return *this;
    }
    A& operator=(const A&) {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
        return *this;
    }
};

bool operator==(const A&, const A&)
{
    return true;
}

// An unordered collection of values
template <typename T>
class Values
{
public:
    void add(T t);
    bool remove(T t);
    std::vector<T> const & values() const
    { return v; }
private:
    std::vector<T> v;
};

// Add a new item
template <typename T>
void Values<T>::add(T t) {
    v.push_back(t);
}

// Remove an item
// Returns true if removed, false if not present
template <typename T>
bool Values<T>::remove(T t) {
    bool found(false);

    //  for (auto i = 0; i != v.size(); ++i)

    // i != v.size() ist falsch wegen des pop_back: besser i < v.size() oder ein return

    //  for (decltype(v.size()) i = 0; i != v.size(); ++i)
    for (decltype(v.size()) i = 0; i < v.size(); ++i)
    {
        std::cout << "i: " << i << " size: " << v.size() << std::endl;
        if (v[i] == t) {
            v[i] = std::move(v.back()); // moving nicht möglich
            v.pop_back();
            found = true;
        }
    }
    return found;
}


void test() {
    //  Values<int> vi;
    Values<A> vi;

    A a;

    for (int i = 0; i != 10; ++i)
    {
        vi.add(a);
    }


    if (!vi.remove(a))
    {
        std::cout << "Can't remove 1\n";
    }
    if (vi.remove(a))
    {
        std::cout << "Can remove 1 twice\n";
    }

    A b;

    if (!vi.remove(b))
    {
        std::cout << "Can't remove 9\n";
    }
    std::cout << "size: " << vi.values().size() << std::endl;
}

int main() {
    test();

    std::experimental::observer_ptr<char> ptr;

//    const char* p{};

    if (int i = 4) {

    }

}

