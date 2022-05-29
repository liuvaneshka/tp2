#include "menu.h"
#include "parser.h"
#include <iostream>

// 1) CONSTRUCTOR DE MENU ???
// 2) CREO QUE UNA VEZ QUE AL FINAL DE CADA FUNCION, SE DEBE LLAMAR NUEVAMENTE A MOSTRAR_MENU()
// 3) HABRIA QUE VER DE MODULARIZAR LAS ITERACIONES DE LAS LISTAS QUE HAGO VARIAS ECES CON LEVES MODIFICACIONES
// 4) COMO CASTEO ALGO QUE INGRESA EL USUARIO A ALGO DE TIPO ENUMERADO ???
// 5) UNA VEZ QUE SOLUCIONEMOS EL CHAR DINAMICO DE TEMA, HAY QUE MODIFICARLO ACA TAMBIEN!
// 6) NO ENTIENDO EL ERROR DEL SWITCH(TIPO)
// 7) ANALIZAR EN QUE PARTES Y COMO LIBERAR LA MEMORIA DURANTE LA EJECUCION DEL PROGRAMA
// 8) UNA VEZ HECHO EL PUNTO ANTERIOR, AL MOMENTO DE QUE EL USUARTIO INGERSA LA OPCION DE SALIR HAY QUE LIBERAR:
    // !- RECORRER LISTA DE AUTORES, ELIMINANDO LA MEMORIA PEDIDA PARA CADA OBJETO
    // !- LIBERAR LA MEMORIA DE LA LISTA_ESCRITORES
    // !- RECORRER LISTA DE LECTURAS, ELIMINANDO LA MEMORIA PEDIDA PARA CADA OBJETO
    // !- LIBERAR LA MEMORIA DE LA LISTA_LECTURAS
    // !- LIBERAR PARSER Y ARCHIVO ???
    // * - FUNCION DE COLA DE LECTURAS, CUIDADO AL ELIMINARLA, NO QUEREMOS ELIMINAR LOS OBJETOS !!!
Menu::Menu(){
    this->lista_escritores =  lista_escritores.procesar_escritor(ARCHIVO_ESCRITORES,lista_escritores);
    this->lista_lecturas = lista_lecturas.procesar_lectura(ARCHIVO_LECTURAS, lista_lecturas, lista_escritores);
}

Menu::~Menu(){}

void Menu::mostrar_menu(){
    int tamanio = sizeof(OPCIONES)/sizeof(OPCIONES[0]); 

    for(int i = 0; i < tamanio; i++){
        cout << i+1 << ". " << OPCIONES[i]  << endl;
    }
    elegir_opcion();
    selector_menu();
}

void Menu::elegir_opcion() {
    string opcion;
    cout << "\n\tIngresar opcion: " << endl;
    cin >> opcion;
    this->opcion = atoi(opcion.c_str());
}

bool Menu::selector_menu(){

    bool estado;        

    switch (this->opcion) {

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
            cola_de_lecturas();
            estado = true;
            break;

        case 12:
            cout << "\n\t\t\tCordial despedida" << endl;        // HAY QUE LIBERAR TODA LA MEMORIA
            estado = false;
            break;

        default:
            cout << "\n\t\t\tError elige otra opcion valida" << endl;
            estado = true;

    }
    mostrar_menu();
    return estado;
}
void Menu::agregar_lectura(){
    Lectura* nueva_lectura = crear_lectura();
    almacenar_lectura(nueva_lectura);
    nueva_lectura->mostrar_lectura();   // muestro la lectura que se agregó
}

Lectura* Menu::crear_lectura(){     //Problemas con entradas por teclado y los enumerados!!! como casteo en estos casos ???
    string titulo, escritor;
    int anio, minutos, tipo;
    Lectura* nueva_lectura;
    Escritor* escritor_lectura;

    cout << "Ingrese el numero de la lectura que deseas crear (1. POEMA / 2. CUENTO / 3. NOVELA): ";
    cin >> tipo;

    cout << "Ingrese el título de la lectura: ";
    cin >> titulo;

    cout << "Ingrese el anio de publicacion de la lectura: ";
    cin >> anio;

    cout << "Ingrese minutos promedio de lectura: ";
    cin >> minutos;

    escritor_lectura = crear_escritor();

    // Podría modularizarse aún mas !!!
    switch(tipo) {      // Para el switch cree un nuevo enumerado

        case 1:
            int versos;
            cout << "Ingrese la cantidad de versos del poema: ";
            cin >> versos;
            nueva_lectura = new Poema(titulo, escritor_lectura, anio, minutos, versos);
            break;

        case 2:
            string libro;
            cout << "Ingrese el titulo del libro: ";
            cin >> libro;
            nueva_lectura = new Cuento(titulo, escritor_lectura, anio, minutos, libro);
            break;

        case 3:
            string genero;
            cout << "Ingrese el género de la novela (DRAMA / COMEDIA / FICCION / SUSPENSO / TERROR / ROMANTICA): ";
            cin >> genero;
            generos genero_numerado = obtener_genero(genero);

            if(genero_numerado == HISTORICA){
                string tema;    
                cout << "Ingrese el tema de la novela histórica: ";
                cin >> tema;
                nueva_lectura = new Novela_historica(titulo, escritor_lectura, anio, minutos, tema);
            }
            else
                nueva_lectura = new Novela(titulo, escritor_lectura, anio, minutos, genero_numerado);
            break;

        default:
            cout << "Datos inválidos, intente nuevamente." << endl;
    }

    return nueva_lectura;
}

void Menu::almacenar_lectura(Lectura* lectura){
    //Mismo método del parser :)
}

