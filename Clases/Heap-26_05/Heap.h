#ifndef HEAP_26_05_HEAP_H
#define HEAP_26_05_HEAP_H

#include <iostream>
#include <vector>

using namespace std;

template<class T>
bool Greater(T a, T b){
    return a>b;
};

template<class T>
bool Less(T a, T b){
    return a<b;
};

template <class O,class T>
class Heap{
    vector<T> Arbol;
    O Op;
public:

    bool push (T valor){
        Arbol.push_back(valor);
        auto* Ultimo = Arbol[Arbol.size()];
        while (Op (*Ultimo,*((Ultimo-1)/2)) ){
            std::swap( *Ultimo,*((Ultimo-1)/2) );
            Ultimo=(Ultimo-1)/2;
        }
    }

    bool pop (T valor){


    }

    bool empty(){
        return Arbol.empty();
    };

};



#endif //HEAP_26_05_HEAP_H
