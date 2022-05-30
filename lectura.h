#ifndef TP2_LECTURA_H
#define TP2_LECTURA_H
#include <iostream>
#include "CONSTANTES.h"
#include "escritor.h"
using namespace std;

class Lectura {

protected:
    int minutos;
    int anio;
    Escritor* escritor;
    string titulo;

public:

    //PRE:
    //POST:
    Lectura(string titulo, Escritor *escritor, int anio, int minutos);
    Lectura();  // TEMPLATE!!!

    //PRE:
    //POST:
    virtual ~Lectura() = 0;

    //PRE:
    //POST:
    virtual void mostrar_lectura() = 0;

    //PRE:
    //POST:
    string obtener_titulo();

    //PRE:
    //POST:
    int obtener_minutos();

    //PRE:
    //POST:
    int obtener_anio();

    //PRE:
    //POST:
    Escritor *obtener_escritor();

    //PRE:
    //POST:
    int comparar_lecturas(Lectura *_lectura);
};

#endif //TP2_LECTURA_H