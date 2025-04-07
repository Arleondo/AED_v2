#pragma once
#include <cstdlib>

void direct_bubblesort(int* p, long size) {
    for (long ite = 0; ite < size - 1; ++ite) {
        for (long jite = 0; jite < size - ite - 1; ++jite) {
            if (p[jite] < p[jite + 1]) {
                std::swap(p[jite], p[jite + 1]);
            }
        }
    }
}

struct Bubble_polimorfo {
    virtual void sort(int* p, long size) = 0;
    virtual ~Bubble_polimorfo() = default;
};

struct Bubble_mayor : public Bubble_polimorfo {
    void sort(int* p, long size) override {
        for (long ite = 0; ite < size - 1; ++ite) {
            for (long jite = 0; jite < size - ite - 1; ++jite) {
                if (p[jite] < p[jite + 1]) {
                    std::swap(p[jite], p[jite + 1]);
                }
            }
        }
    }
};
struct Bubble_menor : public Bubble_polimorfo {
    void sort(int* p, long size) override {
        for (long ite = 0; ite < size - 1; ++ite) {
            for (long jite = 0; jite < size - ite - 1; ++jite) {
                if (p[jite] > p[jite + 1]) {
                    std::swap(p[jite], p[jite + 1]);
                }
            }
        }
    }
};



template <class T, class Op>
class Bubble_funtor {
    inline Op comparador;
public:
    void operator()(T* p, long size) {
        for (long ite = 0; ite < size - 1; ++ite) {
            for (long jite = 0; jite < size - ite - 1; ++jite) {
                if (comparador(p[jite + 1], p[jite])) {
                    std::swap(p[jite], p[jite + 1]);
                }
            }
        }
    }
};

template <class T>
struct Cmenos {
    inline bool operator()(T a, T b) const { return a < b; }
};

template <class T>
struct Cmas {
    inline bool operator()(T a, T b) const { return a > b; }
};





bool puntero_menor(int a, int b) { return a < b; }

bool puntero_mayor(int a, int b) { return a > b; }

void bubblesort_componentes(int* p, long size, bool (*comp)(int, int)) {
    for (long ite = 0; ite < size - 1; ++ite) {
        for (long jite = 0; jite < size - ite - 1; ++jite) {
            if (comp(p[jite], p[jite + 1])) {
                std::swap(p[jite], p[jite + 1]);
            }
        }
    }
}
