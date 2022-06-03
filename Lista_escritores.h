#ifndef __LISTA_ESCRITORES_H__
#define __LISTA_ESCRITORES_H__
#include "Lista.h"
#include "Escritor.h"
#include "CONSTANTES.h"

class Lista_escritores{

private:
    Lista<Escritor*> lista_escritores;

public:
    //PRE: -
    //POS: Construye una Lista de Escritores vacia
    Lista_escritores();

    //PRE: El objeto Lista de Escritores debe ser un objeto válido
    //POS: Destruye la lista de escritores
    ~Lista_escritores();

    //PRE: nuevo_escritor es un Escritor valido
    //POS: Agrega el escritor al final de la lista
    void alta(Escritor* nuevo_escritor);

    //PRE: La lista no puede estar vacía. 1 <= pos <= obtener_cantidad()        // obtener_tamanio() ??
    //POS: Elimina el escritor ubicado en la posicion indicada
    void baja(int posicion);                                             // el IDE dice que nunca se usa

    //PRE: La lista no debe estar vacía
    //POS: Devueve el escritor ubicado en la posicion indicada
    Escritor* consultar(int posicion);

    //PRE: El objeto Lista_escritores debe ser un objeto válido.
    //POS: Devuelve true si la lista está vacía, false en caso contrario.
    bool vacia();

    //PRE: vacia() = false
    //POS: Muestra la informacion de los escritores que pertenecen a la lista
    void listar();

    //PRE: El escritor hallado debe ser un objeto valido
    //POS: Devuelve el escritor cuyo nombre se busca en la lista
    Escritor* rastrear(string nombre_escritor);
};

#endif // __LISTA_ESCRITORES_H__
