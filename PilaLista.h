//
// Created by jeanc on 15/09/2022.
//

#ifndef EXAMENI_PILALISTA_H
#define EXAMENI_PILALISTA_H

#include "Lista.cpp"
#include "RuntimeException.h"

template<class T>
class PilaLista {

private:
    Lista<T> *s;
    int n;

public:
    PilaLista();
    ~PilaLista();
    int size();
    bool empty() const;
    T* top() throw(StackEmpty);
    void push(T* e);
    void pop() throw(StackEmpty);
    string toString();
};

#endif //EXAMENI_PILALISTA_H
