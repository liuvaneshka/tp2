#include "menu.h"
#include "parser.h"

// 1) ANALIZAR EN QUE PARTES Y COMO LIBERAR LA MEMORIA DURANTE LA EJECUCION DEL PROGRAMA
    // !- OJO AL DAR DE BAJA UNA LECTURA -> ELIMINO EL NODO PERO NO EL OBEJETO AL QUE APUNTA EL PUNTERO EN DICHO NODO
        // Verificar que se elimine la Lectura, pero no el Escritor del puntero que posee como atributo
        // Verificar que luego se elimine la memoria del Nodo en donde se encontraba el puntero a dicha Lectura

    // !- RECORRER LISTA DE ESCRITORES, ELIMINANDO LA MEMORIA PEDIDA PARA CADA OBJETO
        // Verificar primero eliminar los objetos Escritor y luego dar de baja en la lista, dado que ahi se eliminan los Nodos
    // !- RECORRER LISTA DE LECTURAS, ELIMINANDO LA MEMORIA PEDIDA PARA CADA OBJETO
        // Verificar primero eliminar los objetos Lectura y luego dar de baja en la lista, dado que ahi se eliminan los nodos

    // !- LIBERAR LA MEMORIA DE LA LISTA_ESCRITORES
    // !- LIBERAR LA MEMORIA DE LA LISTA_LECTURAS
        // Se usa o no el new??? En este implementacion, no uso new para listas pero si para la cola

    // !- LIBERAR COLA DE LECTURAS
        //Para este punto ya se eliminaron los objetos Lectura, queda solo liberar la memoria de los nodos y la memoria pedida para la Cola vacía

// 3) En cola_lecturas -> Boceto de implementacion (no terminado)
/*
    this->cola_lecturas = new Cola();
    int minimo = 0;
    Lectura* primera_lectura, *lectura_comparacion;

    lista_lecturas.inicializar();
    while(lista_lecturas.hay_siguiente()){
        Lectura* lectura_actual = lista_lecturas.obtener_dato_cursor();

        if (!cola_lecturas.vacia()){
            if (lectura_actual->obtener_minutos < minimo)
                primera_lectura = lectura_actual;

            else
                primera_lectura = cola_lecturas.consultar();

            Lectura* lectura_comparacion = cola_lecturas.consultar()

            do {
                Lectura* desencolada = cola_lecturas.desencolar();
                cola_lecturas.encolar(desencolada);
                lectura_comparacion = cola_lecturas.consultar();
            } while (lectura_actual > lectura_comparacion.consultar() && lectura_comparacion != primera_lectura);

            cola_lecturas.encolar(lectura_actual)

            while(cola_lecturas.consultar() != primera_lectura)
                cola_lecturas.encolar(cola_lecturas.desencolar())
        }
        else
            cola_lecturas.encolar(lectura_actual)
            minimo = lectura_actual -> obtener_minutos();
}
*/

// 4) Repeticion de 3 metodos que ya escribimos en parser... Dudo que haya solución :(

// 5) Modularizacion -> se podrñia modularizar al crear objetos pero a costa de tener métodos con muchos parámetros

// 6) Implementacion de sortear_lectura correcta ?
//      - Tener en cuenta el time.h para que vaya variando el numero random
//      - Se muestra por pantalla la letura que tocó -> luego qué se hace ???

// 7) Para listar novelas por género -> Como sé cuales ponteros a Lectura son a un tipo de objeto Novela para poder llamar a obtener_genero() ??
//    Habrá que tener un método en clase Lectura que se encargue ??? Raaro


Menu::Menu(){
    Parser parser;
    Lista <Escritor*> lista_escritores;
    Lista <Lectura*> lista_lecturas;

    this->lista_escritores =  parser.procesar_escritor(ARCHIVO_ESCRITORES, lista_escritores);
    this->lista_lecturas = parser.procesar_lectura(ARCHIVO_LECTURAS, lista_lecturas, lista_escritores);
    this->cola_lecturas = nullptr;
    srand( (unsigned int) time(0));             // Para sortear la lectura -> Se hace asi?
}

Menu::~Menu(){}

void Menu::mostrar_menu(){

    string opciones [] = {"Agregar una nueva lectura",
                          "Quitar lectura",
                          "Agregar un escritor",
                          "Actualizar fallecimiento autor",
                          "Listar los escritores",
                          "Sortear una lectura",
                          "Listar lecturas",
                          "Listar lecturas por anio",
                          "Listar lecturas por escritor",
                          "Listar Novelas por genero",
                          "Listar proximas lecturas",
                          "Salir"};

    int tamanio = sizeof(opciones)/sizeof(opciones[0]);

    for(int i = 0; i < tamanio; i++){
        cout << i+1 << ". " << opciones[i]  << endl;
    }
}

