#ifndef __NODO_H__
#define __NODO_H__
#include <iostream>

template <typename Dato>
class Nodo{

private:
    Dato dato;
    Nodo* siguiente;

public:

    //PRE: dato debe ser un dato válido.
    //POST: Construye un nodo con el dato "dato" y anterior es nullptr.
    Nodo(Dato dato);

    //PRE: p_nodo es un puntero válido y el objeto Nodo es un objeto válido.
    //POST: Cambia hacia donde apunta el Nodo.
    void cambiar_siguiente(Nodo* p_nodo);

    //PRE: El objeto Nodo debe ser un objeto válido.
    // POST: Le asigna dato al dato del nodo.
    void asignar_dato(Dato _dato);

    //PRE: El objeto Nodo debe ser un objeto válido.
    //POST: Devuelve el dato del nodo.
    Dato obtener_dato();

    //PRE: El objeto Nodo debe ser un objeto válido.
    //POST: Devuelve el Nodo siguiente.
    Nodo* obtener_siguiente();

};

////////////////////////////////////////////////

template <typename Dato>
Nodo<Dato>::Nodo(Dato dato){
    this -> dato = dato;
    siguiente = 0;
}

template <typename Dato>
void Nodo<Dato>::cambiar_siguiente(Nodo<Dato>* p_nodo){
    siguiente = p_nodo;
}

template <typename Dato>
Dato Nodo<Dato>::obtener_dato(){
    return dato;
}

template <typename Dato>
void Nodo<Dato>:: asignar_dato(Dato _dato) {
    dato = _dato;
}

template <typename Dato>
Nodo<Dato>* Nodo<Dato>::obtener_siguiente(){
    return siguiente;
}

#endif // __NODO_H__
