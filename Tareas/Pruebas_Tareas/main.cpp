#include "S&Q.h"

using namespace std;


int main(){

    Queue_a<int> Primera_cola(5);

    for (int i = 0; i < 3; i++) {
        if (i == 1) {
            cout << "Cola creada. :)\n"; i++;
        }
        int y;
        cout << "Insertar elemento:\n";
        cin >> y;
        Primera_cola.Push(y);
    }
}
