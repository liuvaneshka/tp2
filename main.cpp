#include <iostream>
#include "menu.h"


int main() {
    /*
    Menu menu;
    menu.mostrar_menu();
    menu.elegir_opcion();

    while (menu.selector_menu()) {
        menu.mostrar_menu();
        menu.elegir_opcion();
    }*/
    Lista<Lectura*>* lista = new Lista<Lectura*>;
    Escritor* escritor = new Escritor("nombre", "argentino", 1999, 2000);
    Cuento* cuento = new Cuento("titulo", escritor, 1999, 15, "hola");
    Cuento* cuento1 = new Cuento("titulo1", escritor, 2000, 1, "hola1");
    Cuento* cuento2 = new Cuento("titulo2", escritor, 1988, 10, "hola2");

    lista->alta_al_final(cuento1);
    lista->alta_al_final(cuento2);
    lista->alta_al_final(cuento);

    Cola* cola = new Cola;

    for (int i = 1; i <= lista ->obtener_tamanio(); i++){ //Mauro: cuando lo probamos en el meet, estaba con <, por eso quizás no imprimía el ultimo... :(
        cola->encolar(lista->consultar(i));
    }

    Lectura* desencolado = cola->desencolar();
    desencolado->mostrar_lectura();

    Lectura* desencolado1 = cola->desencolar();
    desencolado1->mostrar_lectura();

    Lectura* desencolado2 = cola->desencolar();
    desencolado2->mostrar_lectura();

    return 0;
}