void Menu::elegir_opcion(){
    string opcion;
    cout << "\n\tIngresar opcion: " << endl;
    cin >> opcion;
    this->opcion = atoi(opcion.c_str());
}

bool Menu::selector_menu(){

    bool estado;
    switch (this->opcion){

        case 1:
            cout << "caso 1 "<< endl;
            agregar_lectura();
            estado = true;
            break;

        case 2:
            cout << "caso 2" << endl;
            quitar_lectura();
            estado = true;
            break;

        case 3:
            cout << "caso 3" << endl;
            agregar_escritor();
            estado = true;
            break;

        case 4:
            cout << "caso 4" << endl;
            modificar_fallecimiento();
            estado = true;
            break;

        case 5:
            cout << "caso 5" << endl;
            listar_escritores();
            estado = true;
            break;

        case 6:
            cout << "caso 6" << endl;
            sortear_lectura();
            estado = true;
            break;

        case 7:
            cout << "caso 7" << endl;
            listar_lecturas();
            estado = true;
            break;

        case 8:
            cout << "caso 8" << endl;
            listar_lecturas_entre_anios();
            estado = true;
            break;

        case 9:
            cout << "caso 9" << endl;
            listar_lecturas_de_escritor();
            estado = true;
            break;

        case 10:
            cout << "caso 10" << endl;
            listar_novelas_de_genero();
            estado = true;
            break;

        case 11:
            cout << "caso 11" << endl;
            proximas_lecturas();
            estado = true;
            break;

        case 12:
            cout << "\n\t\t\tCordial despedida" << endl;
            liberar_memoria();
            estado = false;
            break;

        default:
            cout << "\n\t\t\tError elige otra opcion valida" << endl;
            estado = true;
    }
    return estado;
}

void Menu::agregar_lectura(){
    Lectura* nueva_lectura = crear_lectura();
    almacenar_lectura(nueva_lectura);
    nueva_lectura->mostrar_lectura();
}

Lectura* Menu::crear_lectura(){
    string titulo;
    int anio, minutos, tipo;
    Lectura* nueva_lectura = nullptr;
    Escritor* escritor_lectura = nullptr;

    cout << "Ingrese el numero de la lectura que deseas crear (1. POEMA / 2. CUENTO / 3. NOVELA): ";
    cin >> tipo;

    cout << "Ingrese el título de la lectura: ";
    cin >> titulo;

    cout << "Ingrese el anio de publicacion de la lectura: ";
    cin >> anio;

    cout << "Ingrese minutos promedio de lectura: ";
    cin >> minutos;

    escritor_lectura = crear_escritor();

    switch(tipo) {

        case 1:{
            int versos;
            cout << "Ingrese la cantidad de versos del poema: ";
            cin >> versos;
            nueva_lectura = new Poema(titulo, escritor_lectura, anio, minutos, versos);
            break;
        }

        case 2:{
            string libro;
            cout << "Ingrese el titulo del libro: ";
            cin >> libro;
            nueva_lectura = new Cuento(titulo, escritor_lectura, anio, minutos, libro);
            break;
        }

        case 3:{
            int genero;
            cout << "Ingrese el género de la novela (1.DRAMA / 2.COMEDIA / 3.FICCION / 4.SUSPENSO / 5.TERROR / 6.ROMANTICA / 7.HISTORICA): ";
            cin >> genero;
            generos genero_numerado = (generos) genero;

            if(genero_numerado == HISTORICA){
                string tema;
                cout << "Ingrese el tema de la novela histórica: ";
                cin >> tema;
                nueva_lectura = new Novela_historica(titulo, escritor_lectura, anio, minutos, tema);
            }
            else
                nueva_lectura = new Novela(titulo, escritor_lectura, anio, minutos, genero_numerado);
            break;
        }

        default:
            cout << "Datos inválidos, intente nuevamente." << endl;
    }
    return nueva_lectura;
}

//MISMOS DOS MÉTODOS QUE EL PARSER
void Menu::almacenar_lectura(Lectura* lectura){
    int posicion_correcta = obtener_posicion_correcta(lectura);
    lista_lecturas.alta(lectura, posicion_correcta);
}


