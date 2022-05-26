//
// Created by liuvaneshka on 26/05/22.
//

#ifndef MENU_H
#define MENU_H

#include <iostream>


using namespace std;

//const string ARCHIVO_LECTURAS = "Lecturas.txt";
//const string ARCHIVO_ESCRITORES = "Autores.txt";


class Menu {

private:
    //Lista<Lectura*> lecturas;
    //Lista<Escritor*> Escritores;
    int opcion;

public:

    /* post: imprime el menu */
    void mostrar_menu();
    /* post: pide al usuario la opcion*/
    void elegir_opcion();
    /* post: dependiendo del caso cambia el estado*/
    bool selector_menu();

};


#endif