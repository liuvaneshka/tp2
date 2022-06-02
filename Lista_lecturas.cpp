#include "Lista_lecturas.h"

Lista_lecturas::Lista_lecturas(){
    Lista<Lectura*> lista_lecturas;
}

Lista_lecturas::~Lista_lecturas(){
    while(!lista_lecturas.vacia()){
        Lectura* eliminar = lista_lecturas.consultar(1);
        delete eliminar;          // Elimino objeto Lectura

        lista_lecturas.baja(1);   // Se elimina el Nodo
    }
}

void Lista_lecturas::alta(Lectura* lectura){
    int posicion = posicion_segun_anio(lectura);
    lista_lecturas.alta(lectura, posicion);
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


void Lista_lecturas::baja(int posicion){
    Lectura* eliminar = lista_lecturas.consultar(posicion);
    delete eliminar;
    lista_lecturas.baja(posicion);
}

int Lista_lecturas::rastrear(string titulo_lectura){
    int indice = 1, indice_correspondiente = -1;

    lista_lecturas.inicializar();
    while(lista_lecturas.hay_actual() && lista_lecturas.consultar(indice)->obtener_titulo() != titulo_lectura){
        indice++;
        lista_lecturas.siguiente();
    }

    if(lista_lecturas.hay_actual())
        indice_correspondiente = indice;

    return indice_correspondiente;
}

Lectura* Lista_lecturas::consultar(int posicion){
    return lista_lecturas.consultar(posicion);
}

bool Lista_lecturas::vacia(){
    return lista_lecturas.vacia();
}

void Lista_lecturas::sortear(){
    int num_random = rand() % lista_lecturas.obtener_tamanio() + 1;

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
    }

    if(contador_lecturas == 0)
        cout << "\nNo hay lecturas entre los anios ingresados\n" << endl;
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


Lista<Lectura*>* Lista_lecturas::ordenar_por_minutos(){
    Lista<Lectura*>* lecturas_ordenadas = new Lista<Lectura*>;
    int posicion_correcta;

    lista_lecturas.inicializar();
    while(lista_lecturas.hay_actual()){
        Lectura* lectura_actual = lista_lecturas.obtener_dato_cursor();
        posicion_correcta = posicion_segun_minutos(lecturas_ordenadas, lectura_actual);

        lecturas_ordenadas->alta(lectura_actual, posicion_correcta);
        lista_lecturas.siguiente();
    }
    return lecturas_ordenadas;
}

int Lista_lecturas::posicion_segun_minutos(Lista<Lectura*> *lecturas_ordenadas, Lectura* lectura){
    int indice = 1;
    int sobrecargar = 0; //numero = 0, creado para sobrecargar el método de comparar

    if (!lecturas_ordenadas->vacia()){
        lecturas_ordenadas->inicializar();

        while(lecturas_ordenadas->hay_actual() && lectura->comparar_lecturas(lecturas_ordenadas->consultar(indice), sobrecargar) != -1){
            indice++;
            lecturas_ordenadas->siguiente();
        }
    }
    return indice;
}