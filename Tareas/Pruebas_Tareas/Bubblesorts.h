#ifndef PRUEBAS_TAREAS_BUBBLESORTS_H
#define PRUEBAS_TAREAS_BUBBLESORTS_H

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

template <class T>
class Bubble_funtor {
public:
    void operator()(T* p, long size) {
        for (long i = 0; i < size - 1; ++i) {
            for (long j = 0; j < size - i - 1; ++j) {
                if (p[j] > p[j + 1]) {
                    std::swap(p[j], p[j + 1]);
                }
            }
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

struct Cmenos {
    static inline bool cmp(int a, int b) { return a < b; }
};
template <class T>
struct Cmas {
    static inline bool cmp(T a, T b) { return a < b; }
};



#endif
