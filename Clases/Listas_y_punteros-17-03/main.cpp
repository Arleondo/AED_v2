#include <iostream>

using namespace std;

char *c=new char;

int main() {
    int ar[4]={6,8,10,4};
    //const int * ar;
    int *p = ar; cout << *p << "\n";
    //Error ar=p;
    p++; cout << *p << "\n"; //avanza a uno *p=1 -> *p = 2
    //error ar++; debido a que es constante
    *(p+2); cout << *p << "\n"; //1 no hace nada , 2 no mueve el puntero
    *(p+2) = 9; cout << *p << "\t" << ar[3] << "\n"; //1 cambia la position de ar[3], 2 no mueve el puntero
    *(p+4) = 3; cout << *p << "\t" << ar[5] << "\n"; //permite acceder a ar[5] atravez de p, 2 p no se mueve
    // Memoria dinamica
    int * z = new int [100], *w = z;

    for (;w<=&z[99];w++){ *w = 100;}

    delete []z;

    for (int *Iptr = z; Iptr<=&z[99]; Iptr=Iptr+10){
        for (int i=0;i<10;i++) {
            cout << *(Iptr+i) << "  ";
        }
        cout << "\n";
    }

    return 0;
}
