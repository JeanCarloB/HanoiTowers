//
// Created by jeanc on 15/09/2022.
//

#ifndef EXAMENI_LISTA_H
#define EXAMENI_LISTA_H

#include "Nodo.cpp"

template<class T>
class Lista {
private:
    Nodo<T> *raiz;
public:
    Lista();
    ~Lista();
    string toString();
    T *inicio();
    void borrarInicio();
    void agregarInicio(T *);
};


#endif //EXAMENI_LISTA_H
