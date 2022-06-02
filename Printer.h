#ifndef __PRINTER_H__
#define __PRINTER_H__
#include <string>
#include <iostream>
#include "CONSTANTES.h"
using namespace std;

class Printer{

public:

    int pedir_opcion();
    string pedir_titulo();
    int pedir_anio();
    int pedir_minutos();
    int pedir_tipo();
    string pedir_titulo_eliminar();

    int pedir_versos();
    string pedir_libro();
    generos pedir_genero();
    generos pedir_genero_listar();
    string pedir_tema();


    string pedir_nombre();
    string pedir_nacionalidad();
    int pedir_nacimiento();
    int pedir_fallecimiento();

    int pedir_nuevo_fallecimiento();
    int pedir_anio_desde();
    int pedir_anio_hasta();

   char opcion_leer();

};

#endif // __PRINTER_H__