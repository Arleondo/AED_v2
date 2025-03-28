#include <stdexcept>

template <class T>
class Stack_a {
	int size;
	T* top = 0;
	T* array = new T[size];
public:
	Stack_a(int size) :size(size) {};

	void push(T num) {
		if (top < array + size) {
			if (top = 0) {
				top = array;
				*top = num;
				return;
			}
			top++;
			*top = num;
		}
		else {
			throw std::out_of_range("Stack lleno")
		}
	}

	void pop() {
		if (top != 0) {
			*top = 0;
			top--;
		}
		else {
			throw ("Stack vacio")
		}
	}
};

template <class T>
class Queue_a {
	int size; 
	T* head = 0; T* tail = 0;
	T* array = new T[size];
public:
	Queue_a(int size) :size(size){};
	
	void Push(T num){
		if (head-1<tail||)
		
	}

	void Pop(){
		
		
	}
};



