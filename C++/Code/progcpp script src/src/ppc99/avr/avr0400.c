volatile unsigned int x1 = 1;
volatile unsigned int x2 = 2;
volatile unsigned int x3 = 0;

unsigned int func1() {
    return x1;
}

unsigned int func2() {
    return x2;
}

unsigned int func3() {
    return 0;
}

unsigned int check() {
  unsigned int result;

  result = func1();
  if (result != 0) 
     return result;

  result = func2();
  if (result != 0) 
     return result;

  result = func3();
  if (result != 0) 
     return result;

  return 0;  //keine Methode erfolgreich
}

int main() {
    unsigned int r = check();
    if (r > 0) {
        return r;
    }
    return 42;
}
