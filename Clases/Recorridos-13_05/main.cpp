#include <iostream>
#include "Recorridos.h"

int main() {
    /*
            1
           / \
          2   3
         / \   \
        4   5   6
    */

    Nodo* raiz = new Nodo(1);
    raiz->izquierdo = new Nodo(2);
    raiz->derecho = new Nodo(3);
    raiz->izquierdo->izquierdo = new Nodo(4);
    raiz->izquierdo->derecho = new Nodo(5);
    raiz->derecho->derecho = new Nodo(6);

    cout << "Recorrido por niveles del árbol: ";
    recorridoPorNiveles(raiz);
    cout << endl;

    return 0;
}