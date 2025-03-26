#include <iostream>
#include "Sort.h"

//libreria chrono
using namespace std;

int main() {
    Cmenos <int>p;
    int ar[4]={8,4,6,3};
    sort (ar,4, p);
    cout << "[ ";
    for (int i : ar){
        cout << i << ", ";
    }
    cout << "]\n";
    return 0;
}
