#ifndef SORTED_FORWARD_LIST_15_04_SORTEDFL_H
#define SORTED_FORWARD_LIST_15_04_SORTEDFL_H


template<class T>
struct Nodo{
    T valor;
    Nodo* next;

    explicit Nodo(T valor, Nodo* sgte = nullptr):valor(valor),next(sgte){};
};

template <class T>
class Lista_ordenada{
    Nodo<T>* Head;
    int size;
public:

    Lista_ordenada():Head(nullptr),size(0){};

    ~Lista_ordenada(){
        auto remove= Head;
        for (;remove; remove=remove->next){
            delete[] remove;
        }
    };

    Nodo<T>** find(T x){};

    void ins(T valor){
        Nodo<T>** cambio = *find(valor);



    };

    void rem(T& valor=0){};


};







#endif