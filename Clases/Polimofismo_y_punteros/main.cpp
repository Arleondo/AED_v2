#include <iostream>

using namespace std;

struct Comparador{
    virtual bool cmp(long a,long b)=0;
};

struct Compless:public Comparador{
    bool cmp (long a,long b) override{
        return a<b;
    };
};

struct Compgreater:public  Comparador{
    bool cmp (long a, long b) override{
      return b>a;
    };
};

int main() {

    Compless menor;
    Compgreater mayor; bool b=mayor.cmp(3,4);
    cout << b << "\n";
    Comparador* Sptr=&menor;
    b = Sptr->cmp(7,2);
    cout << b << "\n";



    return 0;
}
