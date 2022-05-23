#include "cuento.h"

Cuento::Cuento(string titulo, Escritor *autor, int anio, int minutos, string libro)
        : Lectura(titulo, autor, anio, minutos){
    this->libro = libro;
}

string Cuento::obtener_libro(){
    return libro;
}

void Cuento :: mostrar_lectura(){
    Lectura::mostrar_lectura();
    cout << "Titulo del libro donde esta el cuento: " << obtener_libro() << endl;
}

Cuento :: ~Cuento(){};       // Esto del = default me tira warnings