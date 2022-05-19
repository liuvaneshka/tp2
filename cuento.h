//
// Created by liuvaneshka on 17/05/22.
//
#ifndef CUENTO_H
#define CUENTO_H
#include "Lectura.h"


class Cuento : public Lectura{
private:
    string libro;
public:
    /* pre: libro es una cadena
     * post: Inicializa un cuento a partir de los atributos dados
     */
    Cuento(string libro);
    /*post: destruye Cuento
    */
    ~Cuento();
    /* post : devuelve el titulo del libro
    */
    string obtener_libro();
    /*pre: obtiene una cadena representando el libro
     post: asigna al atributo librpo el valor de la cadena
     */
    void asignar_libro(string titulo);
    /* post : imprime el cuento
    */
    void mostrar_lectura();
};


#endif
