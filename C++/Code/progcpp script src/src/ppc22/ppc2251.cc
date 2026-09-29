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
#include <algorithm>

class A
{
    friend std::ostream& operator<<(std::ostream& out, const A& a);
public:
    A(int v) : mValue{v} {}
    const int& value() const {return mValue;}

    A(const A& o) : mValue(o.mValue) {
        std::cout << __PRETTY_FUNCTION__ << " " << mValue << std::endl;
    }
    A& operator=(const A& rhs) {
        std::cout << __PRETTY_FUNCTION__ << " " << mValue << " " << rhs.mValue << std::endl;
        A copy(rhs);
        swap(copy);
        return *this;
    }
    A(A&& o) {
        std::cout << __PRETTY_FUNCTION__ << " " << o.mValue << std::endl;
        swap(o);
    }
    A& operator=(A&& rhs) {
        std::cout << __PRETTY_FUNCTION__ << " " << mValue << " " << rhs.mValue << std::endl;
        swap(rhs);
        return *this;
    }
    void swap(A& o) {
        using std::swap;
        swap(mValue, o.mValue);
    }
private:
    int mValue{0};
};

std::ostream& operator<<(std::ostream& out, const A& a) {
    return out << a.mValue;
}

template<typename T>
std::ostream& operator<<(std::ostream& out, const std::vector<T>& v) {
    for(const auto& e: v) {
        if (&e != &v[0]) {
            std::cout << ',';
        }
        std::cout << e;
    }
    return out;
}

int main()
{
    //[remove
    std::vector<A> v{1, -1, 2, -2, 3, -3, 4, -4, 5, -5};
    std::cout << v << std::endl;;
    std::cout << "---" << std::endl; //-
    auto it = std::remove_if(std::begin(v), std::end(v), [](const A& v) {return v.value() <= 0;});
    std::cout << *it << std::endl;
    //]
    std::cout << v << std::endl;
    //[erase
    v.erase(it, std::end(v));
    std::cout << v << std::endl;
    //]

}
