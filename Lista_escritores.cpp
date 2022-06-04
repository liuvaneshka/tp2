#include "Lista_escritores.h"
Lista_escritores::Lista_escritores(){
    Lista<Escritor*> lista_escritores;
}

Lista_escritores::~Lista_escritores(){
    while(!lista_escritores.vacia()){
        Escritor* eliminar = lista_escritores.consultar(1);
        delete eliminar;
        lista_escritores.baja(1);
    }
}

void Lista_escritores::alta(Escritor* nuevo_escritor){
    lista_escritores.alta(nuevo_escritor);
}

Escritor* Lista_escritores::consultar(int posicion){
    return lista_escritores.consultar(posicion);
}

bool Lista_escritores::vacia(){
    return lista_escritores.vacia();
}

void Lista_escritores::listar(){
    int contador = 1;
    lista_escritores.inicializar();

    while(lista_escritores.hay_actual()){
        cout << VERDE << "Escritor numero: " << contador << endl;
        Escritor* escritor_actual = lista_escritores.obtener_dato_cursor();
        escritor_actual -> mostrar_escritor();

        lista_escritores.siguiente();
        contador++;
    }
}

void Lista_escritores::listar_nombres_escritores(){
    int contador = 1;
    lista_escritores.inicializar();

    while(lista_escritores.hay_actual()){
        Escritor* escritor_actual = lista_escritores.obtener_dato_cursor();
        cout << VIOLETA << escritor_actual->obtener_nombre() << " ** ";

        lista_escritores.siguiente();
        contador++;
    }
    cout << endl;
}

Escritor* Lista_escritores::rastrear(string nombre_escritor){
    int indice = 1;
    Escritor* escritor_buscado = nullptr;

    lista_escritores.inicializar();
    while(lista_escritores.hay_actual() && lista_escritores.consultar(indice) -> obtener_nombre() != nombre_escritor){
        indice++;
        lista_escritores.siguiente();
    }
    if (lista_escritores.hay_actual())
        escritor_buscado = lista_escritores.consultar(indice);

    return escritor_buscado;
}
