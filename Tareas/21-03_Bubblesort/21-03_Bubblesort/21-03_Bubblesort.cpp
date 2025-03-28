#include <iostream>
#include <chrono>
#include <random>
#include <algorithm>
#include <array>
#include "Bubblesorts.h"
using namespace std;

int main() {
    const int size = 5000;
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

    // Medir el tiempo de cada sort
    array<double, 4> tiempos{};

    auto start = chrono::high_resolution_clock::now();
    direct_bubblesort(arr, size);
    auto end = chrono::high_resolution_clock::now();
    tiempos[0] = chrono::duration<double, milli>(end - start).count();

    Bubble_mayor Bubble;
    start = chrono::high_resolution_clock::now();
    Bubble.sort(arr2, size);
    end = chrono::high_resolution_clock::now();
    tiempos[1] = chrono::duration<double, milli>(end - start).count();

    Cmenos comparador;
    start = chrono::high_resolution_clock::now();
    bubblesort_componentes<Cmenos>(arr3, size, comparador);
    end = chrono::high_resolution_clock::now();
    tiempos[2] = chrono::duration<double, milli>(end - start).count();

    Bubble_funtor<int> bubbleFunctor;
    start = chrono::high_resolution_clock::now();
    bubbleFunctor(arr4, size);
    end = chrono::high_resolution_clock::now();
    tiempos[3] = chrono::duration<double, milli>(end - start).count();

    // Imprimir tiempos
    cout << "Tiempos de ejecucion (ms):\n";
    for (int i = 0; i < 4; ++i) {
        cout << "Metodo " << i + 1 << ": " << tiempos[i] << " ms\n";
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


