#include <iostream>
#include <chrono>
#include <random>
#include <algorithm>
#include "Bubblesorts.h"
using namespace std;

int main() {
    int size = 1000;
    int* arr = new int[size];

    for (int i = 0; i < size; i++) {
        arr[i] = i + 1;
    }
    random_device rd;
    mt19937 rng(rd());
    shuffle(arr, arr + size, rng);


    void (*ptr_sort)(int*, long) = direct_bubblesort;
    ptr_sort(arr, 1000);


    // Imprimir en grupos de 10 sin salirse del rango
    for (int i = 0; i < 1000; i++) {
        cout << arr[i] << "\t";
        if ((i + 1) % 10 == 0) {
            cout << "\n";
        }
    }

    return 0;
}