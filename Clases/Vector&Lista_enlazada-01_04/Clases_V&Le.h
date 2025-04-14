#ifndef VECTOR_LISTA_ENLAZADA_01_04_CLASES_V_LE_H
#define VECTOR_LISTA_ENLAZADA_01_04_CLASES_V_LE_H

#include <iostream>
#include <stdexcept>

template <class T>
class Vector_A{
    int size; int cambiado=0;
    int capacidad ; T* array;

    void Aumento_de_tam(){
        int n_size= size/2+size;
        T* n_array = new T[n_size];
        for (int i=0;i<size;i++){
            n_array[i]=array[i];
        }
        delete[] array;
        array=n_array; cambiado++; size=n_size;
    };
    void Diminusion_de_tam(){
        int n_size = (size/3)*2;
        if (capacidad > n_size) return;
        T* n_array = new T[n_size];
        for (int i=0;i<n_size;i++){
            n_array[i]=array[i];
        }
        delete[] array;
        array = n_array; cambiado--; size = n_size;
    };

public:
    explicit Vector_A(int size):size(size),array(new T[size]),capacidad(0){};

    ~Vector_A() {
        delete[] array;
    }

    void push_back(T valor){
        array[capacidad]=valor; capacidad++;
        if (capacidad==size){ Aumento_de_tam(); }

    };

    void pop_back(){
        if (capacidad>0) {
            capacidad--;
            if (capacidad < (size / 3) * 2 && cambiado > 0) { Diminusion_de_tam(); }
            return;
        }
        std::cout << "Vector vacio papu";

    };

    void push_front(T valor){
        capacidad++;
        if (capacidad==size){ Aumento_de_tam(); }
        for (int i=0; i<capacidad-1;i++){
            std::swap(array[i],array[i+1]);
        }

    };

    void pop_front(){
        if (capacidad>0) {
            capacidad--;
            if (capacidad < (size / 3) * 2 && cambiado > 0) { Diminusion_de_tam(); }
            for (int i=0;i<=capacidad-1;i++){
                std::swap(array[i],array[i+1]);
            }
            return;
        }
        std::cout << "Vector vacio papu";
    };

    T& operator[] (int index){
        if (index<size){
            return array[index];
        }
        throw std::out_of_range("Te excediste papu");
    };

    void print_v(){
        for (int i=0;i<capacidad;i++){
            std::cout << array[i] << " ";
        }
    }

};

template <class T>
struct Node{
    Node* next; Node* prev;
    T valor;
    explicit Node(T valor,Node* next=nullptr,Node* prev=nullptr):valor(valor),next(next),prev(prev){};
};
2
template <class T>
class Lista_enlazada{
    Node<T>* Head; Node<T>* Tail;
    int size=0;
public:

    Lista_enlazada(std::initializer_list<T> values = 0) : Head(nullptr),Tail(nullptr) {
        if (values!=0) {
            for (const T &value: values) {
                push_back(value);
            }
        }
    }
    ~Lista_enlazada(){
        while (Head) {
            Node<T>* tmp = Head;
            Head = Head->next;
            delete tmp;
        }
    };

    void push_back(T valor){
        if (!Head) {
            Head = new Node<T>(valor); Tail = Head; return;
        }
        Tail->next = new Node<T>(valor, nullptr, Tail);
        Tail=Tail->next;
    }

    T pop_back(){
        if (Tail) {
            T regreso = Tail->valor; Tail = Tail->prev;
            delete Tail->next; Tail->next = nullptr;
            return regreso;
        }
    }

    void push_front(T valor){
        if (!Head){
            Head = new Node<T>(valor); Tail = Head; return;
        }
        Head->prev = new Node<T>(valor,Head, nullptr);
        Head = Head->prev;
    }

    T pop_front(){
        if (Head){
            T regreso = Head->valor; Head = Head->next;
            delete Head->prev; Head->prev = nullptr;
            return regreso;
        }
    }

    T& operator[](int index){
        if (index >= size/2){

        }
    }

    void print_v(){}

};



#endif
