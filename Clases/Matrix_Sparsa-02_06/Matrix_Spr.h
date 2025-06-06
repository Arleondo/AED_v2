#ifndef MATRIX_SPARSA_02_06_MATRIX_SPR_H
#define MATRIX_SPARSA_02_06_MATRIX_SPR_H

#include <iostream>
#include <map>

struct node{
    int valor;
    int coord_x,coord_y;
    node* right, * down;

    explicit node(int valor,int c_x,int c_y,node* right=nullptr,node* down=nullptr):
    valor(valor),coord_x(c_x),coord_y(c_y),right(right),down(down){};
};

class Matrix_Sparsa{
    node** Columnas;
    int limitante;
public:

    Matrix_Sparsa(int x , int y):limitante(y){Columnas = new node*[x];};

};


class SparseMatrix {
private:
    int rows, cols;
    std::map<std::pair<int, int>, int> data;

public:
    SparseMatrix(int r, int c) : rows(r), cols(c) {}

    void set(int r, int c, int value) {
        if (r >= rows || c >= cols || r < 0 || c < 0) {
            std::cerr << "Índice fuera de rango.\n";
            return;
        }

        if (value != 0)
            data[{r, c}] = value;
        else
            data.erase({r, c}); // No almacenamos ceros
    }

    int get(int r, int c) const {
        if (r >= rows || c >= cols || r < 0 || c < 0) {
            std::cerr << "Índice fuera de rango.\n";
            return 0;
        }

        auto it = data.find({r, c});
        return (it != data.end()) ? it->second : 0;
    }

    void print() const {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                std::cout << get(i, j) << " ";
            }
            std::cout << "\n";
        }
    }

    void printNonZeroElements() const {
        std::cout << "Elementos no cero:\n";
        for (const auto& [pos, val] : data) {
            std::cout << "(" << pos.first << ", " << pos.second << ") = " << val << "\n";
        }
    }
};

#endif