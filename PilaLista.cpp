//
// Created by jeanc on 15/09/2022.
//

#include "PilaLista.h"

template<class T>
PilaLista<T>::PilaLista() : s(new Lista<T>), n(0) {
}

template<class T>
PilaLista<T>::~PilaLista() {
    delete s;
}

template<class T>
int PilaLista<T>::size() {
    return n;
}

template<class T>
bool PilaLista<T>::empty() const {
    return n == 0;
}

template<class T>
T *PilaLista<T>::top() throw(StackEmpty) {
    if (empty())
        throw StackEmpty("Top sobre un stack vacio!");
    return s->inicio();
}

template<class T>
void PilaLista<T>::push(T *e) {
    ++n;
    s->agregarInicio(e);
}

template<class T>
void PilaLista<T>::pop() throw(StackEmpty) {
    if (empty())
        throw StackEmpty("Pop sobre un stack vacio!");
    s->borrarInicio();
    n--;
}

template<class T>
string PilaLista<T>::toString() {
    return s->toString();
}