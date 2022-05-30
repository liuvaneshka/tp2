#include "nodo.h"

template <typename Dato>
Nodo<Dato>::Nodo(Dato dato){
    this -> dato = dato;
    siguiente = 0;
}

template <typename Dato>
void Nodo<Dato>::cambiar_siguiente(Nodo* p_nodo){
    siguiente = p_nodo;
}

template <typename Dato>
Dato Nodo<Dato>::obtener_dato(){
    return dato;
}

template <typename Dato>
Nodo<Dato>* Nodo<Dato>::obtener_siguiente(){
    return siguiente;
}

