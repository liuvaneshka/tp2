#ifndef TP2_LECTURA_H
#define TP2_LECTURA_H
#include <iostream>
#include "CONSTANTES.h"
#include "Escritor.h"
using namespace std;

class Lectura {

protected:
    int minutos;
    int anio;
    Escritor* escritor;
    string titulo;

public:

    //PRE: anio > 0, minutos > 0, escritor es un objeto válido.
    //POST: Construye un objeto Lectura.
    Lectura(string titulo, Escritor *escritor, int anio, int minutos);

    //PRE: -
    //POST: Constructor sin parámetros para el template de Lista<Lectura*>.
    Lectura();  // TEMPLATE!!!

    //PRE: El objeto Lectura es un objeto válido.
    //POST: Destruye la Lectura (destructor virtual).
    virtual ~Lectura() = 0;

    //PRE: El objeto Lectura es un objeto válido.
    //POST: método virtual, definido en cada subclase.
    virtual void imprimir_novela_genero(generos genero) = 0;

    //PRE: El objeto Lectura es un objeto válido.
    //POST: método virtual que imprime los atributos de la Lectura (polimorfismo).
    virtual void mostrar_lectura() = 0;

    //PRE: El objeto Lectura es un objeto válido.
    //POST: devuelve el titulo de la Lectura.
    string obtener_titulo();

    //PRE: El objeto Lectura es un objeto válido.
    //POST: devuelve los minutos de la Lectura.
    int obtener_minutos();

    //PRE: El objeto Lectura es un objeto válido.
    //POST: devuelve el año de publicación de la Lectura.
    int obtener_anio();

    //PRE: El objeto Lectura es un objeto válido.
    //POST: Devuelve el escritor de la Lectura.
    Escritor *obtener_escritor();

    //PRE: lectura es un objeto válido.
    /*POST: Devuelve -1 si la Lectura que llama posee un año de publicación anterior a la del parámetro.
            Devuelve 0 si las Lecturas poseen el mismo año de publicación.
            Devuelve 1 si la Lectura que llama posee un año de publicación posterior a la del parámetro. */
    int comparar_lecturas(Lectura *lectura);

    int comparar_lecturas(Lectura *lectura, int sobrecargar);
};

#endif //TP2_LECTURA_H
