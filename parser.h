//
// Created by liuvaneshka on 25/05/22.
//
#include<iostream>
#include<string>
#include "archivo.h"
#include "lectura.h"
#include "escritor.h"

#ifndef PARSER_H
#define PARSER_H

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

    /* pre: recibe la ruta del archivo, y la lista vacia por referencia
     * post: crea los objetos y los inserta en la lista
    */
    void procesar_escritor(string ruta, Lista<Escritor*> &lista_escritores);

    /* pre: recibe la ruta del archivo, y la lista vacia por referencia
     * post: crea los objetos y los inserta en la lista
    */
    void procesar_lectura(string ruta, Lista<Lectura*> &lista_lectura);
};


#endif
