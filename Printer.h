#ifndef __PRINTER_H__
#define __PRINTER_H__
#include <string>
#include <iostream>
#include "CONSTANTES.h"
using namespace std;

class Printer{

public:

    //PRE: El numero a ingresar debe ser un entero mayor a cero.
    //POS: Le solicita al usuario que ingrese un numero del 1 al 12 para ejecutar alguna opción del menu.
    int pedir_opcion();
    
    //PRE: -
    //POS: Le solicita al usuario que ingrese el titulo de una Lectura para ser procesada.
    string pedir_titulo();
    
    //PRE: El numero a ingresar debe ser un entero mayor a cero.
    //POS: Le solicita al usuario que ingrese un anio para ser procesado.
    int pedir_anio();
    
    //PRE: El numero a ingresar debe ser un entero mayor a cero.
    //POS: Le solicita al usuario que ingrese los minutos de la Lectura para ser procesados.
    int pedir_minutos();
    
    //PRE: El numero a ingresar debe ser un entero mayor a cero.
    //POS: Le solicita al usuario que ingrese un tipo de Lectura (cuento, poema o novela) para ser procesado.
    int pedir_tipo();

    //PRE: El numero a ingresar debe ser un entero mayor a cero.
    //POS: Le solicita al usuario que ingrese una cantidad de versos determinada para ser procesado
    int pedir_versos();
    
    //PRE: -
    //POS: Le solicita al usuario que ingrese el nombre de un libro para ser procesado
    string pedir_libro();
    
    //PRE: El numero a ingresar debe ser un entero mayor a cero.
    /*POS: Le solicita al usuario que ingrese un numero del 1 al 7, a cada numero le corresponde un genero de novela que
           será procesado. */
    generos pedir_genero();
    
    //PRE: -
    //POS: le solicita al usuario que ingrese un tema de una novela histórica para ser procesado.
    string pedir_tema();

    //PRE: -
    //POS: Le solicita al usuario que ingrese un nombre para ser procesado.
    string pedir_nombre();
    
    //PRE: -
    //POS: le solicita al usuario que ingrese la nacionalidad de un escritor, si es desconocido se pide ingresar '¿?'.
    string pedir_nacionalidad();
    
    //PRE: -
    /*POS: le solicita al usuario que ingrese el anio de nacimiento del escritor en cuestion para ser procesado, si se
           desconoce se pide ingresar un -1. */
    int pedir_nacimiento();
    
    /*PRE: El numero del anio de fallecimiento debe ser mayor al numero del anio de nacimiento. El unico caso en el que esto
           no sucede es cuando el escritor en cuestion no fallecio o se desconoce su fallecimiento (se le asigna -1). */
    /*POS: Le solicita al usuario que ingrese el anio de fallecimiento del escritor en cuestion para ser procesado, si se
           desconoce se pide ingresar un -1. */
    int pedir_fallecimiento();
    
    //PRE: -
    //POS: Le solicita al usuario que ingrese el anio desde el cual se buscaran ciertas lecturas.
    int pedir_anio_desde();
    
    //PRE: -
    //POS: Le solicita al usuario que ingrese el anio hasta el cual se buscaran ciertas lecturas.
    int pedir_anio_hasta();

    //PRE: Ingresar 's' o 'n', no ingresar 'si' ni 'no'.
    //POS: Le solicita al usuario que ingrese s (SI) o n (NO) para marcar si quiere marcarse como leída una lectura.
    char opcion_leer();
};

#endif // __PRINTER_H__
