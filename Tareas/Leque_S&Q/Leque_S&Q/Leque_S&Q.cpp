#include "Leques.hpp"
#include <iostream>

using namespace std;

int main() {
	
	LStack<int> stack(3);
	
	cout << "Testing LStack (Pila):\n";
	
	for (int i = 1; i <= 7; i++) {
		stack.push(i * 10);
		cout << "Pushed: " << i * 10 << "\n";
	}
	
	int val;
	
	for (int i = 0; i < 7; i++) {
		stack.pop(val);
		cout << "Popped: " << val << "\n";
	}

	cout << "\nTesting LQueue (Cola):\n";
	
	LQueue<int> queue(3);

	for (int i = 1; i <= 7; i++) {
		queue.push(i * 100);
		cout << "Ingreso: " << i * 100 << "\n";
	}
	for (int i = 0; i < 7; i++) {
		queue.pop(val);
		cout << "Salida: " << val << "\n";
	}

	return 0;
}

