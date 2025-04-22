#ifndef SORTED_LINKED_LIST_22_04_LINKED_LIST_H
#define SORTED_LINKED_LIST_22_04_LINKED_LIST_H

#include <iostream>

template <class T>
class Node{
    T valor;
    Node<T>* next;

    explicit Node(T valor,Node<T>* next= nullptr):valor(valor),next(next){};
};

template <class T>
class Linked_list{
    Node<T>* Head;
    int size = 0;

public:

    Linked_list():Head(nullptr){};

    bool Find(T v, Node<T>**& Iterador){
        Iterador=&Head;
        while (*Iterador && (*Iterador)->valor<v){
            Iterador=&((*Iterador)->next);
        }
        return *Iterador && (*Iterador)->valor==v;
    }

    bool Ins(T v){
        Node<T>** p;
        if (Find(v,p)) return false;
        auto* nuevo =new Node<T>(v,*p);
        *p=nuevo; size++; return true;
    }

    bool Rem(T v){
        Node<T>** p;
        if (!Find(v,p)) return false;
        auto* Del=*p;
        *p = Del->next; delete Del;
        size--; return true;
    }
};





#endif