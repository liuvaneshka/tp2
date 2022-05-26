//
// Created by liuvaneshka on 26/05/22.
//
#include <iostream>
#include "menu.h"

using namespace std;


void Menu::mostrar_menu(){

    string listado [] = {"Agregar una nueva lectura","Quitar lectura","Agregar un escritor", "Actualizar fallecimiento autor", "Listar los escritores" , "Sortear una lectura" , "Listar lecturas", "Listar lecturas por anio", "Listar lecturas por escritor", "Listar Novelas por genero", "Listar proximas lecturas", "Salir"};
    int size = sizeof(listado)/sizeof(listado[0]);

    for(int i = 0; i < size; i++){
        cout << i+1 << ". " << listado[i]  << endl;
    }
}

void Menu::elegir_opcion() {
    string op;
    cout << "\n\tIngresar opcion: " << endl;
    cin >> op;
    this->opcion = atoi(op.c_str());
}

bool Menu::selector_menu(){

    bool estado;

    switch (this->opcion) {

        case 1:
            cout << "metodo 1 " /*<<tarjeta.obtenerSaldo() */<< endl;
            estado = true;
            break;

        case 2:
            cout << "caso 2" << endl;
            estado = true;
            break;

        case 3:
            cout << "caso 3" << endl;
            estado = true;
            break;

        case 4:
            cout << "caso 4" << endl;
            estado = true;
            break;

        case 5:
            cout << "caso 5" << endl;
            estado = true;
            break;

        case 6:
            cout << "caso 6" << endl;
            estado = true;
            break;

        case 7:
            cout << "caso 7" << endl;
            estado = true;
            break;

        case 8:
            cout << "caso 8" << endl;
            estado = true;
            break;

        case 9:
            cout << "caso 9" << endl;
            estado = true;
            break;

        case 10:
            cout << "caso 10" << endl;
            estado = true;
            break;

        case 11:
            cout << "caso 11" << endl;
            estado = true;
            break;

        case 12:
            cout << "\n\t\t\tCordial despedida" << endl;
            estado = false;
            break;

        default:
            cout << "\n\t\t\terror elige otra opcion valida" << endl;
            estado = true;

    }
    return estado;
}