#include "Printer.h"

int Printer::pedir_opcion(){
    string opcion;
    cout << VIOLETA << "\n\t\tIngresar opcion: ";
    cin >> opcion;
    return atoi(opcion.c_str());
}

string Printer::pedir_titulo(){
    string titulo;
    cout << NEGRO << "Ingrese el título de la lectura: ";
    cin.ignore();
    getline(cin, titulo);
    return titulo;
}

string Printer::pedir_titulo_eliminar(){
    string titulo_lectura;
    cout << ROJO << "Ingrese el titulo de la lectura que desea eliminar: ";
    cin.ignore();
    getline(cin, titulo_lectura);
    return titulo_lectura;
}

int Printer::pedir_anio(){
    int anio;
    cout << NEGRO << "Ingrese el anio de publicacion de la lectura: ";
    cin >> anio;
    return anio;
}

int Printer::pedir_minutos(){
    int minutos;
    cout << "Ingrese minutos promedio de lectura: ";
    cin >> minutos;
    return minutos;
}

int Printer::pedir_tipo(){
    int tipo;
    cout << NEGRO << "Ingrese el numero de la lectura que deseas crear ";
    cout << AMARILLO << "(1. POEMA / 2. CUENTO / 3. NOVELA): ";
    cin >> tipo;
    return tipo;
}

int Printer::pedir_versos(){
    int versos;
    cout << VERDE << "Ingrese la cantidad de versos del poema: ";
    cin >> versos;
    return versos;
}

string Printer::pedir_libro(){
    string libro;
    cout << "Ingrese el titulo del libro: ";
    cin.ignore();
    getline(cin, libro);
    return libro;
}

generos Printer::pedir_genero(){
    int genero;
    cout << "Ingrese el género de la novela" << endl;
    cout << AMARILLO << "(1.DRAMA / 2.COMEDIA / 3.FICCION / 4.SUSPENSO / 5.TERROR / 6.ROMANTICA / 7.HISTORICA): "<< endl;
    cin >> genero;
    return (generos) genero;
}

generos Printer::pedir_genero_listar(){
    int genero;

    cout << VERDE << "Ingrese el genero de las novelas que desea listar" << endl;
    cout << AMARILLO << " (1.DRAMA / 2.COMEDIA / 3.FICCION / 4.SUSPENSO / 5.TERROR / 6.ROMANTICA / 7.HISTORICA): ";
    cin >> genero;
    cout << '\n';

    return (generos) genero;
}

string Printer::pedir_tema(){
    string tema;
    cout << NEGRO << "Ingrese el tema de la novela histórica: ";
    cin.ignore();
    getline(cin, tema);
    return tema;
}

string Printer::pedir_nombre(){
    string nombre;
    cout << AZUL << "Ingrese el nombre del escritor: ";
    cin.ignore();
    getline(cin, nombre);
    return nombre;
}

string Printer::pedir_nacionalidad(){
    string nacionalidad;
    cout << AZUL << "Ingrese la nacionalidad: " << endl;
    cout << VERDE << " (si es desconocida, ingrese ¿?): ";
    cin >> nacionalidad;
    return nacionalidad;
}

int Printer::pedir_nacimiento(){
    int nacimiento;
    cout << AZUL << "Ingrese el año de nacimiento: " << endl;
    cout << VERDE << " (si es desconocida, ingrese -1): ";
    cin >> nacimiento;
    return nacimiento;
}

int Printer::pedir_fallecimiento(){
    int fallecimiento;
    cout << AZUL << "Ingrese el año de fallecimiento: " << endl;
    cout << VERDE << "(si es desconocida o continua vivo, ingerse -1): ";
    cin >> fallecimiento;
    return fallecimiento;
}

int Printer::pedir_nuevo_fallecimiento(){
    int nuevo_fallecimiento;
    cout << VERDE << "Ingrese el nuevo año de fallecimiento: ";
    cin >> nuevo_fallecimiento;
    return nuevo_fallecimiento;
}

int Printer::pedir_anio_desde(){
    int desde;
    cout << VERDE << "Ingrese el año DESDE el cual desea listar las lecturas: ";
    cin >> desde;
    return desde;
}

int Printer::pedir_anio_hasta(){
    int hasta;
    cout << VERDE << "Ingrese el año HASTA el cual desea listar las lecturas: ";
    cin >> hasta;
    cout << '\n';
    return hasta;
}


char Printer::opcion_leer(){
    char opcion;
    cout << AZUL << "\nDesea marcar la lectura de la cola como leida?" << endl;
    cout << VERDE << " (S.Si / N.No): ";
    cin >> opcion;
    return opcion;
}