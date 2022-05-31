#include <iostream>
#include "parser.h"
#include "CONSTANTES.h"

using namespace std;
/*
Parser::Parser(){};
*/
/*
Parser::~Parser(){}
*/

Lista<Escritor*> Parser::procesar_escritor(string ruta, Lista<Escritor*> &lista_escritores){

    string nombre, nacionalidad, lectura;
    int nacimiento, fallecimiento;

    Archivo entrada(ruta);

    while (!entrada.final_archivo()){
        lectura = entrada.leer_linea();
        if(!lectura.empty()){
            //int codigo = obtener_referencia(lectura);
            nombre = entrada.leer_linea();
            nacionalidad = entrada.leer_linea();
            lectura = entrada.leer_linea();

            if(!lectura.empty()) {

                nacimiento = atoi(lectura.c_str());
                lectura = entrada.leer_linea();

                if (!lectura.empty()) {
                    fallecimiento = atoi(lectura.c_str());
                }
                else
                    fallecimiento = DESCONOCIDO;

            }
            else{
                nacimiento = DESCONOCIDO;
                fallecimiento = DESCONOCIDO;

            }
            Escritor* escritor = new Escritor(nombre, nacionalidad, nacimiento, fallecimiento);
            cout << "          ]]]]]]ESCRITOR " << escritor << endl;
            almacenar_escritor(escritor, lista_escritores);
        }
    }
    entrada.cerrar_archivo(); // esto o destructor
    return lista_escritores;
}

Lista<Lectura*> Parser::procesar_lectura(string ruta, Lista<Lectura*> &lista_lecturas, Lista<Escritor*> &lista_escritores){

    Escritor* escritor;
    string dato, titulo, tipo, libro, tema_linea;
    generos genero;
    int minutos, anio, versos;

    Archivo entrada(ruta);

    while (!entrada.final_archivo()){
        dato = entrada.leer_linea();
        cout << "entra: " << dato << endl;

        if(!dato.empty()){

            tipo = dato;
            cout << "tipo "  << tipo << endl;
            titulo = entrada.leer_linea();
            cout << "titulo "  << titulo << endl;

            dato = entrada.leer_linea();
            minutos = atoi(dato.c_str());
            cout << "minutos "  << minutos << endl;

            dato = entrada.leer_linea();
            anio = atoi(dato.c_str());
            cout << "anio "  << anio << endl;

            dato = entrada.leer_linea();
            cout << "dato"  << dato << endl;

            if(tipo == POEMA){
                versos = atoi(dato.c_str());
                dato = entrada.leer_linea();
                escritor = obtener_escritor(dato, lista_escritores);
                Poema* poema = new Poema(titulo, escritor, anio, minutos, versos);      // El escritor se pasa sin el & xq ya es un puntero
                almacenar_lectura(poema, lista_lecturas);           // si pongo &lista_lecturas dá error
            }
            else if(tipo == NOVELA){
                dato =  entrada.leer_linea();
                cout << "dato novela "  << dato << endl;
                genero = obtener_genero(dato);
                cout << "genero" << genero << endl;
                if (genero == HISTORICA) {
                    tema_linea = entrada.leer_linea();
                    dato = entrada.leer_linea();
                    escritor = obtener_escritor(dato, lista_escritores);
                    Novela_historica* historica = new Novela_historica(titulo, escritor, anio, minutos, tema_linea);
                    almacenar_lectura(historica, lista_lecturas);
                }
                else{
                    dato = entrada.leer_linea();
                    cout << "      dato " <<dato << endl;
                    int codigo = obtener_referencia(dato);
                    cout <<  "   codigo "<< codigo;
                    escritor = obtener_escritor(dato, lista_escritores);
                    Novela* novela = new Novela(titulo, escritor, anio, minutos, genero);
                    cout<< "construyo"<< endl;
                    almacenar_lectura(novela, lista_lecturas);
                }

            }
            else if(tipo == CUENTO){
                cout << "     libro " << endl;
                libro = dato;
                dato = entrada.leer_linea();
                cout << dato << endl;
                escritor = obtener_escritor(dato, lista_escritores);
                cout <<  "     escritor "<<escritor << endl;
                Cuento* cuento = new Cuento(titulo, escritor, anio, minutos, libro);
                cout<< "construyo"<< endl;
                almacenar_lectura(cuento, lista_lecturas);
            }
        }
    }
    entrada.cerrar_archivo(); // esto o destructor
    return lista_lecturas;
}


generos Parser::obtener_genero(string genero) {
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

void Parser::almacenar_escritor(Escritor* escritor, Lista<Escritor*> &lista_escritores){
    cout << "entro al metodo " << endl;
    lista_escritores.alta_al_final(escritor);
}

void Parser::almacenar_lectura(Lectura* lectura, Lista<Lectura*> &lista_lecturas){
    cout << "almaceno" <<endl;
    int posicion_correcta = obtener_posicion_correcta(lectura, lista_lecturas);
    lista_lecturas.alta(lectura, posicion_correcta);
}

int Parser::obtener_posicion_correcta(Lectura* lectura, Lista<Lectura*> &lista_lecturas){
    int indice = 1;
    lista_lecturas.inicializar();
    while(lista_lecturas.hay_siguiente() && lectura->comparar_lecturas(lista_lecturas.consultar(indice)) != -1){
        indice++;
        lista_lecturas.siguiente();
    }
    return indice;
}

bool Parser::verificar_escritor(string linea_escritor){
    return linea_escritor != "ANONIMO";
}

Escritor* Parser::rastrear_escritor(int codigo, Lista<Escritor*> &lista_escritores){
    cout << "entro rastreo" << endl;
    return lista_escritores.consultar(codigo);
}

Escritor* Parser::obtener_escritor(string dato, Lista<Escritor*> &lista_escritores){
    int referencia_escritor;
    Escritor* escritor;

    if (verificar_escritor(dato)){
        cout << "verifico" << endl;
        referencia_escritor = obtener_referencia(dato);
        cout << "referencia " << referencia_escritor << endl;
        escritor = rastrear_escritor(referencia_escritor, lista_escritores);
    }
    else
        escritor = nullptr;
    return escritor;
}

int Parser::obtener_referencia(string linea) {
    string numero;
    int i = 0;

    while(linea[i] != ')'){
        if(linea[i] != '(')
            numero += linea[i];
        i++;
    }
    return (int) atoi(numero.c_str());
}
