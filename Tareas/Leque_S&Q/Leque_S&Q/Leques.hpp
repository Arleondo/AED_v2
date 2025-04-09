#include <stdlib.h>
#include <iostream>

template <class T>
struct Node {
	T* array;	T* head;
	Node* next;
	int size;
	Node(int size, Node<T>* next = nullptr) : size(size), array(T[size]), head(array), next(next) {};
};

template <class T>
struct Node_q :public Node<T> {
	T* tail;
	Node_q(int size, Node<T>* next = nullptr) : Node<T>(size, next), tail(this->head) {};
};


template <class T>
class L_stack {
	Node<T>* Root;
	int size;
public:
	L_stack(int size) :size(size), Root(nullptr){};

	void push(T valor) {
		if (Root) {
			
			Node<T>* Last=Root;
			
			//recorre hasta el ultimo
			for (; Last->next; Last = Last->next);	Last->head++;
			
			//Compara si necesita crear
			if (Last->head == (Last->array) + size) {
				Last->head--; Last->next = new Node<T>(size); 
				Last = Last->next;
			}

			* Last->head = valor;

		}
		Root = new Node<T>(size); *Root->head = valor;
	}

	T& pop() {
		T regreso;

		if (Root) {

			Node<T>* Last = Root;

			for (; Last->next; Last = Last->next);

			regreso = *Last->head;
			
			if (Last->head == Last->array) {
				delete[] * Last;
				*Last = nullptr;
			}
			
			Last->head--;
		
		}

		std::cout << "L_stack vacio papu";
	
	}

	void print() {}

};

