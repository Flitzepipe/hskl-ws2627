void g(int*);

int main() {
    int a{1};
    g(&a);
    return a;
}
