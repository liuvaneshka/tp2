#ifndef __COLA_H__
#define __COLA_H__
#include "nodo.h"
#include "lectura.h"

typedef Lectura* Dato;

class Cola{

private:
    Nodo<Dato>* primero;
    Nodo<Dato>* ultimo;

public:

    // PRE: -
    // POST: Crea una cola vacía
    Cola();

    // PRE: La cola debe ser una cola válida
    // POST: Destruye la cola
    ~Cola();

    // PRE: -
    // POST: Encola un elemento al final
    void encolar(Dato dato);

    // PRE: La cola no puede estar vacía
    // POST: Desencola el elementop del frente
    void desencolar();

    // PRE: La cola debe ser una cola valida
    // POST: Devuelve true si la cola esta vacia, false en caso contrario
    bool vacia();

    // PRE: La cola debe ser una cola válida
    // POST: Devuelve el dato del frente
    Dato consultar();
};
#endif // __COLA_H__