int Menu::obtener_posicion_correcta(Lectura* lectura){
    int indice = 1;
    lista_lecturas.inicializar();
    while(lista_lecturas.hay_siguiente() && lectura->comparar_lecturas(lista_lecturas.consultar(indice)) != -1){
        indice++;
        lista_lecturas.siguiente();
    }
    return indice;
}

void Menu::quitar_lectura(){
    string titulo_lectura = pedir_nombre_lectura();
    int indice_a_eliminar = rastrear_lectura(titulo_lectura);

    if (indice_a_eliminar == DESCONOCIDO)
        cout << "La lectura que desea eliminar no existe, intente nuevamente." << endl;
    else{
        Lectura* eliminar = lista_lecturas.consultar(indice_a_eliminar);
        delete eliminar;                                     // Será correcto?? Intento eliminar el objeto Lectura que ingresó el usuario
        lista_lecturas.baja(indice_a_eliminar);                 // Acá al dar de baja se elimina el Nodo
        cout << "Lectura eliminada con éxito!" << endl;
    }
}

string Menu::pedir_nombre_lectura(){
    string titulo_lectura;
    cout << "Ingrese el titulo de la lectura que desea eliminar: ";
    cin >> titulo_lectura;
    return titulo_lectura;
}

int Menu::rastrear_lectura(string titulo_lectura){

    int indice = 1;
    lista_lecturas.inicializar();

    while(lista_lecturas.hay_siguiente() && lista_lecturas.consultar(indice)->obtener_titulo() != titulo_lectura)
        lista_lecturas.siguiente();

    if(!lista_lecturas.hay_siguiente())
        indice = -1;

    return indice;
}

void Menu::agregar_escritor(){
    Escritor* nuevo_escritor = crear_escritor();
    almacenar_escritor(nuevo_escritor);
    nuevo_escritor->mostrar_escritor();
}

Escritor* Menu::crear_escritor(){
    string nombre, nacionalidad;
    int nacimiento, fallecimiento;

    cout << "Ingrese el nombre del escritor que desea agregar: ";
    cin >> nombre;

    cout << "Ingrese la nacionalidad (si es desconocida, ingrese ¿?): ";
    cin >> nacionalidad;

    cout << "Ingrese el año de nacimiento (si es desconocida, ingrese -1): ";
    cin >> nacimiento;

    cout << "Ingrese el año de fallecimiento (si es desconocida o continua vivo, ingerse -1): ";
    cin >> fallecimiento;

    Escritor* nuevo_escritor = new Escritor(nombre, nacionalidad, nacimiento, fallecimiento);
    return nuevo_escritor;
}

// MISMO METODO DEL PARSER
void Menu::almacenar_escritor(Escritor* escritor){
    lista_escritores.alta_al_final(escritor);
}

void Menu::modificar_fallecimiento(){
    /*
    string nombre_escritor = pedir_nombre_escritor();
    Escritor* escritor_a_modificar = rastrear_escritor(nombre_escritor);
    int nuevo_fallecimiento = pedir_nuevo_fallecimiento();

    if (nuevo_fallecimiento == -1 || nuevo_fallecimiento > escritor_a_modificar->obtener_anio_nacimiento())
        escritor_a_modificar -> modificar_fallecimiento(nuevo_fallecimiento);
    else
        cout << "El año de fallecimiento ingresado es iunválido, intente nuevamente." << endl;
    */
    cout << "ll" << endl;
}

string Menu::pedir_nombre_escritor(){
    string nombre_escritor;

    cout << "Ingrese el nombre del escritor: ";
    cin >> nombre_escritor;
    return nombre_escritor;
}

int Menu::pedir_nuevo_fallecimiento(){
    int nuevo_fallecimiento;

    cout << "Ingrese el nuevo año de fallecimiento: ";
    cin >> nuevo_fallecimiento;
    return nuevo_fallecimiento;
}

void Menu::listar_escritores(){

    lista_escritores.inicializar();
    while(lista_escritores.hay_siguiente()){
        Escritor* escritor_actual = lista_escritores.obtener_dato_cursor();
        escritor_actual->mostrar_escritor();
        lista_escritores.siguiente();
    }
}

void Menu::sortear_lectura(){
    int cant_maxima = lista_lecturas.obtener_tamanio() + 1;
    int num_random = rand() % cant_maxima + 1;

    Lectura* lectura_random = lista_lecturas.consultar(num_random);

    cout << "Lectura sorteada:" << endl;
    lectura_random->mostrar_lectura();
}

void Menu::listar_lecturas(){

    lista_lecturas.inicializar();
    while(lista_lecturas.hay_siguiente()){
        Lectura* lectura_actual = lista_lecturas.obtener_dato_cursor();
        imprimir_lectura(lectura_actual);
        lista_lecturas.siguiente();
    }
}

