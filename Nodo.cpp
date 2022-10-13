//
// Created by jeanc on 15/09/2022.
//

#include "Nodo.h"

template<class T>
Nodo<T>::Nodo() {
    datos = nullptr;
    siguiente = nullptr;
}

template<class T>
T *Nodo<T>::getDatos() const {
    return datos;
}

template<class T>
void Nodo<T>::setDatos(T *datos) {
    Nodo::datos = datos;
}

template<class T>
Nodo<T> *Nodo<T>::getSiguiente() const {
    return siguiente;
}

template<class T>
void Nodo<T>::setSiguiente(Nodo *siguiente) {
    Nodo::siguiente = siguiente;
}