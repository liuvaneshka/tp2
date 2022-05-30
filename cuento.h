#ifndef CUENTO_H
#define CUENTO_H
#include "lectura.h"
using namespace std;

class Cuento : public Lectura{

private:
    string libro;

public:

    //PRE: libro es una cadena.
    //POST: Inicializa un cuento a partir de los atributos dados.
    Cuento(string titulo, Escritor *escritor, int anio, int minutos, string libro);

    //PRE: -
    //POST: destruye Cuento.
    ~Cuento();

    //PRE: -
    //POST: devuelve el titulo del libro
    string obtener_libro();

    //PRE: -
    //POST: imprime el cuento.
    void mostrar_lectura();

};

#endif