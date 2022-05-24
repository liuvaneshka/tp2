#ifndef PARSER_H
#define PARSER_H
#include<iostream>
#include<string>
#include "archivo.h"
#include "lectura.h"
#include "escritores.h"


using namespace std;

class Parser{
private:

    Archivo entrada;

public:

    /*post: Crea el objeto.
    */
    Parser();

    /*post: destruye el archivo.
    */
    ~Parser();

    /*post: Abre el archivo de la ruta en modo lectura
    */
    void procesar_escritor(string ruta, Lista<Escritor*> &lista_escritores);

    /*post: Abre el archivo de la ruta en modo lectura
    */
    void procesar_lectura(string ruta, Lista<Lectura*> &lista_lectura);
};
#endif // PARSER_H