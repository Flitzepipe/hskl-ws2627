#include <cassert>

int main() {
  int i = 10;
  // ab hier: i >= 10
  assert(i>=10);
  i = 1;
  assert(i>=10);
}
