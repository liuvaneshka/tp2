#include "novela.h"

Novela::Novela(string titulo, Escritor *escritor, int anio, int minutos, generos genero)
                : Lectura(titulo, escritor, anio, minutos){
    this -> genero = genero;
}

Novela::~Novela(){}

generos Novela::obtener_genero(){
    return genero;
}

void Novela::mostrar_lectura(){
    Lectura::mostrar_lectura();
    cout << "Género: " << obtener_genero() << "\n" << endl;
}

