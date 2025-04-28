#ifndef ARBOLES_BINARIOS_28_04_ARBOLITO_H
#define ARBOLES_BINARIOS_28_04_ARBOLITO_H

template <class T>
struct Node_arbol{
    Node_arbol<T>* Nodos[2];
    Node_arbol<T>* Left,* Right;
    T valor;

    explicit Node_arbol(T valor,Node_arbol<T>*Left=nullptr,Node_arbol<T>*Right=nullptr):
            valor(valor),Left(Left),Right(Right){Nodos[0]= nullptr; Nodos[1]= nullptr;};
};

template <class T>
class Arbol_binario{
    Node_arbol<T>* Root;
public:

    Arbol_binario():Root(nullptr){};

    bool find(T valor,Node_arbol<T>** & pos){
        pos = & Root;

        /*
        while (*pos && (*pos)->valor!=valor ){
            if(valor<(*pos)->valor){
                pos = & ((*pos)->Left);
            }
            pos = &((*pos)->Right);
        }
        */

        while (*pos && (*pos)->valor!=valor){
            pos = &((*pos)->Nodos[(valor >= (*pos)->valor)]);
        }

        return *pos!= nullptr;
    }

    void Insert(T valor){
        Node_arbol<T>** p;

        if (!find(valor,p)){
            *p= new Node_arbol<T>(valor);
        }
    }

    bool Remove(T valor){
        Node_arbol<T>** p;

        if (find (valor,p)){
            Node_arbol<T>* t = *p; *p= nullptr;
            delete t;
        }
    }

};











#endif