generos Menu::obtener_genero(string genero) {
    generos numero_genero;

    if (genero == "DRAMA")
        numero_genero = DRAMA;
    else if (genero == "COMEDIA")
        numero_genero = COMEDIA;
    else if (genero == "FICCION")
        numero_genero = FICCION;
    else if (genero == "SUSPENSO")
        numero_genero = SUSPENSO;
    else if (genero == "TERROR")
        numero_genero = TERROR;
    else if (genero == "ROMANTICA")
        numero_genero = ROMANTICA;
    else if (genero == "HISTORICA")
        numero_genero = HISTORICA;

    return numero_genero;
}

void Menu::quitar_lectura(){
    string titulo_lectura = pedir_nombre_lectura();
    int indice_a_eliminar = rastrear_lectura(titulo_lectura);

    if (indice_a_eliminar == DESCONOCIDO)
        cout << "La lectura que desea eliminar no existe, intente nuevamente." << endl;
    else{
        lista_lecturas.baja(indice_a_eliminar);        // Habria que liberar la memoria !!!! Donde ?
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
    int cant_lecturas = lista_lecturas.obtener_tamanio();

    while (indice < cant_lecturas && lista_lecturas.consultar(indice) -> obtener_titulo() != titulo_lectura)
        indice++;

    if (indice == cant_lecturas)
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

void Menu::almacenar_escritor(Escritor* escritor){
    // Mismo método del parser :)
}

void Menu::modificar_fallecimiento(){
    string nombre_escritor = pedir_nombre_escritor();
    Escritor* escritor_a_modificar = rastrear_escritor();
    int nuevo_fallecimiento = pedir_nuevo_fallecimiento();

    // Verifico que el fallecimiento ingresado sea válido
    if (nuevo_fallecimiento == -1 || nuevo_fallecimiento > escritor_a_modificar->obtener_anio_nacimiento())
        escritor_a_modificar -> modificar_fallecimiento(nuevo_fallecimiento);
    else
        cout << "El año de fallecimiento ingresado es iunválido, intente nuevamente." << endl;
}

string Menu::pedir_nombre_escritor(){
    string nombre_escritor;

    cout << "Ingrese el nombre del escritor: ";
    cin >> nombre_escritor;
    return nombre_escritor;
}

int Menu::pedir_nuevo_fallecimiento(){
    int nuevo_fallecimiento;

    cout << "Ingrese el nuevo anio de fallecimiento: ";
    cin >> nuevo_fallecimiento;
    return nuevo_fallecimiento;
}

void Menu::listar_escritores(){
    int cant_escritores = lista_escritores.obtener_tamanio();
    for (int i = 1; i < cant_escritores; i++){
        Escritor* escritor_actual = lista_escritores.consultar(i);
        escritor_actual->mostrar_escritor();
    }
}

void Menu::sortear_lectura(){
    // Falta implementacion
}

void Menu::listar_lecturas(){
    int cant_lecturas = lista_lecturas.obtener_tamanio();
    for (int i = 1; i < cant_lecturas; i++){
        imprimir_lectura(i);
        Lectura* lectura_actual = lista_lecturas.consultar(i);
        lectura_actual->mostrar_lectura();
    }
}

void Menu::listar_lecturas_entre_anios(){
    int* anios_ingresados = pedir_anios();
    int desde = anios_ingresados[LECTURAS_DESDE];
    int hasta = anios_ingresados[LECTURAS_HASTA];

    int cant_lecturas = lista_lecturas.obtener_tamanio();

    for(int i = 1; i < cant_lecturas; i++){
        int anio_lectura_actual = lista_lecturas.consultar(i)->obtener_anio();
        if (anio_lectura_actual >= desde && anio_lectura_actual <= hasta)
            imprimir_lectura(i);
    }
}

void Menu::imprimir_lectura(int indice){
        Lectura* lectura_actual = lista_lecturas.consultar(indice);
        lectura_actual->mostrar_lectura();
}

int* Menu::pedir_anios(){
    int anios[2];
    int desde, hasta;

    cout << "Ingrese el año DESDE el cual desea listar las lecturas: ";
    cin >> anios[0];

    cout << "Ingrese el año HASTA el cual desea listar las lecturas: ";
    cin >> anios[1];

    return anios;
}

void Menu::listar_lecturas_de_escritor(){       // Faltaría tener en cuenta el caso donde el escritor sea ANONIMO
    string nombre_escritor = pedir_nombre_escritor();
    int cant_lecturas = lista_lecturas.obtener_tamanio();
    for (int i = 1; i < cant_lecturas; i++){
        Lectura* lectura_actual = lista_lecturas.consultar(i);
        Escritor* escritor_actual = lectura_actual -> obtener_escritor();
        if (escritor_actual != nullptr && escritor_actual->obtener_nombre() == nombre_escritor)
            imprimir_lectura(i);
    }
}

void Menu::listar_novelas_de_genero(){
    generos genero_elegido = pedir_genero();
    int cant_lecturas = lista_lecturas.obtener_tamanio();
    for (int i = 1; i < cant_lecturas; i++){
        Lectura* lectura_actual = lista_lecturas.consultar(i);
        /*if (la lectura es de tipo novela y la novela es del genero genero_elegido)    // Como se puede hacer esto ??
            imprimir_lectura(i);*/
    }
}

generos Menu::pedir_genero(){
    string genero;

    cout << "Ingrese el genero de las novelas que desea listar: ";
    cin >> genero;
    
    return obtener_genero(genero);
}

void Menu::cola_de_lecturas(){
    Cola* cola_lecturas = new Cola();
    // Falta implementacion
}
