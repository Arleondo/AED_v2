//Hacer un vector y una lista enlazada, las cuales tengan tiempos constante
#include <iostream>
#include <vector>
#include "Clases_V&Le.h"
using namespace std;


int main() {

    Vector_A<int> Wazaa(10);

    for (int i=0;i<10;i++){
        Wazaa.push_back(i);
    }
    cout << "[ ";Wazaa.print_v();
    cout << "]";
}
