#ifndef __LISTA_LECTURAS_H__
#define __LISTA_LECTURAS_H__
#include "Lista.h"
#include "Lectura.h"

class Lista_lecturas{

private:
    Lista<Lectura*> lista_lecturas;

    //PRE:
    //POST:
    int posicion_segun_anio(Lectura* lectura);

    //PRE:
    //POST:
    int posicion_segun_minutos(Lista<Lectura*> *lecturas_ordenadas, Lectura* lectura);

public:

    //PRE:
    //POST:
    Lista_lecturas();

    //PRE:
    //POST:
    ~Lista_lecturas();

    //PRE:
    //POST:
    bool vacia();

    //PRE:
    //POST:
    void alta(Lectura* lectura);

    //PRE:
    //POST:
    void baja(int posicion);

    //PRE:
    //POST:
    Lectura* consultar(int posicion);

    //PRE:
    //POST:
    int rastrear(string titulo_lectura);

    //PRE:
    //POST:
    void sortear();

    //PRE:
    //POST:
    void listar();

    //PRE:
    //POST:
    void listar_entre_anios(int desde, int hasta);

    //PRE:
    //POST:
    void listar_por_escritor(string nombre_escritor);

    //PRE:
    //POST:
    void listar_por_genero(generos genero);

    //PRE:
    //POST:
    Lista<Lectura*>* ordenar_por_minutos();

};
#endif // __LISTA_LECTURAS_H__