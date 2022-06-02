#include "Lista_lecturas.h"
Lista_lecturas::Lista_lecturas(){
    Lista<Lectura*> lista_lecturas;
}

Lista_lecturas::~Lista_lecturas(){
    while(!lista_lecturas.vacia()){
        Lectura* eliminar = lista_lecturas.consultar(1);
        delete eliminar;          // Elimino objeto Escritor

        lista_lecturas.baja(1);   // Se elimina el Nodo
    }
}

void Lista_lecturas::inicializar(){
    lista_lecturas.inicializar();
}

bool Lista_lecturas::hay_actual(){
    return lista_lecturas.hay_actual();
}

void Lista_lecturas::siguiente(){
    lista_lecturas.siguiente();
}

Lectura* Lista_lecturas::obtener_dato_cursor(){
    return lista_lecturas.obtener_dato_cursor();
}

void Lista_lecturas::alta(Lectura* lectura){
    int posicion = posicion_segun_anio(lectura);
    lista_lecturas.alta(lectura, posicion);
}

void Lista_lecturas::baja(int posicion){
    Lectura* eliminar = lista_lecturas.consultar(posicion);
    delete eliminar;
    lista_lecturas.baja(posicion);
}

bool Lista_lecturas::vacia(){
    return lista_lecturas.vacia();
}

Lectura* Lista_lecturas::consultar(int posicion){
    return lista_lecturas.consultar(posicion);
}

int Lista_lecturas::posicion_segun_anio(Lectura* lectura){
    int indice = 1;

    if (!lista_lecturas.vacia()){
        lista_lecturas.inicializar();

        while(lista_lecturas.hay_actual() && lectura->comparar_lecturas(lista_lecturas.consultar(indice)) != -1){
            indice++;
            lista_lecturas.siguiente();
        }
    }
    return indice;
}

int Lista_lecturas::rastrear(string titulo){
    int indice = 1, indice_correspondiente = -1;

    lista_lecturas.inicializar();
    while(lista_lecturas.hay_actual() && lista_lecturas.consultar(indice)->obtener_titulo() != titulo){
        indice++;
        lista_lecturas.siguiente();
    }

    if(lista_lecturas.hay_actual())
        indice_correspondiente = indice;

    return indice_correspondiente;
}

void Lista_lecturas::sortear(){
    int num_random = rand() % lista_lecturas.obtener_tamanio() + 1;
    cout << "numero random elegido: " << num_random << endl;

    Lectura* lectura_random = lista_lecturas.consultar(num_random);

    cout << "Lectura sorteada: " << endl;
    lectura_random->mostrar_lectura();
}

void Lista_lecturas::listar(){
    int contador = 1;
    lista_lecturas.inicializar();

    while(lista_lecturas.hay_actual()){
        cout << "Lectura numero: "<< contador << endl;
        Lectura* lectura_actual = lista_lecturas.obtener_dato_cursor();
        lectura_actual->mostrar_lectura();

        lista_lecturas.siguiente();
        contador++;
    }
}

void Lista_lecturas::listar_entre_anios(int desde, int hasta){
    int contador_lecturas = 0;

    if (desde > hasta)
        cout << "\nAños inválidos, intente nuevamente\n" << endl;

    else{
        lista_lecturas.inicializar();
        while(lista_lecturas.hay_actual()){
            Lectura* lectura_actual = lista_lecturas.obtener_dato_cursor();
            int anio_lectura_actual = lectura_actual->obtener_anio();

            if (anio_lectura_actual >= desde && anio_lectura_actual <= hasta){
                lectura_actual->mostrar_lectura();
                contador_lecturas++;
             }
            lista_lecturas.siguiente();
        }
        if(contador_lecturas == 0)
        cout << "\nNo hay lecturas entre los anios ingresados\n" << endl;
    }

    
}

void Lista_lecturas::listar_por_escritor(string nombre_escritor){
     bool hay_lecturas = false;

    lista_lecturas.inicializar();
    while(lista_lecturas.hay_actual()){
        Lectura* lectura_actual = lista_lecturas.obtener_dato_cursor();
        Escritor* escritor_actual = lectura_actual->obtener_escritor();

        if (escritor_actual != nullptr && escritor_actual->obtener_nombre() == nombre_escritor){
            hay_lecturas = true;
            cout << '\n';
            lectura_actual->mostrar_lectura();
        }
        lista_lecturas.siguiente();
    }

    if (!hay_lecturas)
        cout << "\nNo existen lecturas escritas por el Escritor ingresado, intente nuevamente\n" << endl;
}

void Lista_lecturas::listar_por_genero(generos genero){
    lista_lecturas.inicializar();
    while(lista_lecturas.hay_actual()){
        Lectura* lectura_actual = lista_lecturas.obtener_dato_cursor();
        lectura_actual->imprimir_novela_genero(genero);
        lista_lecturas.siguiente();
    }
}
