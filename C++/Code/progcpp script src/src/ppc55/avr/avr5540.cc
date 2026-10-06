volatile int a = 851;
volatile int b = 33;

int main() {
    int x = a % b;    
    int y = a * b;
    return x + y;
}
