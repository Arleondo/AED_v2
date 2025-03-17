#include <iostream>
using namespace std;

int main() {
    void * a ;
    int entero = 6;
    int * ptr_entero = &entero;
    char letra = 'b';
    a = ptr_entero;
    *(int *)a = 90;

    *( char *)a = letra;
    cout << *(int*)a << "\n" << *(char*)a;
}