void Menu::listar_lecturas_entre_anios(){
    int desde = pedir_anio_desde();
    int hasta = pedir_anio_hasta();

    lista_lecturas.inicializar();
    while(lista_lecturas.hay_siguiente()){
        Lectura* lectura_actual = lista_lecturas.obtener_dato_cursor();
        int anio_lectura_actual = lectura_actual->obtener_anio();

        if (anio_lectura_actual >= desde && anio_lectura_actual <= hasta)
            imprimir_lectura(lectura_actual);

        lista_lecturas.siguiente();
    }
}

void Menu::imprimir_lectura(Lectura* lectura){
    lectura->mostrar_lectura();
}

int Menu::pedir_anio_desde(){
    int desde;
    cout << "Ingrese el año DESDE el cual desea listar las lecturas: ";
    cin >> desde;
    return desde;
}

int Menu::pedir_anio_hasta(){
    int hasta;
    cout << "Ingrese el año HASTA el cual desea listar las lecturas: ";
    cin >> hasta;
    return hasta;
}

void Menu::listar_lecturas_de_escritor(){
    string nombre_escritor = pedir_nombre_escritor();

    lista_lecturas.inicializar();
    while(lista_lecturas.hay_siguiente()){
        Lectura* lectura_actual = lista_lecturas.obtener_dato_cursor();
        Escritor* escritor_actual = lectura_actual->obtener_escritor();

        if (escritor_actual != nullptr && escritor_actual->obtener_nombre() == nombre_escritor)
            imprimir_lectura(lectura_actual);

        lista_lecturas.siguiente();
    }
}

void Menu::listar_novelas_de_genero(){
    /*
    generos genero = pedir_genero();

    lista_lecturas.inicializar();
    while(lista_lecturas.hay_siguiente()){
        Lectura* lectura_actual = lista_lecturas.obtener_dato_cursor();

        if(lectura_actual == Novela && lectura_actual->obtener_genero() == genero)                    // Cómo se puede hacer esto?
            imprimir_lectura(lectura_actual);
        lista_lecturas.siguiente();
    }
    */
    cout << endl;
}

generos Menu::pedir_genero(){
    int genero;

    cout << "Ingrese el genero de las novelas que desea listar (1.DRAMA / 2.COMEDIA / 3.FICCION / 4.SUSPENSO / 5.TERROR / 6.ROMANTICA / 7.HISTORICA): ";
    cin >> genero;

    return (generos) genero;
}

void Menu::proximas_lecturas(){
    if (!cola_lecturas)
        cola_de_lecturas();

    marcar_como_leida();
}

void Menu::cola_de_lecturas(){      // Como sobrecargo el de comparar lecturas si reciben lo mismo?
    this->cola_lecturas = new Cola();
    //Almaceno en orden por minutos las lecturas
}

void Menu::marcar_como_leida(){
    char opcion;

    cout << "Proxima lectura: ";
    Lectura* prox_lectura = cola_lecturas->consultar();
    prox_lectura -> mostrar_lectura();

    cout << "Desea marcar la lectura de la cola como leida? (S.Si / N.No): ";
    cin >> opcion;

    if (opcion == 's' || opcion == 'S'){
        cola_lecturas->desencolar();
        cout << "Lectura leida" << endl;
    }
}

void Menu::liberar_escritores(){
    while(!lista_escritores.vacia()){
        Escritor* eliminar = lista_escritores.consultar(1);
        delete eliminar;          // Elimino objeto Escritor
        lista_escritores.baja(1);   // Se elimina el Nodo
    }
    // Si creo la lista con new...
    // delete lista_escritores;
}

void Menu::liberar_lecturas(){
    while(!lista_lecturas.vacia()){
        Lectura* eliminar = lista_lecturas.consultar(1);
        delete (eliminar);          // Elimino objeto Lectura
        lista_lecturas.baja(1);   // Se elimina el Nodo
    }
    // Si creo la lista con new...
    // delete lista_lecturas;
}

void Menu::liberar_cola(){
    // Para este punto los obejtos de la cola ya está, liberados, queda liberar nodos
    while(!cola_lecturas->vacia())
        cola_lecturas->desencolar();

    // Como cree la Cola con new
    delete cola_lecturas;
}

void Menu::liberar_listas(){
    liberar_escritores();
    liberar_lecturas();
}

void Menu::liberar_memoria(){
    liberar_listas();
    liberar_cola();
}
