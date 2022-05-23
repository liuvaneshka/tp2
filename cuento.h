#ifndef CUENTO_H
#define CUENTO_H
#include "lectura.h"

class Cuento : public Lectura{

private:
    string libro;

public:
    /* pre: libro es una cadena
    post: Inicializa un cuento a partir de los atributos dados
    */
    Cuento(string titulo, Escritor *autor, int anio, int minutos, string libro);

    /* post : devuelve el titulo del libro
    */
    string obtener_libro();

    /* post : imprime el cuento
    */
    void mostrar_lectura();

    /*post: destruye Cuento
    */
    ~Cuento();
};

#endif