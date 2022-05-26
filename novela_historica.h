#ifndef __NOVELA_HISTORICA_H__
#define __NOVELA_HISTORICA_H__
#include "novela.h"

class Novela_historica : public Novela{

private:
    generos genero;
    char* tema;

public:
    //PRE: genero y tema deben ser válidos.
    //POST: Construye un objeto Novela_historica.
    Novela_historica(string titulo, Escritor* autor, int anio, int minutos, char* tema);

    //PRE: El objeto Novela_historica debe ser un objero válido.
    //POST: Devuelve el tema de la Novela_historica.
    char* obtener_tema();

    //PRE: El objeto Novela_historica debe ser un objeto válido.
    //POST: Muestra por pantalla los atributos de Novela_historica.
    void mostrar_lectura();

    //PRE: El objeto Novela_historica debe ser un objero válido.
    //POST: Destruye un objeto Novela_historica.
    ~Novela_historica();
};
#endif // __NOVELA_HISTORICA_H__