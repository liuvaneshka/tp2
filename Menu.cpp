//
// Created by liuvaneshka on 17/05/22.
//
#include <iostream>
#include "Menu.h"

using namespace std;

Menu::Menu(int _opcion){
    this->opcion = _opcion;
}

Menu :: ~Menu()= default;

int Menu:: obtener_opcion() const {
    return opcion;
}

void Menu:: mostrar_opciones() {
    string listado [] = {"Agregar una nueva lectura","Quitar lectura"," Agregar un escritor", "Actualizar fallecimiento autor", " Listar los escritores" , " Sortear una lectura" , " Listar lecturas", " Listar lecturas por anio", " Listar lecturas por escrior", " Listar Novelas por genero", " Listar proximas lecturas", " Salir"};
    int size = sizeof(listado)/sizeof(listado[0]);

    for(int i = 0; i < size; i++){
        cout << i+1 << ". " << listado[i]  << endl;
    }
}

void Menu:: elegir_opcion() {
    int strPos;
    cout << "\n\tIngrese la opcion que desea: " << endl;
    cin >> strPos;
    cout << "\n";
    opcion = int(strPos);
}
