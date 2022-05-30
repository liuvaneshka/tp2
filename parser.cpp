#include <iostream>
#include <string>
#include "parser.h"
#include "CONSTANTES.h"

using namespace std;

Parser::Parser(){};

/*
Parser::~Parser(){}
*/

Lista<Escritor*> Parser::procesar_escritor(string ruta, Lista<Escritor*> &lista_escritores){

    string nombre, nacionalidad, lectura;
    int nacimiento, fallecimiento, codigo;

    Archivo entrada = Archivo(ruta);
    //entrada.abrir_archivo(ruta);

    while (!entrada.final_archivo()){

        lectura = entrada.leer_linea();

        if(!lectura.empty()){

            codigo = obtener_referencia(lectura);
            nombre = entrada.leer_linea();
            nacionalidad = entrada.leer_linea();
            lectura = entrada.leer_linea();

            if(!lectura.empty()){

                nacimiento = atoi(lectura.c_str());
                lectura = entrada.leer_linea();

                if(!lectura.empty())
                    fallecimiento = atoi(lectura.c_str());
                else
                    fallecimiento = DESCONOCIDO;

            }
            else{
                nacimiento = DESCONOCIDO;
                fallecimiento = DESCONOCIDO;

            }
            Escritor* escritor = new Escritor(nombre, nacionalidad, nacimiento, fallecimiento);
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

    Archivo entrada = Archivo(ruta);        // Lo agregué porque si no teniamos constructor entrada no era nada ???
    //entrada.abrir_archivo(ruta);

    while (!entrada.final_archivo()){

        dato = entrada.leer_linea();

        if(!dato.empty()){

            tipo = dato;
            titulo = entrada.leer_linea();

            dato = entrada.leer_linea();
            minutos = atoi(dato.c_str());

            dato = entrada.leer_linea();
            anio = atoi(dato.c_str());

            dato = entrada.leer_linea();

            if(tipo == POEMA){
                versos = atoi(dato.c_str());
                dato = entrada.leer_linea();
                escritor = obtener_escritor(dato, lista_escritores);
                Poema* poema = new Poema(titulo, escritor, anio, minutos, versos);      // El escritor se pasa sin el & xq ya es un puntero
                almacenar_lectura(poema, lista_lecturas);           // si pongo &lista_lecturas dá error
            }
            else if(tipo == NOVELA){
                genero = (generos) stof(entrada.leer_linea());
                if (genero == HISTORICA) {
                    tema_linea = entrada.leer_linea();
                    dato = entrada.leer_linea();
                    escritor = obtener_escritor(dato, lista_escritores);
                    Novela_historica* historica = new Novela_historica(titulo, escritor, anio, minutos, tema_linea);
                    almacenar_lectura(historica, lista_lecturas);
                }
                else{
                    dato = entrada.leer_linea();
                    escritor = obtener_escritor(dato, lista_escritores);
                    Novela* novela = new Novela(titulo, escritor, anio, minutos, genero);
                    almacenar_lectura(novela, lista_lecturas);
                }

            }
            else if(tipo == CUENTO){
                libro = dato;
                dato = entrada.leer_linea();
                escritor = obtener_escritor(dato, lista_escritores);
                Cuento* cuento = new Cuento(titulo, escritor, anio, minutos, libro);
                almacenar_lectura(cuento, lista_lecturas);
            }
        }
    }
    entrada.cerrar_archivo(); // esto o destructor
    return lista_lecturas;
}

void Parser::almacenar_escritor(Escritor* escritor, Lista<Escritor*> &lista_escritores){
    lista_escritores.alta_al_final(escritor);
}

void Parser::almacenar_lectura(Lectura* lectura, Lista<Lectura*> &lista_lecturas){
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

Escritor* Parser::rastrear_escritor(int codigo, Lista<Escritor*> lista_escritores){
    return lista_escritores.consultar(codigo);
}

Escritor* Parser::obtener_escritor(string dato, Lista<Escritor*> lista_escritores){
    int referencia_escritor;
    Escritor* escritor;

    if (verificar_escritor(dato)){
        referencia_escritor = obtener_referencia(dato);
        escritor = rastrear_escritor(referencia_escritor, lista_escritores);
    }
    else
        escritor = nullptr;
    return escritor;
}

int Parser::obtener_referencia(string linea) {
    string numero;
    int i = 1;
    while(i != linea.size() && linea[i] <= 9 && linea[i] >= 1)
        numero += linea[i];
    return (int) stof(numero);
}
