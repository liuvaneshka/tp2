#ifndef MENU_H
#define MENU_H
#include <iostream>
#include "escritor.h"
#include "lectura.h"
#include "lista.h"
#include "CONSTANTES.h"
//Clases principales
#include "novela.h"
#include "novela_historica.h"
#include "cuento.h"
#include "poema.h"
// Para la opcion de sortear una lectura
#include <stdlib.h>
#include <time.h>
// Para la cola de lecturas
#include "cola.h"

using namespace std;

class Menu {

private:
    Lista<Lectura*> lista_lecturas;
    Lista<Escritor*> lista_escritores;
    int opcion;

    //Opcion 1
    void agregar_lectura();
    Lectura* crear_lectura();
    void almacenar_lectura(Lectura* lectura);
    generos obtener_genero(string genero);

    //Opcion2
    void quitar_lectura();
    string pedir_nombre_lectura();
    int rastrear_lectura(string titutlo_lectura);

    //Opcion 3
    void agregar_escritor();
    Escritor* crear_escritor();
    void almacenar_escritor(Escritor* escritor);

    //Opcion 4
    void modificar_fallecimiento();
    string pedir_nombre_escritor();
    Escritor* rastrear_escritor();
    int pedir_nuevo_fallecimiento();

    //Opcion 5
    void listar_escritores();

    //Opcion 6
    void sortear_lectura();

    //Opcion 7
    void listar_lecturas();
    void imprimir_lectura(int indice);

    //Opcion 8
    void listar_lecturas_entre_anios();
    int* pedir_anios();

    //Opcion 9
    void listar_lecturas_de_escritor();
    //pedir_nombre_escritor(); Para listar las lecturas tambien se utiliza este método

    //Opcion 10
    void listar_novelas_de_genero();
    generos pedir_genero();

    //Opcion 11
    void cola_de_lecturas();

    //Opcion 12 -> salir() : se imprime el saludo desde selector_menu y se destruiría el objeto Menu ???

public:

    //PRE:
    //POST: imprime el menu.
    void mostrar_menu();

    //PRE:
    //POST: pide al usuario la opcion
    void elegir_opcion();

    //PRE:
    //POST: dependiendo del caso cambia el estado
    bool selector_menu();

};


#endif
