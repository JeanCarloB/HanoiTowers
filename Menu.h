//
// Created by jeanc on 15/09/2022.
//

#ifndef EXAMENI_MENU_H
#define EXAMENI_MENU_H

#include "PilaLista.cpp"

class Menu {
private:
    PilaLista<int> *torre1;
    PilaLista<int> *torre2;
    PilaLista<int> *torre3;
public:
    Menu();
    virtual ~Menu();
    void menuPrincipal();
    void ingresarJuego();
    void minNumeroMov();
    void mostrarPasoAPaso();
    int calcularPasosMin(int);
    void realizarPasoAPaso(int, int, int, int);
    int calcularN(int);
    bool compara(int*,int*);

    void reinicio(PilaLista<int> *);
};

#endif //EXAMENI_MENU_H
