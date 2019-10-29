#include "a.hpp"

int main(void) {
    Hello *x = new Hello();
    int v = x->doit();
    return v;
}