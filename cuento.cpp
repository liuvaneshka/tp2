//
// Created by liuvaneshka on 17/05/22.
//
#include "Cuento.h"
#include "lectura.h"

Cuento :: Cuento(string libro, string titulos, Escritor autor, int anio, int minutos ) : Lectura(titulo, autor, anio, minutos){
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
