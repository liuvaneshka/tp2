#include "cola.h"
#include <iostream>

Cola::Cola(){
    primero = nullptr;
    ultimo = primero;
}

void Cola::encolar(Dato dato){
    Nodo<Dato>* nuevo = new Nodo<Dato>(dato);
    if (ultimo)
        ultimo -> cambiar_siguiente(nuevo);
    else
        primero = nuevo;
    ultimo = nuevo;
}

Dato Cola::desencolar(){
    Nodo<Dato>* borrar = primero;
    primero = primero -> obtener_siguiente();         // Si el primero quedo apuntando a null, entonces eliminé el ultimo elemento y ultimo tambien apunta a null
    if (!primero)
        ultimo = primero;
    Dato desencolado = borrar->obtener_dato();
    delete borrar;
    borrar = nullptr;
    return desencolado;
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