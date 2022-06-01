

#ifndef __LISTA_H__
#define __LISTA_H__
#include "nodo.h"

template <typename Dato>
class Lista{

private:
    Nodo<Dato>* primero;
    Nodo<Dato>* cursor;
    int tamanio;

    //PRE:
    //POST:
    Nodo<Dato>* obtener_nodo(int posicion);

public:

    //PRE: -
    //POST: Construye una Lista vacía.
    Lista();

    //PRE: El objeto Lista debe ser un objeto válido.
    //POST: Destruye la Lista.
    ~Lista();

    //PRE: dato es un dato válido. 1 <= pos <= obtener_tamanio() + 1.
    //POST: Agrega el dato en la posicion indicada.
    void alta(Dato dato, int posicion);

    //PRE: dato es un dato válido.
    //POST: Agrega el dato al final de la lista.
    void alta_al_final(Dato dato);

    //PRE: La lista no puede estar vacía. 1 <= pos <= obtener_cantidad().
    //POST: Elimina el dato que se encuentra en la posicion indicada.
    void baja(int posicion);

    //PRE: La lista no debe estar vacía.
    //POST: Devuelve el dato que se encuentra en la posicion.
    Dato consultar(int posicion);

    //PRE: El objeto Lista debe ser un objeto válido.
    //POST: Devuelve true si la lista está vacía, false en caso contrario.
    bool vacia();

    //PRE: El objeto Lista debe ser un objeto válido.
    //POST: Devuelve el tamanio de la lista.
    int obtener_tamanio();

    //PRE: El objeto Lista debe ser un objeto válido.
    //POST: Dirige al cursor a la primera posicion
    void inicializar();

    //PRE: El objeto Lista debe ser un objeto válido.
    //POST: Devuelve false si cursor está en la ultima posicion, true en caso contrario.
    bool hay_siguiente();

    //PRE: El objeto Lista debe ser un objeto válido.
    //POST: Avanza una posicion.
    void siguiente();

    //PRE:
    //POST:
    Dato obtener_dato_cursor();

};

////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <typename Dato>
Lista <Dato>::Lista(){
    primero = 0;
    cursor = 0;
    tamanio = 0;
}

template <typename Dato>
Nodo<Dato>* Lista <Dato>::obtener_nodo(int posicion){
    Nodo<Dato>* actual = primero;
    int contador = 1;
    while (contador < posicion){
        actual = actual -> obtener_siguiente();
        contador++;
    }
    return actual;
}

template <typename Dato>
void Lista <Dato>::alta(Dato dato, int posicion){
    Nodo<Dato>* nuevo = new Nodo<Dato>(dato);
    if (posicion == 1){
        nuevo -> cambiar_siguiente(primero);
        primero = nuevo;
    }
    else{
        Nodo<Dato>* aux = obtener_nodo(posicion - 1);
        nuevo -> cambiar_siguiente(aux -> obtener_siguiente());
        aux -> cambiar_siguiente(nuevo);
    }
    tamanio++;
}


template <typename Dato>
void Lista <Dato>::alta_al_final(Dato dato){
    int posicion_final = obtener_tamanio() + 1;
    alta(dato, posicion_final);
}

template <typename Dato>
void Lista <Dato>::baja(int posicion){
    Nodo<Dato>* borrar = primero;
    if (posicion == 1){
        primero = primero -> obtener_siguiente();
    }
    else{
        Nodo<Dato>* aux = obtener_nodo(posicion - 1);
        borrar = aux -> obtener_siguiente();
        aux -> cambiar_siguiente(borrar -> obtener_siguiente());
    }
    delete borrar;
    tamanio--;
}

template <typename Dato>
Dato Lista <Dato>::consultar(int posicion){
    return obtener_nodo(posicion)-> obtener_dato();
}

template <typename Dato>
bool Lista <Dato>::vacia(){
    return tamanio == 0;
}

template <typename Dato>
int Lista <Dato>::obtener_tamanio(){
    return tamanio;
}

template <typename Dato>
Lista <Dato>::~Lista(){
    while (! vacia())
        baja(1);
}

// VERIFICAR ESTAS 3 FUNCIONES !!! ////////////////////
template <typename Dato>
void Lista <Dato>::inicializar(){
    cursor = primero;
    std::cout << "primero: " << primero << std::endl;
}

template <typename Dato> bool Lista <Dato>::hay_siguiente(){
    std::cout << "hay sig??????? :  " << cursor -> obtener_siguiente() << std::endl;
    return (cursor -> obtener_siguiente() == 0);
}

template <typename Dato>
void Lista<Dato>::siguiente(){
    //Dato elemento = cursor -> obtener_dato();
    cursor = cursor->obtener_siguiente();
    std::cout << "cursor " << cursor <<std::endl;
    //return elemento;
}

template <typename Dato>
Dato Lista<Dato>::obtener_dato_cursor(){
    return cursor->obtener_dato();
}


#endif // __LISTA_H__