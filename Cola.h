#ifndef __COLA_H__
#define __COLA_H__
#include "Nodo.h"
#include "Lectura.h"

template <typename Dato>
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

template <typename Dato>
Cola<Dato>::Cola(){
    primero = nullptr;
    ultimo = primero;
}

template <typename Dato>
void Cola<Dato>::encolar(Dato dato){
    Nodo<Dato>* nuevo = new Nodo<Dato>(dato);
    if (ultimo)
        ultimo -> cambiar_siguiente(nuevo);
    else
        primero = nuevo;
    ultimo = nuevo;
}

template <typename Dato>
Dato Cola<Dato>::desencolar(){
    Nodo<Dato>* borrar = primero;
    primero = primero -> obtener_siguiente();         // Si el primero quedo apuntando a null, entonces eliminé el ultimo elemento y ultimo tambien apunta a null
    if (!primero)
        ultimo = primero;
    Dato desencolado = borrar->obtener_dato();
    delete borrar;
    borrar = nullptr;
    return desencolado;
}

template <typename Dato>
bool Cola<Dato>::vacia(){
    return primero == 0;
}

template <typename Dato>
Dato Cola<Dato>::consultar(){
    return primero -> obtener_dato();
}

template <typename Dato>
Cola<Dato>::~Cola(){
    while (! vacia())
        desencolar();
}
#endif // __COLA_H__
