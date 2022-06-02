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
    Lista<Lectura*>* lista_lecturas;
    Lista<Escritor*>* lista_escritores;
    Cola<Lectura*>* cola_lecturas;

    //!Opcion 1
    //PRE: La lista_lecturas debe estar bien definida.
    //POST: Crea y almacena en lista_lecturas la lectura con los atributos ingresados por el usuario.
    void agregar_lectura();

    //PRE: La lista_lecturas debe estar bien definida.
    //POST: Pide al usuario los atributos necesarios y crea el objeto correspondiente (Poema, Cuento, Novela, Novela_historica)
    Lectura* crear_lectura();

    //PRE: La lista_lecturas debe estar bien definida y lectura debe ser un objeto válido.
    //POST: Almacena a la lectura en lista_lecturas según el año de publicacion, de manera creciente.
    void almacenar_lectura(Lectura* lectura);

    //PRE: lecura debe ser un objeto válido.
    /*POST: Devuelve el indice de la lista_lecturas donde se debe almacenar
            la lectura para mantener la lista en orden por año de publicacion. */
    int obtener_posicion_segun_anio(Lectura* lectura);

    //!Opcion2
    //PRE: La lista_lecturas debe estar bien definida.
    /*POST: Quita de lista_lecturas la lectura ingresada por el usuario.
            De no existir, se lo comunica al usuario. */
    void quitar_lectura();

    //PRE: -
    //POST: Devuelve el nombre de la lectura ingresado por el usuario.
    string pedir_nombre_lectura();

    //PRE: La lista_lecturas debe estar bien definida.
    //POST: Obtiene el indice donde se encuentra la lectura cuyo nombre coincide con el que ingresó el usuario.
    int rastrear_lectura(string titulo_lectura);

    //PRE:
    //POST:
    void actualizar_cola(Lectura* lectura_nueva);

    //!Opcion 3
    //PRE: La lista_escritores debe estar ben definida.
    //POST: Crea y almacena en lista_escritores el escritor con los atributos ingresados por el usuario.
    void agregar_escritor();

    //PRE: La lista_escritores debe estar ben definida.
    //POST: Pide al usuario los atributos necesarios y crea al Escritor.
    Escritor* crear_escritor();

    //PRE: La lista_escritores debe estar bien definida y escritor debe ser un objeto válido.
    //POST: Almacena al escritor en la lista_escritores, en la posicion final.
    void almacenar_escritor(Escritor* escritor);

    //!Opcion 4
    //PRE: La lista_escritores debe estar bien definida.
    //POST: Modifica el atributos anio_dfallecimiento del Escritor ingresado por el usuario.
    void modificar_fallecimiento();

    //PRE: LLa lista_escritores debe estar bien definida.
    //POST: Pide al usuario el nombre del Escritor.
    string pedir_nombre_escritor();

    //PRE: La lista_escritores debe estar bien definida.
    /*POST: Obtiene el escritor cutyo nombre coincide con el nombre_escritor, ingresado por el usuario.
            De no existir, se lo comunica al usuario */
    Escritor* rastrear_escritor(string nombre_escritor);

    //PRE: -
    //POST: Devuelve el nuevo año de fallecimiento, ingresado por el usuario.
    int pedir_nuevo_fallecimiento();

    //!Opcion 5
    //PRE: La lista_escritores debe estar bien definida.
    //POST: Imprime uno por uno los Escritores de la lista_escritores.
    void listar_escritores();

    //!Opcion 6
    //PRE: La lista_lecturas debe estar bien definida.
    //POST: Imprime una Lectura de la lista_lecturas elegida aleatoriamente.
    void sortear_lectura();

    //!Opcion 7
    //PRE: La lista_lecturas debe estar bien definida.
    //POST: Imprime uno por uno las Lecturas de la lista_lecturas.
    void listar_lecturas();

    //!Opcion 8
    //PRE: La lista_lecturas debe estar bien definida.
    //POST: Lista las lecturas entre dos años ingresados por el usuario.
    void listar_lecturas_entre_anios();

    //PRE: -
    //POST: Devuelve el año desde el cual el usuario desea listar las lecturas.
    int pedir_anio_desde();

    //PRE: -
    //POST: Devuelve el año hasta el cual el usuario desea listar las lecturas.
    int pedir_anio_hasta();

    //!Opcion 9
    //PRE: La lista_lecturas debe estar bien definida.
    //POST: Lista las lecturas que pertenezcan al escritor ingresado por el usuario.
    void listar_por_escritor();

    //PRE: La lista_lecturas debe estar bien definida.
    /*POST: Devuelve true si existen lecturas del escritor ingresado por el usuario y las imprime.
            En caso contrario, devuelve false*/
    bool hay_lecturas_de_escritor(string nombre_escritor);

    //!Opcion 10
    //PRE: La lista_lecturas debe estar bien definida.
    //POST: Imprime las novelas del género ingresado por el usuario.
    void listar_novelas_de_genero();

    //PRE: -
    //POST: Pide al usuario que ingrese el género de la Lectura.
    generos pedir_genero();

    //!Opcion 11
    //PRE: La lista_lecturas y la cola_lecturas deben estar bien definidas.
    //POST: Crea una cola de lecturas y perite leer la del frente de la cola.
    void proximas_lecturas();

    //PRE: La lista_lecturas debe estar bien definida.
    //POST: Crea una cola de lecturas, ordenada por minutos de lectura.
    void cola_de_lecturas();

    //PRE: La lista_lecturas debe estar bien definida.
    //POST: Devuelve una lista con las lecturas, ordenada por minutos de lectura.
    Lista<Lectura*>* ordenar_por_minutos();

    //PRE: la lista_lecturas y lecturas_ordenadas deben estar bien definidas.
    /*POST: Devuelve el indice de la lista_lecturas donde se debe almacenar
            la lectura para mantener la lista ordenada por minutos de lectura. */
    int obtener_posicion_segun_minutos(Lista<Lectura*>* lecturas_ordenadas, Lectura* lectura);

    //PRE: La cola_lecturas debe estar bien definida.
    //POST: Poregunta al usuario si desea leet la lectura al frente de la cola.
    void marcar_como_leida();

    //!Opcion 12 -> salir()
    //se imprime el saludo desde selector_menu y se destruiría el objeto Menu ???
    //PRE: -
    //POST: Lbera toda la memoria pedida durante el programa.
    void liberar_memoria();

    //PRE: La lista_lecturas y lista_escritores deben estar bien definidas.
    //POST: Llama a métodos que liberan ambas listas.
    void liberar_listas();

    //PRE: La lista_escritores debe estar bien definida.
    //POST: Libera los Escritores almacenados en lista_escritores y luego la misma lista.
    void liberar_escritores();

    //PRE: La lista_lecturas debe estar bien definida.
    //POST: Libera las lecturas almacenadas en lista_lecturas y luego la misma lista.
    void liberar_lecturas();

    //PRE: La cola debe estar bien definida (se debe haber creado).
    //POST: Libera la memoria pedida para crear la cola vacía.
    void liberar_cola();

public:

    //PRE: -
    //POST: Construye un Menu.
    Menu();

    //PRE: -
    //POST: Destruye un Menu.
    ~Menu();

    //PRE: Menu debe ser un objeto válido.
    //POST: Impriem las opcines del Menu.
    void mostrar_menu();

    //PRE: Menu debe ser un objeto válido.
    //POST: Pide al usuario la opcion que desea ejecutar del Menu.
    void elegir_opcion();

    //PRE: Menu debe ser un objeto válido.
    //POST: Dependiendo de la opcion ingresada por el usuario, se ejecuta la acción correspondiente.
    bool selector_menu();
};

#endif
