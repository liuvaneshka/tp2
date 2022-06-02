#include "Menu.h"
#include "Parser.h"

Menu::Menu(){
    Parser parser;
    Lista <Escritor*> *lista_escritores = new Lista<Escritor*>;
    Lista_lecturas *lista_lecturas = new Lista_lecturas;
    cola_lecturas = nullptr;

    this->lista_escritores = parser.procesar_escritor(ARCHIVO_ESCRITORES, lista_escritores);
    this->lista_lecturas = parser.procesar_lectura(ARCHIVO_LECTURAS, lista_lecturas, lista_escritores);

    srand( (unsigned int) time(0));
}

Menu::~Menu(){
    liberar_escritores();
    //delete lista_escritores;        //Falta clase extra (Liu)
    delete lista_lecturas;
    if (cola_lecturas)
        delete cola_lecturas;
}

//METODO MOMENTANEO
void Menu::liberar_escritores(){
    while(!lista_escritores->vacia()){
        Escritor* eliminar = lista_escritores->consultar(1);
        delete eliminar;          // Elimino objeto Escritor

        lista_escritores->baja(1);   // Se elimina el Nodo
    }
    delete lista_escritores;
}


void Menu::mostrar_menu(){
    int tamanio = sizeof(OPCIONES)/sizeof(OPCIONES[0]);

    for(int i = 0; i < tamanio; i++)
        cout << AMARILLO << i+1 << ". " << OPCIONES[i]  << endl;

}

void Menu::elegir_opcion(){
    string opcion;
    this->opcion = printer.pedir_opcion();
}

bool Menu::selector_menu(){
    bool estado;
    switch (this->opcion){

        case 1:
            cout << VERDE << "caso 1: Agregar una nueva lectura"<< endl;
            agregar_lectura();
            estado = true;
            break;

        case 2:
            cout << VERDE << "caso 2: Quitar lectura" << endl;
            quitar_lectura();
            estado = true;
            break;

        case 3:
            cout << VERDE << "caso 3: Agregar un escritor" << endl;
            agregar_escritor();
            estado = true;
            break;

        case 4:
            cout << VERDE << "caso 4: Actualizar fallecimiento autor" << endl;
            modificar_fallecimiento();
            estado = true;
            break;

        case 5:
            cout << VERDE << "caso 5: Listar los escritores" << endl;
            listar_escritores();
            estado = true;
            break;

        case 6:
            cout << VERDE << "caso 6: Sortear una lectura" << endl;
            sortear_lectura();
            estado = true;
            break;

        case 7:
            cout << VERDE << "caso 7: Listar lecturas" << endl;
            listar_lecturas();
            estado = true;
            break;

        case 8:
            cout << VERDE << "caso 8: Listar lecturas por anio" << endl;
            listar_lecturas_entre_anios();
            estado = true;
            break;

        case 9:
            cout << VERDE << "caso 9: Listar lecturas por escritor" << endl;
            listar_por_escritor();
            estado = true;
            break;

        case 10:
            cout << VERDE << "caso 10: Listar Novelas por genero" << endl;
            listar_novelas_de_genero();
            estado = true;
            break;

        case 11:
            cout << VERDE << "caso 11: Listar proximas lecturas" << endl;
            proximas_lecturas();
            estado = true;
            break;

        case 12:
            cout << "\n\t\t\tCordial despedida\n" << endl;
            estado = false;
            break;

        default:
            cout << "\nError elige otra opcion valida\n" << endl;
            estado = true;
    }
    return estado;
}

void Menu::agregar_lectura(){
    Lectura* nueva_lectura = crear_lectura();
    lista_lecturas->alta(nueva_lectura);

    cout << "\nLectura creada: " << endl;
    nueva_lectura->mostrar_lectura();
}

