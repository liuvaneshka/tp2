#include "Menu.h"
#include "Parser.h"

Menu::Menu(){
    Parser parser;
    Lista <Escritor*> *lista_escritores = new Lista<Escritor*>;
    Lista <Lectura*> *lista_lecturas = new Lista<Lectura*>;
    cola_lecturas = nullptr;

    this->lista_escritores = parser.procesar_escritor(ARCHIVO_ESCRITORES, lista_escritores);
    this->lista_lecturas = parser.procesar_lectura(ARCHIVO_LECTURAS, lista_lecturas, lista_escritores);

    srand( (unsigned int) time(0));
}

Menu::~Menu(){}

void Menu::mostrar_menu(){
    cout << endl;
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
        cout << AMARILLO << i+1 << ". " << opciones[i]  << endl;
    }
}

void Menu::elegir_opcion(){
    string opcion;
    cout <<  VIOLETA << "\n\t\tIngresar opcion: ";
    cin >> opcion;
    this->opcion = atoi(opcion.c_str());
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
            liberar_memoria();
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
    almacenar_lectura(nueva_lectura);

    cout << "\nLectura creada: " << endl;
    nueva_lectura->mostrar_lectura();
}

Lectura* Menu::crear_lectura(){
    string titulo;
    int anio, minutos, tipo;
    Lectura* nueva_lectura = nullptr;
    Escritor* escritor_lectura = nullptr;

    cout << NEGRO <<"Ingrese el título de la lectura: ";
    cin.ignore();
    getline(cin, titulo);

    cout << NEGRO << "Ingrese el anio de publicacion de la lectura: ";
    cin >> anio;

    cout << "Ingrese minutos promedio de lectura: ";
    cin >> minutos;

    escritor_lectura = crear_escritor();

    cout << NEGRO << "Ingrese el numero de la lectura que deseas crear ";
    cout << AMARILLO << "(1. POEMA / 2. CUENTO / 3. NOVELA): ";
    cin >> tipo;

    switch(tipo) {

        case 1:{
            int versos;
            cout << VERDE << "Ingrese la cantidad de versos del poema: ";
            cin >> versos;
            nueva_lectura = new Poema(titulo, escritor_lectura, anio, minutos, versos);
            break;
        }

        case 2:{
            string libro;
            cout << "Ingrese el titulo del libro: ";
            cin.ignore();
            getline(cin, libro);
            nueva_lectura = new Cuento(titulo, escritor_lectura, anio, minutos, libro);
            break;
        }

        case 3:{
            int genero;
            cout << "Ingrese el género de la novela" << endl;
            cout << AMARILLO << "(1.DRAMA / 2.COMEDIA / 3.FICCION / 4.SUSPENSO / 5.TERROR / 6.ROMANTICA / 7.HISTORICA): "<< endl;
            cin >> genero;
            generos genero_numerado = (generos) genero;

            if(genero_numerado == HISTORICA){
                string tema;
                cout << NEGRO << "Ingrese el tema de la novela histórica: ";
                cin.ignore();
                getline(cin, tema);
                nueva_lectura = new Novela_historica(titulo, escritor_lectura, anio, minutos, tema);
            }
            else
                nueva_lectura = new Novela(titulo, escritor_lectura, anio, minutos, genero_numerado);
            break;
        }

        default:
            cout << ROJO << "\nDatos inválidos, intente nuevamente.\n" << endl;
    }
    return nueva_lectura;
}

void Menu::almacenar_lectura(Lectura* lectura){
    int posicion_correcta = obtener_posicion_segun_anio(lectura);
    lista_lecturas->alta(lectura, posicion_correcta);
}

int Menu::obtener_posicion_segun_anio(Lectura* lectura){
    int indice = 1;

    if (!lista_lecturas->vacia()){
        lista_lecturas->inicializar();

        while(lista_lecturas->hay_actual() && lectura->comparar_lecturas(lista_lecturas->consultar(indice)) != -1){
            indice++;
            lista_lecturas->siguiente();
        }
    }
    return indice;
}

