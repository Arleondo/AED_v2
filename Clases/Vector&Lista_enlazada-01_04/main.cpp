//Hacer un vector y una lista enlazada, las cuales tengan tiempos constantes
#include <iostream>
#include <vector>
#include "Clases_V&Le.h"
using namespace std;


int main() {

    Vector_A<int> wazaa(10);

    for (int i=0;i<10;i++){
        wazaa.push_back(i);
    }
    cout << "[ ";wazaa.print_v();
    cout << "]";


}
