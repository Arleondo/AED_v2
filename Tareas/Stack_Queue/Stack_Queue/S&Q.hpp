#include <stdexcept>
#include <iostream>

template <class T>
class Stack_a {
    int size;
    T* top = 0;
    T* array;
public:
    explicit Stack_a(int size) :size(size), array(new T[size]) {};

    void push(T num) {
        if (top < array + size) {
            if (top == 0) {
                top = array;
                *top = num;
                return;
            }
            top++;
            *top = num;
        }
        else {
            throw std::out_of_range("Stack lleno");
        }
    }

    void pop() {
        if (top != 0) {
            *top = 0;
            top--;
        }
        else {
            throw ("Stack vacio");
        }
    }

    void Print() {
        std::cout << "[ ";
        for (T* Ptr_i = array; Ptr_i != array + size; Ptr_i++) {
            std::cout << *Ptr_i << " ";
        }
        std::cout << "]" << "\n";
    }
};

template <class T>
class Queue_a {
    int size;
    T* head = 0; T* tail = 0;
    T* array;
public:
    explicit Queue_a(int size) :size(size), array(new T[size]) {};

    void Push(T num) {
        if (head != 0) {
            if ((tail - head) != array+size) {
                head++;
                if (head == array + size && tail != array) {
                    head = array;
                }
                *head = num; return;
            }
            throw std::out_of_range("Queue lleno");
        }
        head = array; *head = num; tail = head;
    }

    void Pop() {
        if (tail != 0) {
            if (head - tail != array - 1) {
                *tail = -123456; //para verificar
                tail++;
                if (tail == array + size) {
                    tail = array;
                }
            }
            tail = 0; head = 0;
        }
        throw ("Queue vacio");
    }

    void Print() {
        std::cout << "[ ";
        for (T* Ptr_i = array; Ptr_i != array + size; Ptr_i++) {
            std::cout << *Ptr_i << " ";
        }
        std::cout << "]" << "\n";
    }
};