Lectura* Menu::crear_lectura(){
    string titulo;
    int anio, minutos, tipo;
    Lectura* nueva_lectura = nullptr;
    Escritor* escritor_lectura = nullptr;

    titulo = printer.pedir_titulo();
    anio = printer.pedir_anio();
    minutos = printer.pedir_minutos();

    escritor_lectura = crear_escritor();

    tipo = printer.pedir_tipo();

    switch(tipo) {

        case 1:{
            int versos = printer.pedir_versos();
            nueva_lectura = new Poema(titulo, escritor_lectura, anio, minutos, versos);
            break;
        }

        case 2:{
            string libro = printer.pedir_libro();
            nueva_lectura = new Cuento(titulo, escritor_lectura, anio, minutos, libro);
            break;
        }

        case 3:{
            generos genero = printer.pedir_genero();

            if(genero == HISTORICA){
                string tema = printer.pedir_tema();
                nueva_lectura = new Novela_historica(titulo, escritor_lectura, anio, minutos, tema);
            }
            else
                nueva_lectura = new Novela(titulo, escritor_lectura, anio, minutos, genero);
            break;
        }

        default:
            cout << ROJO << "\nDatos inválidos, intente nuevamente.\n" << endl;
    }
    return nueva_lectura;
}

void Menu::quitar_lectura(){

    if (lista_lecturas->vacia())
        cout << ROJO << "\n No se puede eliminar ninguna lectura, la lista de lecturas está vacía\n" << endl;
    else {
        string titulo_lectura = printer.pedir_titulo();
        int indice_a_eliminar = lista_lecturas->rastrear(titulo_lectura);

        if (indice_a_eliminar == DESCONOCIDO)
            cout << ROJO << "\nLa lectura que desea eliminar no existe, intente nuevamente.\n" << endl;
        else{
            if (cola_lecturas && !cola_lecturas->vacia())
                actualizar_cola(lista_lecturas->consultar(indice_a_eliminar));
            lista_lecturas->baja(indice_a_eliminar);
            cout << AZUL << "\nLectura eliminada con éxito!\n" << endl;
        }
    }
}


void Menu::agregar_escritor(){
    Escritor* nuevo_escritor = crear_escritor();
    cout << "\nEscritor creado:" << endl;
    nuevo_escritor->mostrar_escritor();
}

Escritor* Menu::crear_escritor() {
    string nombre, nacionalidad;
    int nacimiento, fallecimiento;
    Escritor *nuevo_escritor;
    Escritor *escritor_hallado;

    nombre = printer.pedir_nombre();

    escritor_hallado = rastrear_escritor(nombre);

    if (escritor_hallado) {
        nuevo_escritor = escritor_hallado;
        cout << "Escritor existente\n" << endl;
    }
    else{
        nacionalidad = printer.pedir_nacionalidad();
        nacimiento = printer.pedir_nacimiento();
        fallecimiento = printer.pedir_fallecimiento();

        nuevo_escritor = new Escritor(nombre, nacionalidad, nacimiento, fallecimiento);
        almacenar_escritor(nuevo_escritor);
    }

    return nuevo_escritor;
}

void Menu::almacenar_escritor(Escritor* escritor){
    lista_escritores->alta(escritor);
}

void Menu::modificar_fallecimiento(){

    string nombre_escritor = printer.pedir_nombre();
    Escritor* escritor_a_modificar = rastrear_escritor(nombre_escritor);
    int nuevo_fallecimiento = printer.pedir_nuevo_fallecimiento();

    if (escritor_a_modificar == nullptr)
        cout << ROJO << "\nNo se encuentra el escritor que desea modificar, intente nuevamente.\n" << endl;

    else if (nuevo_fallecimiento == -1 || nuevo_fallecimiento > escritor_a_modificar->obtener_anio_nacimiento()){
        escritor_a_modificar -> modificar_fallecimiento(nuevo_fallecimiento);
        cout << AZUL << "\nFallecimiento actualizado con éxito!\n" << endl;
    }
    else
        cout << ROJO <<  "\nEl año de fallecimiento ingresado es inválido, intente nuevamente.\n" << endl;
}

Escritor* Menu::rastrear_escritor(string nombre_escritor){

    int indice = 1;
    Escritor* escritor_buscado = nullptr;

    lista_escritores->inicializar();
    while(lista_escritores->hay_actual() && lista_escritores -> consultar(indice) -> obtener_nombre() != nombre_escritor){
        indice++;
        lista_escritores->siguiente();
    }
    if (lista_escritores->hay_actual())
        escritor_buscado = lista_escritores -> consultar(indice);

    return escritor_buscado;
}


