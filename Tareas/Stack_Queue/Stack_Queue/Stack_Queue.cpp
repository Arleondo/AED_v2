#include "S&Q.hpp"

using namespace std;


int main() {

    Queue_a<int> Primera_cola(5);

    for (int i = 0; i < 3; i++) {
        if (i == 0) {
            cout << "Cola creada. :)\n"; i++;
        }
        int y;
        cout << "Insertar elemento:\n";
        cin >> y;
        Primera_cola.Push(y);
        if (i != 0) { i--; }
    }
}
