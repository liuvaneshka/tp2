#ifndef __PARSER_H__
#define __PARSER_H__
#include "lista.h"
#include "lectura.h"
#include "escritor.h"
#include "archivo.h"
#include "novela.h"
#include "novela_historica.h"
#include "cuento.h"
#include "poema.h"

#include <sstream>
using namespace std;

class Parser{

private:
    //Archivo entrada;
    //creacion inicial lista
    generos obtener_genero(string genero);
    //PRE:
    //POST:
    void almacenar_escritor(Escritor* escritor, Lista<Escritor*> &lista_escritores);

    //PRE:
    //POST:
    void almacenar_lectura(Lectura* lectura, Lista<Lectura*> &lista_lecturas);

    //PRE:
    //POST:
    bool verificar_escritor(string linea_escritor);

    //PRE:
    //POST:
    Escritor* obtener_escritor(string dato, Lista<Escritor*> lista_escritores);

    //PRE:
    //POST:
    Escritor* rastrear_escritor(int codigo, Lista<Escritor*> lista_escritores);

    //PRE:
    //POST:
    int obtener_posicion_correcta(Lectura* lectura, Lista<Lectura*> &lista_lecturas);

    //PRE:
    //POS:
    int obtener_referencia(string linea);

    //PRE:
    //POS:
    char* obtener_tema(string linea);

public:

    //PRE:
    //POST:
    //Parser();

    //PRE:
    //POST:
    //~Parser();

    //PRE:
    //POST:
    Lista <Escritor*> procesar_escritor(string ruta, Lista<Escritor*> &lista_escritores);
    //PRE:
    //POST:
    Lista <Lectura*> procesar_lectura(string ruta, Lista<Lectura*> &lista_lectura,Lista<Escritor*> &lista_escritores);
};
#endif // __PARSER_H__
