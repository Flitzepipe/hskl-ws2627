#include <stdint.h>
#include <stdio.h>

typedef union {
  struct {
    uint8_t start[4];
    uint8_t end[8];
  };
  uint8_t array[12];
} t_all_values_union;
extern t_all_values_union all_values;

t_all_values_union all_values;

void foo() {
    
  for (uint8_t i = 0; i < 12; i++) {
    all_values.array[i] = i;
  }
}

int eeprom_get(const char a, char* const p) {
    return 42;
}

char eeprom(int(*f)(char, char*), const char a) {
    char v;
    f(a, &v);
    return v;
}
int (*eeprom2(int(*f)(char, char*), const char a))(char*) {
    int l(char* const p) {
        return f(a, p);
    }
    return l;
}

typedef struct {
    uint8_t r;
    uint8_t g;
    uint8_t b;
    uint8_t o;
} rgb_t;

typedef union {
    rgb_t rgb;
    uint32_t data;        
} urgb_t;

int main(void) {
    urgb_t u;

    u.rgb.r = 42;
    u.rgb.g = 43;
    u.rgb.b = 44;
    printf("u= %d \n", u.data);
    
    char v = eeprom(eeprom_get, 1);
    eeprom2(eeprom_get, 1)(&v);
}
