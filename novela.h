#ifndef __NOVELA_H__
#define __NOVELA_H__
#include "lectura.h"
using namespace std;

class Novela : public Lectura {

private:
    generos genero;

public:

    //PRE: genero debe ser un género válido.
    //POST: Construye un objeto Novela.
    Novela(string titulo, Escritor *escritor, int anio, int minutos, generos genero);

    //PRE: El objeto Novela debe ser un objeto válido.
    //POST: Destruye un objeto Novela.
    ~Novela();

    //PRE: El objeto Novela debe ser un objeto válido.
    //POST: Devuelve el índice del enumerado del género de la novela.
    generos obtener_genero();

    //PRE: El objeto Novela debe ser un objeto válido.
    //POST: Muestra por pantalla los atributos de Novela.
    void mostrar_lectura();
};
#endif // __NOVELA_H__