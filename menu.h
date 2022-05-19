//
// Created by liuvaneshka on 17/05/22.
//

#ifndef MENU_H
#define MENU_H

class menu {
private:
    int opcion
public:
    /*pre: opcion es un entero
     * post: inicializa un menu a partir de la opcion
     */
    Menu(int _opcion);
    /*post: destruye Menu
    */
    ~Menu();
    /* post : devuelve la opcion del menu
    */
    obtener_opcion();
    /* post : imprime las opciones del menu
    */
    mostrar_opciones();
    /* post : asigna la opcion
    */
    elegir_opcion();

};


#endif
