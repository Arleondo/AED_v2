#include <iostream>
#include <vector>
using namespace std;

bool isPalindrome(int x) {
    int palin=x;
    int temp;
    while(palin){
        temp = temp*10;
        temp = temp + palin%10;
        palin = int(palin/10);
    }
    if (temp == x) return true;

    return false;
}

int main() {
    int x = -121;
    cout << isPalindrome(x);

}
