#ifndef RECORRIDOS_13_05_RECORRIDOS_H
#define RECORRIDOS_13_05_RECORRIDOS_H

#include <queue>
using namespace std;
struct Nodo {
    int valor;
    Nodo* izquierdo;
    Nodo* derecho;

    explicit Nodo(int val) : valor(val), izquierdo(nullptr), derecho(nullptr) {}
};

// Función para hacer recorrido por niveles
void recorridoPorNiveles(Nodo* raiz) {
    if (!raiz) return;

    queue<Nodo*> cola;
    cola.push(raiz);

    while (!cola.empty()) {
        Nodo* actual = cola.front();
        cola.pop();

        cout << actual->valor << " ";

        if (actual->izquierdo)
            cola.push(actual->izquierdo);
        if (actual->derecho)
            cola.push(actual->derecho);
    }
}


#endif
