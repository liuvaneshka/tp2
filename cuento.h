//
// Created by liuvaneshka on 17/05/22.
//
#ifndef CUENTO_H
#define CUENTO_H

class Cuento {
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
    /* post : imprime el cuento
    */
    void mostrar_cuento();
};


#endif