void Menu::quitar_lectura(){

    if (lista_lecturas->vacia())
        cout << ROJO << "\n No se puede eliminar ninguna lectura, la lista de lecturas está vacía\n" << endl;
    else {
        string titulo_lectura = pedir_nombre_lectura();
        int indice_a_eliminar = rastrear_lectura(titulo_lectura);

        if (indice_a_eliminar == DESCONOCIDO)
            cout << ROJO << "\nLa lectura que desea eliminar no existe, intente nuevamente.\n" << endl;
        else{
            Lectura* eliminar = lista_lecturas->consultar(indice_a_eliminar);
            if (cola_lecturas && !cola_lecturas->vacia())
                actualizar_cola(eliminar);
            delete eliminar;                                     // Será correcto?? Intento eliminar el objeto Lectura que ingresó el usuario
            lista_lecturas->baja(indice_a_eliminar);                 // Acá al dar de baja se elimina el Nodo
            cout << AZUL << "\nLectura eliminada con éxito!\n" << endl;
        }
    }
}

string Menu::pedir_nombre_lectura(){
    string titulo_lectura;
    cout << ROJO << "Ingrese el titulo de la lectura que desea eliminar: ";
    cin.ignore();
    getline(cin, titulo_lectura);
    return titulo_lectura;
}

int Menu::rastrear_lectura(string titulo_lectura){

    int indice = 1, indice_correspondiente = -1;

    lista_lecturas->inicializar();
    while(lista_lecturas->hay_actual() && lista_lecturas->consultar(indice)->obtener_titulo() != titulo_lectura){
        indice++;
        lista_lecturas->siguiente();
    }

    if(lista_lecturas->hay_actual())
        indice_correspondiente = indice;

    return indice_correspondiente;
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

    cout << AZUL << "Ingrese el nombre del escritor: ";
    cin.ignore();
    getline(cin, nombre);

    escritor_hallado = rastrear_escritor(nombre);

    if (escritor_hallado) {      // Para usar al momento de crear una lectura, si el escritor ya se encunetra creado
        nuevo_escritor = escritor_hallado;
        cout << "Escritor existente " << endl;
    }
    else{
        cout << AZUL << "Ingrese la nacionalidad" << endl;
        cout << VERDE << " (si es desconocida, ingrese ¿?): ";
        cin >> nacionalidad;

        cout << AZUL << "Ingrese el año de nacimiento" << endl;
        cout << VERDE << " (si es desconocida, ingrese -1): ";
        cin >> nacimiento;

        cout << AZUL << "Ingrese el año de fallecimiento " << endl;
        cout << VERDE << "(si es desconocida o continua vivo, ingerse -1): ";
        cin >> fallecimiento;

        nuevo_escritor = new Escritor(nombre, nacionalidad, nacimiento, fallecimiento);
        almacenar_escritor(nuevo_escritor);
        cout << "almaceno escritor en crear escritor " << endl;
    }

    return nuevo_escritor;
}

void Menu::almacenar_escritor(Escritor* escritor){
    lista_escritores->alta(escritor);
}

