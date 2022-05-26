#ifndef __PARSER_H__
#define __PARSER_H__
#include "lista.h"
#include "lectura.h"
#include "novela.h"
#include "cuento.h"
#include "novela_historica.h"
#include "poema.h"
#include <sstream>
using namespace std;

class Parser{

private:
    Archivo entrada;

    void almacenar_escritor(Escritor* escritor, Lista<Escritor*> &lista_escritores);
    void almacenar_lectura(Lectura* lectura, Lista<Lectura*> &lista_lecturas);

    bool verificar_escritor(string linea_escritor);
    Escritor* obtener_escritor(string dato, Lista<Escritor*> lista_escritores);
    Escritor* rastrear_escritor(int codigo, Lista<Escritor*> lista_escritores);
    int obtener_posicion_correcta(Lectura* lectura, Lista<Lectura*> &lista_lecturas);

public:
    // CONSTRUCTOR
    Parser(Archivo entrada);

    // DESTRUCTOR
    ~Parser();

    void procesar_escritor(string ruta, Lista<Escritor*> &lista_escritores);
    void procesar_lectura(string ruta, Lista<Lectura*> &lista_lecturas, Lista<Escritor*> &lista_escritores);
    int referencia(string linea);

};
#endif // __PARSER_H__