void Menu::listar_escritores(){
    int contador = 1;
    lista_escritores->inicializar();

    while(lista_escritores->hay_actual()){
        cout << VERDE << "Escritor numero: " << contador << endl;
        Escritor* escritor_actual = lista_escritores->obtener_dato_cursor();
        escritor_actual -> mostrar_escritor();

        lista_escritores->siguiente();
        contador++;
    }
}

void Menu::sortear_lectura(){
    lista_lecturas->sortear();
}

void Menu::listar_lecturas(){
    lista_lecturas->listar();
}

void Menu::listar_lecturas_entre_anios(){
    int desde = printer.pedir_anio_desde();
    int hasta = printer.pedir_anio_hasta();
    lista_lecturas->listar_entre_anios(desde, hasta);
}

void Menu::listar_por_escritor(){
    string nombre_escritor = printer.pedir_nombre();
    lista_lecturas->listar_por_escritor(nombre_escritor);
}

void Menu::listar_novelas_de_genero(){
    generos genero = printer.pedir_genero();
    lista_lecturas->listar_por_genero(genero);
}

void Menu::proximas_lecturas(){

    if (!cola_lecturas){
        cola_de_lecturas();
    }

    if (!cola_lecturas->vacia()){
        marcar_como_leida();
    }
    else
        cout << ROJO << "\n\t\t Ya no quedan lecturas por ser leidas: " << endl;
}

void Menu::cola_de_lecturas(){
    Lista<Lectura*>* lecturas_ordenadas = lista_lecturas->ordenar_por_minutos();
    cola_lecturas = new Cola<Lectura*>;

    lecturas_ordenadas->inicializar();
    while(lecturas_ordenadas->hay_actual()){
        Lectura* lectura_actual = lecturas_ordenadas->obtener_dato_cursor();

        cola_lecturas->encolar(lectura_actual);
        lecturas_ordenadas->siguiente();
    }
    delete lecturas_ordenadas;      // Elimino la lista aux creada con el new, no los objetos de adentro ???
}


void Menu::actualizar_cola(Lectura* lectura_eliminada){
    Cola<Lectura*>* cola_actualizada = new Cola<Lectura*>;

    while(!cola_lecturas->vacia()){
        Lectura* lectura_actual = cola_lecturas->desencolar();
        if (lectura_actual != lectura_eliminada)
            cola_actualizada -> encolar(lectura_actual);
    }
    delete cola_lecturas;       // ELIMINAR DESTRUCTOR DE COLA
    this->cola_lecturas = cola_actualizada;

    /*cout << "hola 1" << endl;
    Lectura* primera_lectura = cola_lecturas->desencolar();
    if (primera_lectura != lectura_eliminada)
        cout << "hola 2" << endl;
        cola_lecturas->encolar(primera_lectura);

    Lectura* lectura_actual = cola_lecturas->desencolar();
    cout << "hola 3" << endl;
    while(lectura_actual != primera_lectura){
        cout << "hola 4" << endl;
        if (lectura_actual != lectura_eliminada)
            cola_lecturas->encolar(lectura_actual);
        lectura_actual = cola_lecturas->desencolar();
    }*/
}

void Menu::marcar_como_leida(){
    char opcion;

    cout << VERDE << "Proxima lectura: " << endl;
    Lectura* prox_lectura = cola_lecturas->consultar();
    prox_lectura -> mostrar_lectura();

    opcion = printer.opcion_leer();

    if (tolower(opcion) == 's') {
        if (cola_lecturas->vacia())
            cout << ROJO << "\nYa no quedan lecturas por ser leidas.\n" << endl;
        else {
            cola_lecturas->desencolar();
            cout << AZUL << "\nLectura leida con éxito.\n" << endl;
        }
    }

    else if(tolower(opcion) == 'n')
        cout << AZUL << "\nElija otra opcion del menu.\n" << endl;

    else
        cout << ROJO << "\nIngreso inválido, intente nuevamente.\n" << endl;
}
