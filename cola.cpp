#include "cola.h"
#include <iostream>

Cola::Cola(){
    primero = 0;
    ultimo = 0;
}

void Cola::encolar(Dato dato){
    Nodo<Dato>* nuevo = new Nodo(dato);
    if (primero)
        ultimo -> cambiar_siguiente(nuevo);
    else
        primero = nuevo;
    ultimo = nuevo;
}

void Cola::desencolar(){
    Nodo<Dato>* borrar = primero;
    primero = primero -> obtener_siguiente();         // Si el primero quedo apuntando a null, entonces eliminé el ultimo elemento y ultimo tambien apunta a null
    if (! primero)
        ultimo = 0;
    borrar = 0;
    delete borrar;
}

bool Cola::vacia(){
    return primero == 0;
}

Dato Cola::consultar(){
    return primero -> obtener_dato();
}

Cola::~Cola(){
    while (! vacia())
        desencolar();
}
