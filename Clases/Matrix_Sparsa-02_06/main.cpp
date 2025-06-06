#include "Matrix_Spr.h"
using namespace std;

int main() {
    SparseMatrix mat(4, 5);

    mat.set(0, 1, 5);
    mat.set(2, 3, 10);
    mat.set(3, 4, -2);

    cout << "Matriz completa:\n";
    mat.print();

    cout << "\nSolo elementos no cero:\n";
    mat.printNonZeroElements();

    return 0;
}
