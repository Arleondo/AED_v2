#include "S&Q.hpp"

using namespace std;


int main() {

    Stack_a<int> stack(10);
    
    for (int i = 10; i > 0; i) {
        stack.push(i);
    }
    stack.Print();
}
    
