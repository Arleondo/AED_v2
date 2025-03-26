#pragma once
#include <cstdlib>

void direct_bubblesort(int* p , long size) {
    for (int* pos = p; pos < p + int(size); pos++) {
        int* cambio = pos;
        for (int* ptrcambio = pos; ptrcambio < p + int(size); ptrcambio++) {
            if (*ptrcambio<*cambio) {
                cambio = ptrcambio;
            }
        }
        std::swap(*cambio, *pos);
    }
}

struct Bubble_polimorfo {
    virtual void sort(int* p , long size) = 0;
};

struct Bubble_mayor:public Bubble_polimorfo {
    void sort(int* p, long size) override {
        for (int* pos = p; pos < p + int(size); pos++) {
            int* cambio = pos;
            for (int* ptrcambio = pos; ptrcambio < p + int(size); ptrcambio++) {
                if (*ptrcambio < *cambio) {
                    cambio = ptrcambio;
                }
            }
            std::swap(*cambio, *pos);
        }
    }
};
struct Bubble_menor:public Bubble_polimorfo {
    void sort(int* p, long size) override {
        for (int* pos = p; pos < p + int(size); pos++) {
            int* cambio = pos;
            for (int* ptrcambio = pos; ptrcambio < p + int(size); ptrcambio++) {
                if (*ptrcambio > *cambio) {
                    cambio = ptrcambio;
                }
            }
            std::swap(*cambio, *pos);
        }
    }
};

template <class T,class B>
class Bubble_funtor {
    B comparador;
public:
    Bubble_funtor(B comparator):comparador(comparator);
    void operator() (T * p, long size) {
        for (int* pos = p; pos < p + int(size); pos++) {
            int* cambio = pos;
            for (int* ptrcambio = pos; ptrcambio < p + int(size); ptrcambio++) {
                if (comparador(*ptrcambio, *cambio)) {
                    cambio = ptrcambio;
                }
            }
            std::swap(*cambio, *pos);
        }
    }
};

template<class C>
void bubblesort_componentes(int* p, long size, C c) {
    for (int* pos = p; pos < p + int(size); pos++) {
        int* cambio = pos;
        for (int* ptrcambio = pos; ptrcambio < p + int(size); ptrcambio++) {
            if (c.cmp(*ptrcambio, *cambio)) {
                cambio = ptrcambio;
            }
        }
        std::swap(*cambio, *pos);
    }
}
template <class T>
struct Cmenos {
    inline bool cmp(T a, T b) { return a < b; }
};
template <class T>
struct Cmas {
    inline bool cmp(T a, T b) { return a < b; }
};
