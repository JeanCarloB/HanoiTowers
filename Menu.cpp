//
// Created by jeanc on 15/09/2022.
//

#include "Menu.h"

Menu::Menu() {
    this->torre1 = new PilaLista<int>;
    this->torre2 = new PilaLista<int>;
    this->torre3 = new PilaLista<int>;
}

Menu::~Menu() {

}

void Menu::menuPrincipal() {
    int opcion=0;
    do {
        cout << "=========== Bienvenido al menu de las Torres de Hanoi ==========="  << endl;
        cout << "1.Ingresar al juego"                                         << endl;
        cout << "2.Mostrar el minimo numero de intentos para ganar"        << endl;
        cout << "3.Mostrar el algoritmo completo paso a paso de la solucion"  << endl;
        cout << "4.Salir"                                                     << endl;
        cout << "\n";
        cout << "Digite una opcion del menu: ";
        cin >> opcion;
        if(cin.fail()){
            cin.clear();
            cin.ignore(1024,'\n');
            cout<<"Digite solamente dato numerico"<<endl;
            Sleep(2000);
            this->menuPrincipal();
        }
        if(opcion<1||opcion>4){
            cout<<"Digite solamente dato numerico"<<endl;
            Sleep(2000);
            this->menuPrincipal();
        }
        switch (opcion) {
            case 1:
                ingresarJuego();
                break;
            case 2:
                minNumeroMov();
                break;
            case 3:
                mostrarPasoAPaso();
                break;
            case 4:
                cout << "Gracias por utilizar la aplicacion :)"<<endl;
                Sleep(2000);
                exit(0);
                break;
        }
    } while (opcion != 4);
}

void Menu::ingresarJuego() {
    int opcion=0;

    int numeroDiscos=4;

    int intentos=this->calcularPasosMin(numeroDiscos);

    int* disco1=new int(this->calcularN(0));
    int* disco2=new int(this->calcularN(1));
    int* disco3=new int(this->calcularN(2));
    int* disco4=new int(this->calcularN(3));

    int* temp=new int(0);

    torre1->push(disco4);
    torre1->push(disco3);
    torre1->push(disco2);
    torre1->push(disco1);

    while (torre3->size() != 4 || intentos == 0) {
        try {
            do {

                cout << torre1->toString() << endl;
                cout << torre2->toString() << endl;
                cout << torre3->toString() << endl;

                if (intentos < 0) {
                    cout << "Ha gastado todos sus intentos!!" << endl;
                    Sleep(2000);
                    menuPrincipal();
                }
                if (torre3->size() == 4) {
                    cout << "Juego completado con exito!!" << endl;
                    Sleep(2000);
                    menuPrincipal();
                }


                //cout << *torre3->top() << endl;

                cout << "intentos restantes: " << intentos << endl;

                cout << "=========== Torres de Hanoi ===========" << endl;
                cout << "Que movimiento quiere realizar?" << endl;
                cout << "1.De la pila 1 a la pila 2" << endl;
                cout << "2.De la pila 1 a la pila 3" << endl;
                cout << "3.De la pila 2 a la pila 1" << endl;
                cout << "4.De la pila 2 a la pila 3" << endl;
                cout << "5.De la pila 3 a la pila 1" << endl;
                cout << "6.De la pila 3 a la pila 2" << endl;
                cout << "7.Reiniciar el juego" << endl;
                cout << "8.Salir" << endl;
                cout << "\n";
                cout << "Digite una opcion del menu: ";


                cin >> opcion;
                cout << endl;
                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(1024, '\n');
                    cout << "Digite solamente dato numerico" << endl;
                    Sleep(2000);
                    this->menuPrincipal();
                }
                if (opcion < 1 || opcion > 8) {
                    cout << "Digite solamente dato numerico" << endl;
                    Sleep(2000);
                    this->menuPrincipal();
                }
                switch (opcion) {
                    case 1:
                        if(!torre1->empty()){//Si la torre 1 NO esta vacia
                            temp = torre1->top();//Puedo tomar valor top

                            if(torre2->empty()){//En caso que la torre 2 este vacia, inserto sin preocupacion
                                    torre1->pop();
                                    torre2->push(temp);
                                    intentos--;
                            }else{//Si no
                                if(torre2->top()>temp){//Debo fijarme si el elemento primero es mayor o menor
                                    torre1->pop();
                                    torre2->push(temp);
                                    intentos--;
                                }else{
                                    cout<<"Movimiento no permitido"<<endl;
                                }
                            }
                        }
                        break;
                    case 2:
                        if(!torre1->empty()){//Si la torre 1 NO esta vacia
                            temp = torre1->top();//Puedo tomar valor top

                            if(torre3->empty()){//En caso que la torre 3 este vacia, inserto sin preocupacion
                                torre1->pop();
                                torre3->push(temp);
                                intentos--;
                            }else{//Si no
                                if(torre3->top()>temp){//Debo fijarme si el elemento primero es mayor o menor
                                    torre1->pop();
                                    torre3->push(temp);
                                    intentos--;
                                }else{
                                    cout<<"Movimiento no permitido"<<endl;
                                }
                            }
                        }
                        break;
                    case 3:
                        if(!torre2->empty()){//Si la torre 2 NO esta vacia
                            temp = torre2->top();//Puedo tomar valor top

                            if(torre1->empty()){//En caso que la torre 1 este vacia, inserto sin preocupacion
                                torre2->pop();
                                torre1->push(temp);
                                intentos--;
                            }else{//Si no
                                if(torre1->top()>temp){//Debo fijarme si el elemento primero es mayor o menor
                                    torre2->pop();
                                    torre1->push(temp);
                                    intentos--;
                                }else{
                                    cout<<"Movimiento no permitido"<<endl;
                                }
                            }
                        }
                        break;
                    case 4:
                        if(!torre2->empty()){//Si la torre 2 NO esta vacia
                            temp = torre2->top();//Puedo tomar valor top

                            if(torre3->empty()){//En caso que la torre 3 este vacia, inserto sin preocupacion
                                torre2->pop();
                                torre3->push(temp);
                                intentos--;
                            }else{//Si no
                                if(torre3->top()>temp){//Debo fijarme si el elemento primero es mayor o menor
                                    torre2->pop();
                                    torre3->push(temp);
                                    intentos--;
                                }else{
                                    cout<<"Movimiento no permitido"<<endl;
                                }
                            }
                        }
                        break;
                    case 5:
                        if(!torre3->empty()){//Si la torre 3 NO esta vacia
                            temp = torre3->top();//Puedo tomar valor top

                            if(torre1->empty()){//En caso que la torre 1 este vacia, inserto sin preocupacion
                                torre3->pop();
                                torre1->push(temp);
                                intentos--;
                            }else{//Si no
                                if(torre1->top()>temp){//Debo fijarme si el elemento primero es mayor o menor
                                    torre3->pop();
                                    torre1->push(temp);
                                    intentos--;
                                }else{
                                    cout<<"Movimiento no permitido"<<endl;
                                }
                            }
                        }
                        break;
                    case 6:
                        if(!torre3->empty()){//Si la torre 3 NO esta vacia
                            temp = torre3->top();//Puedo tomar valor top

                            if(torre2->empty()){//En caso que la torre 2 este vacia, inserto sin preocupacion
                                torre3->pop();
                                torre2->push(temp);
                                intentos--;
                            }else{//Si no
                                if(torre2->top()>temp){//Debo fijarme si el elemento primero es mayor o menor
                                    torre3->pop();
                                    torre2->push(temp);
                                    intentos--;
                                }else{
                                    cout<<"Movimiento no permitido"<<endl;
                                }
                            }
                        }
                        break;
                    case 7:
                        cout<<"Reiniciando Juego...Por favor espere"<<endl;
                        Sleep(2000);
                        this->reinicio(torre1);
                        this->reinicio(torre2);
                        this->reinicio(torre3);
                        this->torre1->push(disco4);
                        this->torre1->push(disco3);
                        this->torre1->push(disco2);
                        this->torre1->push(disco1);
                        intentos= calcularPasosMin(numeroDiscos);
                        break;
                    case 8:
                        cout << "Saliendo..." << endl;
                        this->reinicio(torre1);
                        this->reinicio(torre2);
                        this->reinicio(torre3);
                        intentos= calcularPasosMin(numeroDiscos);
                        Sleep(2000);
                        this->menuPrincipal();
                        break;
                }

            } while (opcion != 8);
        }catch(RuntimeException e){
            cout<<e.getMessage()<<endl;
        }
    }
    cout << "Juego Terminado" << endl;
    this->reinicio(torre1);
    this->reinicio(torre2);
    this->reinicio(torre3);
    intentos= calcularPasosMin(numeroDiscos);
    menuPrincipal();

}

