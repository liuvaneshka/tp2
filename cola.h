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

    // PRE: La cola debe ser un objeto válido.
    // POST: Destruye una cola.
    ~Cola();

    // PRE: La cola debe ser un objeto válido.
    // POST: Encola un elemento al final de la Cola.
    void encolar(Dato dato);

    // PRE: La cola no puede estar vacía y debe ser un objeto válido.
    // POST: Desencola el elemento del frente de la Cola.
    Dato desencolar();

    // PRE: La cola debe ser un objeto válido.
    // POST: Devuelve true si la cola esta vacía, false en caso contrario.
    bool vacia();

    // PRE: La cola debe ser un objeto válido.
    // POST: Devuelve el dato del frente de la Cola.
    Dato consultar();
};
#endif // __COLA_H__
