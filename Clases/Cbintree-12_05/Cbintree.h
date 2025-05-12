#ifndef CBINTREE_12_05_CBINTREE_H
#define CBINTREE_12_05_CBINTREE_H

template <class T>
struct CBin_Node{
    CBin_Node<T>* Nodos[2];
    CBin_Node<T>* Left,* Right;
    T valor;

    explicit CBin_Node(T valor, CBin_Node<T>*Left=nullptr, CBin_Node<T>*Right=nullptr):
            valor(valor),Left(Left),Right(Right){Nodos[0]= nullptr; Nodos[1]= nullptr;};
};

template <class T>
class CBinTree{
    CBin_Node<T>* Root;

    CBin_Node<T>**& rep(CBin_Node<T>** pos){
        //por implementar
    }


public:

    CBinTree(): Root(nullptr){};

    bool find(T valor, CBin_Node<T>** & pos){
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

    bool Insert(T valor){
        CBin_Node<T>** p = & Root;

        if (!find(valor,p)){
            *p= new CBin_Node<T>(valor); return true;
        }
        return false;
    }

    bool Remove(T valor){
        CBin_Node<T>** p = & Root;

        if (find (valor,p)){
            //Caso 2
            if ( (*p)->Nodos[0] && (*p)->Nodos[1] ){
                CBin_Node<T>** q = rep(p);
                (*p)->v = (*q)->v ; p = q;
            }
            //Caso 1-0
            CBin_Node<T>* temp = *p; *p = (*p)->Nodos[(*p)->Nodos[1]!=nullptr];
            delete temp; return true;
        }
        return false;
    }

};


#endif
