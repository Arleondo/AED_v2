#ifndef DEQUE_08_04_DEQUE_H
#define DEQUE_08_04_DEQUE_H

template<class T>
class Deque{
    T** Mapa;
    T* Ini_m,* Fin_m;
    T* Ini_arr,*Fin_arr;
    int tam_mapa,tam_array;

    void Expandir_mapa(){};

public:

    explicit Deque(int Mapsize,int Arraysize):tam_array(Arraysize),tam_mapa(Mapsize){Mapa=new T*[Mapsize];};

    ~Deque(){
        T** i=Mapa;
        for (;i<Mapa+tam_mapa;i++){
            delete[] *i;
        }
        delete[] i;
    };

    void push_back(){};

    void pop_back(){};

    void push_front(){};

    void pop_front(){};












};

#endif
