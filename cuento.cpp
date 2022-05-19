//
// Created by liuvaneshka on 17/05/22.
//
#include "cuento.h"
#include "Lectura.h"

Cuento :: Cuento(string libro) : Lectura(string titulo, Escritor * _autor, int anio, int minutos){
    this->libro = libro;
}

Cuento :: ~Cuento()= default;

Cuento :: string obtener_libro(){
    return libro;
}

void Cuento :: asignar_libro(string titulo){
    this->libro = titulo;
}

Cuento :: void mostrar_lectura(){
    Lectura::mostrar_lectura();
    cout << "Titulo del libro donde esta el cuento: " << libro << endl;
}