void Menu::modificar_fallecimiento(){

    string nombre_escritor = pedir_nombre_escritor();
    Escritor* escritor_a_modificar = rastrear_escritor(nombre_escritor);
    int nuevo_fallecimiento = pedir_nuevo_fallecimiento();

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

string Menu::pedir_nombre_escritor(){
    string nombre_escritor;

    cout << VERDE << "Ingrese el nombre del escritor: ";
    cin.ignore();
    getline(cin, nombre_escritor);
    return nombre_escritor;
}

int Menu::pedir_nuevo_fallecimiento(){
    int nuevo_fallecimiento;

    cout << VERDE << "Ingrese el nuevo año de fallecimiento: ";
    cin >> nuevo_fallecimiento;
    return nuevo_fallecimiento;
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
    int num_random = rand() % lista_lecturas->obtener_tamanio() + 1;
    cout << VIOLETA << "numero random elegido: " << num_random << endl;

    Lectura* lectura_random = lista_lecturas->consultar(num_random);

    cout << AZUL << "Lectura sorteada: " << endl;
    lectura_random->mostrar_lectura();
}

void Menu::listar_lecturas(){
    int contador = 1;
    lista_lecturas->inicializar();

    while(lista_lecturas->hay_actual()){
        cout << VERDE << "Lectura numero: "<< contador << endl;
        Lectura* lectura_actual = lista_lecturas->obtener_dato_cursor();
        lectura_actual->mostrar_lectura();

        lista_lecturas->siguiente();
        contador++;
    }
}

void Menu::listar_lecturas_entre_anios(){
    int desde = pedir_anio_desde();
    int hasta = pedir_anio_hasta();
    int contador_lecturas = 0;

    if (desde > hasta)
        cout << ROJO << "\nAños inválidos, intente nuevamente\n" << endl;

    else{
        lista_lecturas->inicializar();
        while(lista_lecturas->hay_actual()){
            Lectura* lectura_actual = lista_lecturas->obtener_dato_cursor();
            int anio_lectura_actual = lectura_actual->obtener_anio();

            if (anio_lectura_actual >= desde && anio_lectura_actual <= hasta){
                lectura_actual->mostrar_lectura();
                contador_lecturas++;
             }

            lista_lecturas->siguiente();
        }
    }

    if(contador_lecturas == 0)
        cout << ROJO << "\nNo hay lecturas entre los anios ingresados\n" << endl;
}

int Menu::pedir_anio_desde(){
    int desde;
    cout << VERDE << "Ingrese el año DESDE el cual desea listar las lecturas: ";
    cin >> desde;
    return desde;
}

int Menu::pedir_anio_hasta(){
    int hasta;
    cout << VERDE << "Ingrese el año HASTA el cual desea listar las lecturas: ";
    cin >> hasta;
    cout << '\n';

    return hasta;
}

void Menu::listar_por_escritor(){
    string nombre_escritor = pedir_nombre_escritor();
    bool hay_lecturas = hay_lecturas_de_escritor(nombre_escritor);

    if (!hay_lecturas)
        cout << ROJO << "\n \t **** No existen lecturas escritas por el Escritor ingresado, intente nuevamente\n" << endl;
}

bool Menu::hay_lecturas_de_escritor(string nombre_escritor){
    bool hay_lecturas = false;

    lista_lecturas->inicializar();
    while(lista_lecturas->hay_actual()){
        Lectura* lectura_actual = lista_lecturas->obtener_dato_cursor();
        Escritor* escritor_actual = lectura_actual->obtener_escritor();

        if (escritor_actual != nullptr && escritor_actual->obtener_nombre() == nombre_escritor){
            hay_lecturas = true;
            cout << '\n';
            lectura_actual->mostrar_lectura();
        }
        lista_lecturas->siguiente();
    }
    return hay_lecturas;
}

void Menu::listar_novelas_de_genero(){
    generos genero = pedir_genero();

    lista_lecturas->inicializar();
    while(lista_lecturas->hay_actual()){
        Lectura* lectura_actual = lista_lecturas->obtener_dato_cursor();
        lectura_actual->imprimir_novela_genero(genero);
        lista_lecturas->siguiente();
    }
}

generos Menu::pedir_genero(){
    int genero;

    cout << VERDE << "Ingrese el genero de las novelas que desea listar" << endl;
    cout << AMARILLO << " (1.DRAMA / 2.COMEDIA / 3.FICCION / 4.SUSPENSO / 5.TERROR / 6.ROMANTICA / 7.HISTORICA): ";
    cin >> genero;
    cout << '\n';

    return (generos) genero;
}

void Menu::proximas_lecturas(){

    if (!cola_lecturas){
        cout << "***** no hay colas: " << endl;
        cola_de_lecturas();
    }

    if (!cola_lecturas->vacia()){
        marcar_como_leida();
    }
    else
        cout << ROJO << "\n\t\t Ya no quedan lecturas por ser leidas: " << endl;
}

void Menu::cola_de_lecturas(){
    Lista<Lectura*>* lecturas_ordenadas = ordenar_por_minutos();
    cola_lecturas = new Cola<Lectura*>;

    lecturas_ordenadas->inicializar();
    while(lecturas_ordenadas->hay_actual()){
        Lectura* lectura_actual = lecturas_ordenadas->obtener_dato_cursor();

        cola_lecturas->encolar(lectura_actual);
        lecturas_ordenadas->siguiente();
    }
    delete lecturas_ordenadas;      // Elimino la lista aux creada con el new, no los objetos de adentro
}

Lista<Lectura*>* Menu::ordenar_por_minutos(){
    Lista<Lectura*>* lecturas_ordenadas = new Lista<Lectura*>;
    int posicion_correcta;

    lista_lecturas->inicializar();
    while(lista_lecturas->hay_actual()){
        Lectura* lectura_actual = lista_lecturas->obtener_dato_cursor();
        posicion_correcta = obtener_posicion_segun_minutos(lecturas_ordenadas, lectura_actual);

        lecturas_ordenadas->alta(lectura_actual, posicion_correcta);
        lista_lecturas->siguiente();
    }
    return lecturas_ordenadas;
}

int Menu::obtener_posicion_segun_minutos(Lista<Lectura*>* lecturas_ordenadas, Lectura* lectura){

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

void Menu::actualizar_cola(Lectura* lectura_eliminada){
    Cola<Lectura*>* cola_actualizada = new Cola<Lectura*>;

    while(!cola_lecturas->vacia()){
        Lectura* lectura_actual = cola_lecturas->desencolar();
        if (lectura_actual != lectura_eliminada)
            cola_actualizada -> encolar(lectura_actual);
    }
    delete cola_lecturas;
    this->cola_lecturas = cola_actualizada;
}

void Menu::marcar_como_leida(){
    char opcion;

    cout << VERDE << "Proxima lectura: " << endl;
    Lectura* prox_lectura = cola_lecturas->consultar();
    prox_lectura -> mostrar_lectura();

    cout << AZUL << "\nDesea marcar la lectura de la cola como leida?" << endl;
    cout << VERDE << " (S.Si / N.No): ";
    cin >> opcion;

    if (tolower(opcion) == 's'){
        if (cola_lecturas->vacia())
            cout << ROJO << "\nYa no quedan lecturas por ser leidas.\n" << endl;
        else {
            cola_lecturas->desencolar();
            cout << AZUL << "\nLectura leida con éxito.\n" << endl;
        }
    }
    else
        cout << ROJO << "\nIngreso inválido, intente nuevamente.\n" << endl;
}

void Menu::liberar_escritores(){
    while(!lista_escritores->vacia()){
        Escritor* eliminar = lista_escritores->consultar(1);
        delete eliminar;          // Elimino objeto Escritor

        lista_escritores->baja(1);   // Se elimina el Nodo
    }
    delete lista_escritores;
}

void Menu::liberar_lecturas(){
    while(!lista_lecturas->vacia()){
        Lectura* eliminar = lista_lecturas->consultar(1);
        delete eliminar;          // Elimino objeto Lectura

        lista_lecturas->baja(1);   // Se elimina el Nodo
    }
    delete lista_lecturas;
}

void Menu::liberar_cola(){
    // Para este punto los obejtos de la cola ya está liberados
    if(cola_lecturas)
        delete cola_lecturas;
    // Si nunca se eligio la opcion 11, nunca se crea la cola y por ende no hay que eliminarla
}

void Menu::liberar_listas(){
    liberar_escritores();
    liberar_lecturas();
}

void Menu::liberar_memoria(){
    liberar_listas();
    liberar_cola();
}
