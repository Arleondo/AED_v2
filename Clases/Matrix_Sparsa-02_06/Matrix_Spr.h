#ifndef MATRIX_SPARSA_02_06_MATRIX_SPR_H
#define MATRIX_SPARSA_02_06_MATRIX_SPR_H

#include <iostream>

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


#endif