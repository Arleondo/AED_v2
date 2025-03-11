#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
    int a = 7, * Iptr = &a, ** DIptr = &Iptr;
    int * SIptr;
    *Iptr = a;
    cout << Iptr << "\n" << a << "\n";
    DIptr = & SIptr;
    ** DIptr = 80;
    cout << DIptr << "\n";

    return 127;
}