int Menu::calcularN(int h) {
    return (h+4)*pow(h+9,h+1);
}

int Menu::calcularPasosMin(int n) {
    return pow(2,n)-1;
}

void Menu::mostrarPasoAPaso() {
    string password="";
    int cantidadDiscos=0;

    cout << "Ingrese la contrasena secreta para ver la solucion paso a paso" << endl;
    cin >> password;

    if (password == "123"){
        cout << "Para que cantidad de discos desea ver la solucion?" << endl;
        cin >> cantidadDiscos;

        realizarPasoAPaso(cantidadDiscos, 1, 2, 3);
    } else {
        cout << "La contrasena que ha ingresado es incorrecta. Volviendo al menu principal" << endl << endl;
    }
}

void Menu::realizarPasoAPaso(int discos, int t1, int t2, int t3) {
    if(discos==1){
        cout << "Mueva el disco superior de la torre " << t1 << " a la torre " << t3 << endl;
    }else{
        realizarPasoAPaso(discos-1,t1,t3,t2);
        cout << "Mueva el disco superior de la torre " << t1 << " a la torre " << t3 << endl;
        realizarPasoAPaso(discos-1,t2,t1,t3);
    }
}

void Menu::minNumeroMov() {
    int discos;

    cout << "Para que cantidad de discos desea ver el minimo de pasos necesarios?" << endl;
    cin >> discos;

    cout << "El minimo numero de pasos necesarios para completar el juego con " << discos << " discos es: " << calcularPasosMin(discos) << endl;
}

bool Menu::compara(int* n1,int* n2){
    return *n1>*n2;
}

void Menu::reinicio(PilaLista<int>* ptr) {
    if(!ptr->empty()){
        ptr->pop();
    }
    if(!ptr->empty()){
        ptr->pop();
    }
    if(!ptr->empty()){
        ptr->pop();
    }
    if(!ptr->empty()){
        ptr->pop();
    }
}