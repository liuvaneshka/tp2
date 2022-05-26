#include <iostream>
#include <string>
#include "parser.h"
/*
#include "../clases principales/novela.h"
#include "../clases principales/Poema.h"
#include "../clases principales/novela_historica.h"
#include "../clases principales/cuento.h"
#include "../clases principales/Escritor.h"
#include "lista.h"
*/

using namespace std;

/* VER EL ERROR
Parser::Parser(Archivo entrada) {
    this -> entrada = entrada;
}
*/
Parser::~Parser(){}

void Parser::procesar_escritor(string ruta, Lista<Escritor*> &lista_escritores){

    string nombre, nacionalidad, codigo, lectura;
    int nacimiento, fallecimiento;

    entrada.abrir_archivo(ruta);

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
            almacenar_escritor(escritor);
        }
    }
    entrada.cerrar_archivo(); // esto o destructor
}

void Parser::procesar_lectura(string ruta, Lista<Lectura*> &lista_lecturas, Lista<Escritor*> &lista_escritores){

    Escritor* escritor;
    string dato, titulo, tipo, libro, tema_linea;
    int referencia_escritor;
    generos genero;
    int minutos, anio, versos;

    entrada.abrir_archivo(ruta);

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
                Poema* poema = new Poema(titulo, &escritor, anio, minutos, versos);
            }
            else if(tipo == NOVELA){                                    //puse else if para que no recorra ciclos de mas
                genero = (generos) stof(entrada.leer_linea());
                if (genero == HISTORICA) {
                    tema_linea = entrada.leer_linea();
                    dato = entrada.leer_linea();
                    escritor = obtener_escritor(dato, lista_escritores);
                    Novela_historica *historica = new Novela_historica(titulo, &escritor, anio, minutos, tema_linea);
                }
                else{
                    dato = entrada.leer_linea();
                    escritor = obtener_escritor(dato, lista_escritores);
                    Novela* novela = new Novela(titulo, &escritor, anio, minutos, genero);
                }

            }
            else if(tipo == CUENTO){
                libro = dato;
                dato = entrada.leer_linea();
                escritor = obtener_escritor(dato, lista_escritores);
                Cuento* cuento = new Cuento(titulo, &escritor, anio, minutos, libro);
            }

            //Lista<Lectura*>  &lista_lectura;
        }
    }
    entrada.cerrar_archivo(); // esto o destructor
}

void Parser::almacenar_escritor(Escritor* escritor, Lista<Escritor*> &lista_escritores){
    lista_escritores.alta(escritor, lista_escritores.obtener_tamanio() - 1);    // Almacenado al final!
}

void Parser::almacenar_lectura(Lectura* lectura, Lista<Lectura*> &lista_lecturas){
    int posicion_correcta = obtener_posicion_correcta(lectura, lista_lecturas);
    lista_lecturas.alta(lectura, posicion_correcta);
}

int Parser::obtener_posicion_correcta(Lectura* lectura, Lista<Lectura*> &lista_lecturas){}

bool Parser::verificar_escritor(string linea_escritor){
    return (linea_escritor != "ANONIMO");
}

Escritor* Parser::rastrear_escritor(int codigo, Lista<Escritor*> lista_escritores){
    return lista_escritores.consultar(codigo);
}

Escritor* Parser::obtener_escritor(string dato, Lista<Escritor*> lista_escritores){
    int referencia_escritor;
    Escritor* escritor;

    if (verificar_escritor(dato)){
        referencia_escritor = obtener_referencia(dato);
        escritor = rastrear_escritor(referencia_escritor, lista_lecturas);
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
