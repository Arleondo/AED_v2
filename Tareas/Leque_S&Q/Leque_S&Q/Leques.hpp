#include <stdlib.h>
#include <iostream>

template <class T>
struct Node {
	T* array;	T* head;
	Node* next;
	int size;
	Node(int size, Node<T>* next = nullptr) : size(size), next(next) {
		array = new T[size];
		head = array;
	}

	~Node() {
		delete[] array;
	}
};

template <class T>
struct Node_q : public Node<T> {
	T* tail;
	Node_q(int size, Node<T>* next = nullptr) : Node<T>(size, next) {
		tail = this->head;
	}
};

template <class T>
class LStack {
private:
	Node<T>* L_head; T* A_head;
	int array_size;

public:
	LStack(int array_size) : array_size(array_size),L_head,A_head(nullptr){}

	void push(T v) {
		if (L_head == nullptr && A_head == nullptr) {
			L_head = new Node<T>(array_size);
			A_head = L_head->array; *A_head = v;
		}
		else if (A_head == L_head->array + array_size - 1) {
			Node<T>* newnode = new Node<T>(array_size);
			newnode->next = L_head; L_head = newnode;
			A_head = L_head->array; *A_head = v;
		}
		else { A_head++; *A_head = v;}
	}

	void pop(T& v) {
		if (L_head == nullptr && A_head == nullptr) {
			v = 987654; return;
		}
		else if (A_head == L_head->array) {
			v = *A_head; Node<T>* temp = L_head;
			L_head = L_head->next; delete temp;

			if (L_head == nullptr) {A_head = nullptr;}

			else {A_head = L_head->array + array_size - 1};
		}
		else{v = *A_head; A_head--;}
	}
};

template <class T>
class LQueue {
private:
	Node<T>* L_Head; Node<T>* L_tail;
	T* A_Head; T* A_tail;
	int array_size;

public:

	LQueue(int array_size) : array_size(array_size),L_Head,L_tail,A_Head,A_tail(nullptr) {}

	void push(T V) {
		if (L_Head == nullptr && L_tail == nullptr) {
			Node<T>* newnode = new Node<T>(array_size);
			L_Head = newnode; L_tail = newnode;
			A_Head = L_Head->array; A_tail = L_Head->array;
			*A_tail = V;
		}
		else if (A_tail == L_tail->array + array_size - 1) {
			Node<T>* newnode = new Node<T>(array_size);
			L_tail->next = newnode;
			L_tail = L_tail->next; A_tail = L_tail->array;
			*A_tail = V;
		}
		else {
			A_tail++; *A_tail = V;
		}
	}

	void pop(T& v) {
		if (L_Head == nullptr && L_tail == nullptr) {
			v = 987654; return;
		}
		else if (A_Head == L_Head->array + array_size - 1 || (L_Head == L_tail && A_Head == A_tail)) {
			
			v = *A_Head; Node<T>* temp = L_Head;

			if (L_Head->next == nullptr) {
				L_Head = nullptr; L_tail = nullptr;
				A_Head = nullptr; A_tail = nullptr;
			}
			else {
				L_Head = L_Head->next;
				A_Head = L_Head->array;
			}

			delete temp;

		}
		else {
			v = *A_Head;
			A_Head++;
		}
	}
};
