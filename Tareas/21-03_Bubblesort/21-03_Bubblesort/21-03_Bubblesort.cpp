#include <iostream>
#include <chrono>
#include <random>
#include <algorithm>
#include <array>
#include "Bubblesorts.h"

using namespace std;

int main() {
    const int size = 50000;
    int arr[size] = {};


    for (int i = 0; i < size; i++) {
        arr[i] = i + 1;
    }

    random_device rd;
    mt19937 rng(rd());
    shuffle(arr, arr + size, rng);

    int arr2[size], arr3[size], arr4[size];
    copy_n(arr, size, arr2);
    copy_n(arr, size, arr3);
    copy_n(arr, size, arr4);

    array<double, 4> tiempos{};

    //Directo
    auto start = chrono::high_resolution_clock::now();
    direct_bubblesort(arr, size);
    auto end = chrono::high_resolution_clock::now();
    tiempos[0] = chrono::duration<double, milli>(end - start).count();

    //Polimorfismo
    Bubble_mayor bubblePoli;
    start = chrono::high_resolution_clock::now();
    bubblePoli.sort(arr2, size);
    end = chrono::high_resolution_clock::now();
    tiempos[1] = chrono::duration<double, milli>(end - start).count();

    //Puntero a función
    start = chrono::high_resolution_clock::now();
    bubblesort_componentes(arr3, size, puntero_menor); // puntero_menor debe estar definido como bool(int, int)
    end = chrono::high_resolution_clock::now();
    tiempos[2] = chrono::duration<double, milli>(end - start).count();

    //Functor (plantilla con comparador)
    Bubble_funtor<int, Cmenos<int>> bubbleFunctor;
    start = chrono::high_resolution_clock::now();
    bubbleFunctor(arr4, size);
    end = chrono::high_resolution_clock::now();
    tiempos[3] = chrono::duration<double, milli>(end - start).count();

    string metodos[4] = {
        "Bubble Sort Directo",
        "Polimorfismo (Bubble_mayor)",
        "Puntero a funcion (puntero_menor)",
        "Functor (Cmenos)"
    };

    cout << "Tiempos de ejecucion (ms):\n";
    for (int i = 0; i < 4; ++i) {
        cout << metodos[i] << ": " << tiempos[i] << " ms\n";
    }

    return 0;
}



/* Imprimir en grupos de 10 sin salirse del rango
for (int i = 0; i < 1000; i++) {
    cout << arr[i] << "\t";
    if ((i + 1) % 10 == 0) {
        cout << "\n";
    }
}
*/


