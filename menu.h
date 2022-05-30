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

    int opcion;
    Lista<Lectura*> lista_lecturas;
    Lista<Escritor*> lista_escritores;
    Cola* cola_lecturas;

    //Opcion 1
    void agregar_lectura();
    Lectura* crear_lectura();
    void almacenar_lectura(Lectura* lectura);
    int obtener_posicion_correcta(Lectura* lectura);

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
    void imprimir_lectura(Lectura* lectura);

    //Opcion 8
    void listar_lecturas_entre_anios();
    int pedir_anio_desde();
    int pedir_anio_hasta();

    //Opcion 9
    void listar_lecturas_de_escritor();
    //pedir_nombre_escritor(); Para listar las lecturas tambien se utiliza este método

    //Opcion 10
    void listar_novelas_de_genero();
    generos pedir_genero();

    //Opcion 11
    void proximas_lecturas();
    void cola_de_lecturas();
    void marcar_como_leida();

    //Opcion 12 -> salir() : se imprime el saludo desde selector_menu y se destruiría el objeto Menu ???
    void liberar_memoria();
    void liberar_listas();
    void liberar_escritores();
    void liberar_lecturas();
    void liberar_cola();

public:

    //PRE: recibe dos cadenas representando la ruta de los archivos
    //POST: construye el objeto
    Menu();

    //PRE:
    //POST: destruye el objeto
    ~Menu();

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
