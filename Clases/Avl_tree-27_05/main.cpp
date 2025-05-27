#include "Avl_Tree.h"

int main() {
    AVLTree<int> arbol;
    arbol.insertar(30);
    arbol.insertar(20);
    arbol.insertar(10);
    arbol.insertar(25);
    arbol.insertar(40);
    arbol.insertar(50);

    std::cout << "Recorrido Inorder del Árbol AVL:\n";
    arbol.mostrarInorder();

    return 0;
}