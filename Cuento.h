#ifndef CUENTO_H
#define CUENTO_H
#include "Lectura.h"
using namespace std;

class Cuento : public Lectura{

private:
    string libro;

public:

    //PRE: anio > 0, minutos >0, escritor es un objeto válido.
    //POST: Inicializa un cuento a partir de los atributos dados.
    Cuento(string titulo, Escritor *escritor, int anio, int minutos, string libro);

    //PRE: Cuento debe ser un objeto válido.
    //POST: destruye Cuento.
    ~Cuento();

    //PRE: Cuento debe ser un objeto válido.
    //POST: devuelve el titulo del libro
    string obtener_libro();

    //PRE: Cuento debe ser un objeto válido.
    //POST: Imprime los atributos del Cuento.
    void mostrar_lectura();

    //PRE: Cuento debe ser un objeto válido.
    //POST: Por ser un cuento, no hace nada ya que no tiene género (polimorfimo)
    void imprimir_novela_genero(generos genero);

};

#endif
