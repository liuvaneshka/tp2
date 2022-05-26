//
// Created by liuvaneshka on 25/05/22.
//

#include<iostream>
#include "parser.h"
#include "novela.h"
#include "novela_historica.h"
#include "poema.h"
#include "cuento.h"

using namespace std;

const int no_sabo = -1;
/*
Parser :: Parser(Archivo _entrada){
    this->entrada = _entrada;
}

Parser :: ~Parser(){

}
*/
void Parser :: procesar_escritor(string ruta, Lista<Escritor*> &lista){

    string nombre, nacionalidad, codigo, lectura;
    int nacimiento, fallecimiento;

    entrada.abrir_archivo(ruta);

    while (!entrada.final_archivo()){

        lectura = entrada.leer_linea();

        if(!lectura.empty()){

            nombre = entrada.leer_linea();
            nacionalidad = entrada.leer_linea();
            lectura = entrada.leer_linea();

            if(!lectura.empty()){

                nacimiento = atoi(lectura.c_str());
                lectura = entrada.leer_linea();

                if(!lectura.empty()){
                    fallecimiento = atoi(lectura.c_str());
                }
                else
                    fallecimiento = no_sabo;
            }

            Escritor* autor = new Escritor(nombre, nacionalidad, nacimiento, fallecimiento);
            //lista.insertar(autor) // insettar el objeto dentro de la lista
        }
    }
    entrada.cerrar_archivo(); // esto o destructor
}

void Parser :: procesar_lectura(string ruta, Lista<Lectura*> &lista_lectura){

    string dato, titulo, genero, tipo, libro, referencia_autor, tema_linea;
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

            referencia_autor = entrada.leer_linea();

            //if(referencia_autor != "ANONIMO") // el if se elimina xq el metodo al no encontrar el autor deberia devolver nullptr
                //metodo_retrieve_autor(referencia_autor)

            if(tipo == "P"){
                versos = atoi(dato.c_str());
                //cargar lista de autor(referencia_autor, lista_lectura)
                Poema* poema = new Poema(titulo, *autor, anio, minutos, versos);
            }
            if(tipo == "N"){
                genero = entrada.leer_linea();
                tema_linea = entrada.leer_linea();
                //cargar lista de autor(dato,lista_lectura)
                if (genero == "HISTORICA")
                    Novela_historica* historica = new Novela_historica(titulo, &autor, anio, minutos, &tema);
                else
                    Novela* novela = new Novela(titulo, &autor, anio, minutos, genero);
            }
            if(tipo == "C"){
                //libro = dato;
                //cargar lista de autor(dato,lista_lectura)
                Cuento* cuento = new Cuento(string libro, string titulos, Escritor autor, int anio, int minutos ) ;
            }
            //Lista<Lectura*>  &lista_lectura;
        }
    }
    entrada.cerrar_archivo(); // esto o destructor
}
