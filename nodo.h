#ifndef __NODO_H__
#define __NODO_H__

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
    //POST: Devuelve el dato del nodo.
    Dato obtener_dato();

    //PRE: El objeto Nodo debe ser un objeto válido.
    //POST: Devuelve el Nodo siguiente.
    Nodo* obtener_siguiente();

};

#endif // __NODO_H__