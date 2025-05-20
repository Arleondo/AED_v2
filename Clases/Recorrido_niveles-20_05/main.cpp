#include <iostream>
#include <queue>
using namespace std;

template <class T>
struct Node{
    Node<T>*nodes[2];
    T valor;

    explicit Node(T valor,Node<T>*left= nullptr,Node<T>*right= nullptr):valor(valor){
        nodes[0]=left; nodes[1]=right;};
};

int Level (Node<int>* n){
    if (!n) return 0;

    int l= Level(n->nodes[0]);
    int r= Level(n->nodes[1]);
    return  ((l>r)?l:r)+1;
}

template <class T>
int contarNiveles(Node<T>* root) {
    if (!root) return 0;

    queue<Node<T>*> q;
    q.push(root);
    int niveles = 0;

    while (!q.empty()) {
        int tamNivel = q.size();  // Número de nodos en el nivel actual
        for (int i = 0; i < tamNivel; ++i) {
            Node<T>* actual = q.front();
            q.pop();
            if (actual->nodes[0]) q.push(actual->nodes[0]);
            if (actual->nodes[1]) q.push(actual->nodes[1]);
        }
        ++niveles;  // Se ha procesado un nivel completo
    }

    return niveles;
}




int main() {
    // Crear manualmente un árbol completo de 5 niveles (31 nodos)
    Node<int>* n[31];
    for (int i = 0; i < 31; ++i) {
        n[i] = new Node<int>(i + 1);
    }

    // Asignar hijos: para cada nodo en la mitad superior del árbol (0 a 14),
    // el hijo izquierdo está en 2*i+1 y el derecho en 2*i+2
    for (int i = 0; i < 15; ++i) {
        n[i]->nodes[0] = n[2 * i + 1];
        n[i]->nodes[1] = n[2 * i + 2];
    }

    Node<int>* root = n[0];

    std::cout << "Árbol niveles:" << contarNiveles(root) <<std::endl;

    return 0;
}