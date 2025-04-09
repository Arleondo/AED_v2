#include <stdlib.h>

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
	Node* Root;
	int size;
public:
	L_stack(int size) :size(size), Root(nullptr){};

	void push(T valor) {
		if (Root) {
			if () {
			}
		}
		Root = new Node<T>(size); 
	}

	T& pop() {}

	void print() {}

};