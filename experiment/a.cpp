#include <iostream>

using namespace std;

struct A {
    virtual void doit() = 0;
};

struct B : A {
    void doit() {

    }
};

int main(void) {
    for (int i = 0; i < 10000000; i++) {
        A *x = new B();
        B *y = (B *)(x);
        y->doit();
    }
}