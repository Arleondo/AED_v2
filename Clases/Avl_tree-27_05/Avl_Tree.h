#ifndef AVL_TREE_27_05_AVL_TREE_H
#define AVL_TREE_27_05_AVL_TREE_H

#include <iostream>
#include <algorithm>

template <class T>
struct Node {
    Node<T>* Nodos[2]; // Nodos[0] = Left, Nodos[1] = Right
    T valor;
    int altura;
    explicit Node(T valor, Node<T>* Left = nullptr, Node<T>* Right = nullptr)
        : valor(valor), altura(1) {
        Nodos[0] = Left;
        Nodos[1] = Right;
    }
};

template <class T>
class AVLTree {
    using Node = Node<T>;
    Node* root;


    Node* rotar(Node* y, bool dir) {
        Node* x = y->Nodos[!dir];
        y->Nodos[!dir] = x->Nodos[dir];
        x->Nodos[dir] = y;
        actualizar_altura(y);
        actualizar_altura(x);
        return x;
    }

    Node* balancear(Node* nodo) {
        actualizar_altura(nodo);
        int bal = balance(nodo);

        if (bal > 1) {
            if (balance(nodo->Nodos[0]) < 0)
                nodo->Nodos[0] = rotar(nodo->Nodos[0], 0); // Rotación izquierda
            return rotar(nodo, 1); // Rotación derecha
        }
        else if (bal < -1) {
            if (balance(nodo->Nodos[1]) > 0)
                nodo->Nodos[1] = rotar(nodo->Nodos[1], 1); // Rotación derecha
            return rotar(nodo, 0); // Rotación izquierda
        }
        return nodo;
    }

    Node* insertar(Node* nodo, T valor) {
        if (!nodo)
            return new Node(valor);

        bool dir = valor > nodo->valor;
        nodo->Nodos[dir] = insertar(nodo->Nodos[dir], valor);
        return balancear(nodo);
    }

    void inorder(Node* nodo) {
        if (!nodo) return;
        inorder(nodo->Nodos[0]);
        std::cout << nodo->valor << " ";
        inorder(nodo->Nodos[1]);
    }


public:

    AVLTree() : root(nullptr) {}

    void insertar(T valor) {
        root = insertar(root, valor);
    }

    void mostrarInorder() {
        inorder(root);
        std::cout << std::endl;
    }

    int altura(Node* n) {
        return n ? n->altura : 0;
    }

    int balance(Node* n) {
        return n ? altura(n->Nodos[0]) - altura(n->Nodos[1]) : 0;
    }

    void actualizar_altura(Node* n) {
        n->altura = 1 + std::max(altura(n->Nodos[0]), altura(n->Nodos[1]));
    }


};

#endif //AVL_TREE_27_05_AVL_TREE_H
