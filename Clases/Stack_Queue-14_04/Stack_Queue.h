#ifndef STACK_QUEUE_14_04_STACK_QUEUE_H
#define STACK_QUEUE_14_04_STACK_QUEUE_H

#include "D:\AED_v2\Clases\Vector&Lista_enlazada-01_04\Clases_V&Le.h"

template <class T,class C>
class Stack_mascara{
    C* contenedor;

public:
    Stack_mascara(C estructura):contenedor(&estructura){};

    void push(T x) {
        contenedor->push_back(x);
    }

    void pop(T& valor){
        contenedor->pop_back();
    }

};

template <class T, class C>
class Queue_mascara{
    C* contenedor;

public:
    Queue_mascara(C estructura):contenedor(&estructura){};

    void push(T x){
        contenedor->push_back(x);
    }
    void pop(T& valor){
        contenedor->pop_front();
    }

};

#endif
