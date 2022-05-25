//
// Created by liuvaneshka on 25/05/22.
//

#include<iostream>
#include"parser.h"
#include"novela.h"

using namespace std;

const int no_sabo = -1;

Parser :: Parser(Archivo _entrada){
    this->entrada = _entrada;
}

Parser :: ~Parser(){

}

Parser :: procesar_escritor(string ruta, Lista<Escritor*> &lista){

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
            }
            else{
                nacimiento = no_sabo;

                lectura = entrada.leer_linea();

                if(!lectura.empty()){
                    fallecimiento = no_sabo;
                }
            }

            Escritor* autor = new Escritor(nombre, nacionalidad, nacimiento, fallecimiento);
            //lista.insertar(autor)

        }
    }
    entrada.cerrar_archivo(); // esto o destructor
}

Parser :: procesar_lectura(string ruta, Lista<Lectura*> &lista_lectura){

    string dato, titulo, genero, tipo;
    int minutos, anio, versos;

    entrada.abrir_archivo(ruta);

    while (!entrada.final_archivo()){

        dato = entrada.leer_linea();

        if(!dato.empty()){

            titulo = entrada.leer_linea();

            dato = entrada.leer_linea();
            minutos = atoi(dato.c_str());

            dato = entrada.leer_linea();
            anio = atoi(dato.c_str());

            dato = entrada.leer_linea();

            if(tipo == "P"){
                versos = atoi(dato.c_str());
                //cargar lista de autor(dato,lista_lectura)
                //Poema(string titulo, Escritor *autor, int anio, int minutos, int versos);
            }
            if(tipo == "N"){
                genero = entrada.leer_linea();
                dato = entrada.leer_linea();
                //cargar lista de autor(dato,lista_lectura)
                /*
                if genero == historica
                    Novela_historica *his(tema);
                else
                    Novela *nov(genero);
                */
            }
            else
                Lectura *autor(titulo, minutos, anio/*, Escritor char* */);
                //Lista<Lectura*>  &lista_lectura;
        }
    }
    entrada.cerrar_archivo(); // esto o destructor
}
