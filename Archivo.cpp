//
// Created by liuvaneshka on 19/05/22.
//
#include<iostream>
#include "Archivo.h"

using namespace std;

Archivo :: Archivo(string ruta){
    //archivo.open(ruta);//no se cual es mejor opcion
    abrir_archivo(ruta);
    this->abierto = true;
}

Archivo :: ~Archivo(){

    this->cerrar_archivo();

}

void Archivo :: abrir_archivo(string ruta){

    if(this->abierto){
        cout << "exito al abrir el archivo" << endl;
        archivo.open(ruta);
        abierto = true;
    }

    if(archivo.fail()){
        abierto = false;
    }

}

void Archivo :: cerrar_archivo(){
    archivo.close();
    abierto = false;
}

bool Archivo :: esta_abierto(){
    return abierto;
}

bool Archivo :: final_archivo(){
    return archivo.eof();
}

string Archivo :: leer_dato_linea_en_blanco(){
    string dato, linea;
    do{
        getline(archivo, linea);
        dato += linea + ',';
    }while (!linea.empty());
    dato += '\n';

    return dato;
}
//esta funcion iria en el parser y seria la de cargar_lectura
void Archivo :: mostrar_datos(){
    //Lectura lectura
    //parametros

    while (!final_archivo()){

        string lectura = leer_dato_linea_en_blanco();

        cout << lectura << endl;
        //cout << " " << endl;
        //lectura = new lectura(parametros)
        //lista.agregar(dato)

    }
}
