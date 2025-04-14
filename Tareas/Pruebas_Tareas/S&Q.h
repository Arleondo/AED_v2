#ifndef PRUEBAS_TAREAS_S_Q_H
#define PRUEBAS_TAREAS_S_Q_H

#include <stdexcept>
#include <iostream>

template <class T>
class Stack_a {
    int size;
    T* top = 0;
    T* array;
public:
    explicit Stack_a(int size) :size(size), array(new T[size]), top(array) {};

    ~Stack_a() {
        delete[] array;
    }

    void push(T num) {
        if (top >= array+size-1) {
            throw std::out_of_range("Stack lleno");
        }
        *top = num; top++;
    }

    void pop(T& valor) {
        if (top < array) {
            throw std::underflow_error("Stack Vacio");
        }
        valor = *top; top--;
    }

    void Print() {
        std::cout << "[ ";
        for (T* Ptr_i = array; Ptr_i <= top; Ptr_i++) {
            std::cout << *Ptr_i << " ";
        }
        std::cout << "]\n";
    }
};


template <class T>
class Queue_a {
    int size;
    T* head = 0; T* tail = 0;
    T* array;
    int count = 0;
public:
    explicit Queue_a(int size) :size(size), array(new T[size]) {};

    ~Queue_a() {
        delete[] array;
    }

    void Push(T num) {
        if (count == size) {
            throw std::out_of_range("Queue lleno");
        }
        else if (head == nullptr) {
            head = tail = array;
            *head = num;
        }
        else {
            head++;
            if (head == array + size) {
                head = array;
            }
            *head = num;
        }
        count++;
    }

    void Pop(T& valor) {

        if (count == 0) {
            if (tail == nullptr) {
                throw std::underflow_error("Queue vacio"); valor = 0;
                return;
            }
            head = tail = nullptr; return;
        }

        valor = *tail;
        tail++;

        if (tail == array + size) {
            tail = array;
        }
        count--;
    }

    void Print() {
        std::cout << "[ ";
        for (T* Ptr_i = array; Ptr_i != array + size; Ptr_i++) {
            std::cout << *Ptr_i << " ";
        }
        std::cout << "]" << "\n";
    }
};


#endif
