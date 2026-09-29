#include "./lib/simpletest.h" 


int main() {

  SIMPLETEST("Nummer 1") { 

    // if (true) return true;
    if (2 > 5) return false;
    return true;
  };

   SIMPLETEST("Nummer 2") { 

    // if (true) return true;
    if (!true) return false;
    return true;
  };

   SIMPLETEST("Nummer 3") { 

    // if (true) return true;
    if (4 == 4) return true;
    return true;
  };
};
