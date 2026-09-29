#include <set>
#include <iostream>

using S = std::set<int>;
using std::cout;
using std::endl;

int main() {
    S s = { 1, 2 };
    
    for (int i = 0; i < 3; ++i) {
        auto f = s.find(i);
        if (f != std::end(s))
            cout << "found " << *f << endl;
        else
            cout << "not found" << endl;
    }
}
