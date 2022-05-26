//
// Created by Tiago Sandoval on 24/05/2022.
//

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

Parser::Parser(Archivo _entrada) {
    this->entrada = _entrada;
}

Parser::~Parser(){}

void Parser::procesar_escritor(string ruta, Lista<Escritor*> &lista){

    string nombre, nacionalidad, codigo, lectura;
    int nacimiento, fallecimiento;

    entrada.abrir_archivo(ruta);

    while (!entrada.final_archivo()){

        lectura = entrada.leer_linea();

        if(!lectura.empty()){
            
            codigo = atoi(lectura[1]);
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
            Escritor* autor = new Escritor(nombre, nacionalidad, nacimiento, fallecimiento);
            //lista.insertar(autor) // insettar el objeto dentro de la lista
        }
    }
    entrada.cerrar_archivo(); // esto o destructor
}

void Parser::procesar_lectura(string ruta, Lista<Lectura*> &lista_lectura){

    Escritor* autor;
    string dato, titulo, tipo, libro, referencia_autor, tema_linea;
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
            //referencia_autor = entrada.leer_linea();

            //if(referencia_autor != "ANONIMO") // el if se elimina xq el metodo al no encontrar el autor deberia devolver nullptr
            //metodo_retrieve_autor(referencia_autor)

            if(tipo == POEMA){
                versos = atoi(dato.c_str());
                dato = entrada.leer_linea();
                referencia_autor = atoi(dato[1]);       // Falta tener en cuenta el caso donde dice ANONIMO (error al casterlo a int)
                autor = rastrear_autor(referencia_autor, lista_lectura);
                Poema* poema = new Poema(titulo, &autor, anio, minutos, versos);
            }
            else if(tipo == NOVELA){                                    //puse else if para que no recorra ciclos de mas
                genero = (generos) stof(entrada.leer_linea());
                if (genero == HISTORICA) {
                    tema_linea = entrada.leer_linea();
                    dato = entrada.leer_linea();
                    referencia_autor = atoi(dato[1]);
                    autor = rastrear_autor(referencia_autor, lista_lectura);
                    Novela_historica *historica = new Novela_historica(titulo, &autor, anio, minutos, tema_linea);
                }
                else{
                    dato = entrada.leer_linea();
                    referencia_autor = atoi(dato[1]);
                    autor = rastrear_autor(referencia_autor, lista_lectura);
                    Novela* novela = new Novela(titulo, &autor, anio, minutos, genero);
                }
                    
            }
            else if(tipo == CUENTO){
                libro = dato;
                dato = entrada.leer_linea();
                referencia_autor = atoi(dato[1]);
                autor = rastrear_autor(referencia_autor, lista_lectura);
                Cuento* cuento = new Cuento(titulo, &autor, anio, minutos, libro);
            }

            //Lista<Lectura*>  &lista_lectura;
        }
    }
    entrada.cerrar_archivo(); // esto o destructor
}


