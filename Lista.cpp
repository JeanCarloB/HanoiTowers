//
// Created by jeanc on 15/09/2022.
//

#include "Lista.h"

template<class T>
Lista<T>::Lista() {
    raiz = new Nodo<T>;
}

template<class T>
Lista<T>::~Lista() {
    Nodo<T> * temp;
    Nodo<T> * anterior;
    if (raiz->getSiguiente() == nullptr){
        delete raiz;
    } else {
        while (raiz->getSiguiente() != nullptr){
            temp = raiz;
            while (temp->getSiguiente() != nullptr){
                anterior = temp;
                temp = temp->getSiguiente();
            }
            anterior->setSiguiente(nullptr);
            delete temp;
        }
    }
}

template<class T>
string Lista<T>::toString() {
    stringstream ss;
    Nodo<T> *temporal = raiz;
    if (temporal->getSiguiente() == nullptr){
        ss << "      |     " << endl;
        ss << "      |     " << endl;
        ss << "      |     " << endl;
        ss << "      |     " << endl;
        ss << "-------------" << endl;
    } else {
        temporal = temporal->getSiguiente();
        do {
            ss << setw(9);
            ss << *temporal << endl;
            temporal = temporal->getSiguiente();
        } while (temporal != nullptr);
        ss << "-------------" << endl;
    }
    return ss.str();
}

template<class T>
T *Lista<T>::inicio() {
    Nodo<T> *temp = raiz;
    if (temp->getSiguiente() != nullptr){
        temp = temp->getSiguiente();
        return temp->getDatos();
    }
    return nullptr;
}

template<class T>
void Lista<T>::borrarInicio() {
    Nodo<T> *temp = raiz;
    if (temp->getSiguiente() != nullptr){
        temp = temp->getSiguiente();
        raiz->setSiguiente(temp->getSiguiente());
        delete temp;
    }
}

template<class T>
void Lista<T>::agregarInicio(T *p) {
    Nodo<T> *nuevo = new Nodo<T>;
    nuevo->setDatos(p);
    nuevo->setSiguiente(raiz->getSiguiente());
    raiz->setSiguiente(nuevo);
}