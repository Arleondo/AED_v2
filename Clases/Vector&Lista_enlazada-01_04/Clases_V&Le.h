#ifndef VECTOR_LISTA_ENLAZADA_01_04_CLASES_V_LE_H
#define VECTOR_LISTA_ENLAZADA_01_04_CLASES_V_LE_H

#include <iostream>
#include <stdexcept>

template <class T>
class Vector_A{
    int size; int cambiado=0;
    int capacidad ; T* array;

    void Aumento_de_tam(){
        int n_size=size/2;
        T* n_array = new T[n_size];
        for (int i=0;i<size;i++){
            n_array[i]=array[i];
        }
        delete[] array;
        array=n_array; cambiado++; size=n_size;
    };
    void Diminusion_de_tam(){
        int n_size = (size/3)*2;
        T* n_array = new T[n_size];
        for (int i=0;i<n_size;i++){
            n_array[i]=array[i];
        }
        delete[] array;
        array = n_array; cambiado--; size = n_size;
    };

public:
    explicit Vector_A(int size):size(size),array(new T[size]),capacidad(0){};

    ~Vector_A(){};

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
        for (int i=0; i<capacidad;i++){
            std::swap(array[i],array[i+1]);
        }

    };

    void pop_front(){
        if (capacidad>0) {
            capacidad--;
            if (capacidad < (size / 3) * 2 && cambiado > 0) { Diminusion_de_tam(); }
            for (int i=0;i<=capacidad;i++){
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
class Lista_enlazada{





};



#endif
