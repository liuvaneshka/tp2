#ifndef __LISTA_LECTURAS_H__
#define __LISTA_LECTURAS_H__
#include "Lista.h"
#include "Lectura.h"
#include "CONSTANTES.h"

class Lista_lecturas{

private:
    Lista<Lectura*> lista_lecturas;

    //PRE: el objeto lectura debe ser un objeto valido
    //POS: Determina la posicion de una lectura en la lista segun su anio de publicacion
    int posicion_segun_anio(Lectura* lectura);

public:
    //PRE: -
    //POS: Construye una Lista de Lecturas vacia.
    Lista_lecturas();

    //PRE: El objeto Lista_lecturas debe ser un objeto válido.
    //POS: Destruye la Lista de Lecturas.
    ~Lista_lecturas();

    //PRE: El objeto Lista_lecturas debe ser un objeto válido.
    //POST: Dirige al cursor a la primera posicion
    void inicializar();

    //PRE: El objeto Nodo debe ser un objeto válido.
    //POST: devuelve true si cursor está en un nodo, false si es nullptr.
    bool hay_actual();

    //PRE: El objeto Lista de Lecturas debe ser un objeto válido.
    //POST: Avanza una posicion.
    void siguiente();

    //PRE: El objeto Nodo debe ser un objeto válido.
    //POST: Devuelve la Lectura que se encuentra en el nodo en la posicion de cursor.
    Lectura* obtener_dato_cursor();

    //PRE: lectura es una Lectura válida.
    //POST: Agrega la lectura al final de la lista.
    void alta(Lectura* lectura);

    //PRE: La lista no puede estar vacía. 1 <= pos <= obtener_cantidad().       // obtener_tamanio() ??
    //POST: Elimina el dato que se encuentra en la posicion indicada.
    void baja(int posicion);

    //PRE: El objeto Lista_lecturas debe ser un objeto válido.
    //POS: Devuelve true si la lista está vacía, false en caso contrario.
    bool vacia();

    //PRE: La lista no debe estar vacía.
    //POST: Devuelve la Lectura que se encuentra en la posicion.
    Lectura* consultar(int posicion);


    //PRE: -
    //POS: Devuelve el indice (numero entero) de la lista de la lectura que se quiere rastrear
    int rastrear(string titulo);

    //PRE: -
    //POS: sortea un numero (1 <= num_random <= obtener_tamanio()) e imprime los datos de la lectura cuyo indice es el
    //      numero sorteado
    void sortear();

    //PRE: lista_lecturas.vacia() = false
    //POS: Muestra la informacion de las lecturas que pertenecen a la lista
    void listar();

    //PRE: lista_lecturas.vacia() = false, tienen que ser anios validos
    //POS: Muestra la informacion de las lecturas publicados entre dos anios particulares (siempre que pertenezcan a la lista)
    void listar_entre_anios(int desde, int hasta);      // meti el if del contador adentro del else

    //PRE: lista_lecturas.vacia() = false
    //POS: Muestra la informacion de las lecturas escritos por un escritor en particular (siempre que pertenezcan a la lista)
    void listar_por_escritor(string nombre_escritor);

    //PRE: lista_lecturas.vacia() = false
    //POS: Muestra la informacion de las Novelas de un genero en paricular (siempre que pertenezcan a la lista)
    void listar_por_genero(generos genero);
};
#endif // __LISTA_LECTURAS_H__
