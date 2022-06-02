#include "Cuento.h"

Cuento::Cuento(string titulo, Escritor *escritor, int anio, int minutos, string libro)
        : Lectura(titulo, escritor, anio, minutos){
    this->libro = libro;
}

string Cuento::obtener_libro(){
    return libro;
}

void Cuento :: mostrar_lectura(){
    Lectura::mostrar_lectura();
    cout << "Titulo del libro donde esta el cuento: " << obtener_libro() << "\n" << endl;
}

Cuento :: ~Cuento(){};

void Cuento::imprimir_novela_genero(generos genero){}
