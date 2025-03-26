#ifndef FUNTION_OBJECT_24_03_SORT_H
#define FUNTION_OBJECT_24_03_SORT_H
#include <cstdlib>
template<class C>
void sort(int*p, long size, C c){
    for(int * pos=p; pos < p+int(size); pos++){
        int *cambio= pos;
        for (int * ptrcambio = pos; ptrcambio < p + int(size); ptrcambio++){
            if (c.cmp(*ptrcambio,*cambio)){
                cambio = ptrcambio;
            }
        }
        std::swap(*cambio,*pos);
    }
}

template <class T>
struct Cmenos{
   inline bool cmp(T a, T b){ return a<b; }
};

template <class T>
struct Cmas{
    inline bool cmp(T a, T b){ return a<b; }
};


#endif //FUNTION_OBJECT_24_03_SORT_H
