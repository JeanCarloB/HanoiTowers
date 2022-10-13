//
// Created by jeanc on 15/09/2022.
//

#ifndef EXAMENI_NODO_H
#define EXAMENI_NODO_H

#include "Libreria.h"

template<class T>
class Nodo {
private:
    T *datos;
    Nodo *siguiente;
public:
    Nodo();

    T *getDatos() const;

    void setDatos(T *dato);

    Nodo *getSiguiente() const;

    void setSiguiente(Nodo *siguiente);

    friend ostream &operator<<(ostream &os, const Nodo<T> &nodo) {
        os << *nodo.datos;
        return os;
    }
};

#endif //EXAMENI_NODO_H
