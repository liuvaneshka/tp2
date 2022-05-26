#include "novela.h"

Novela::Novela(string titulo, Escritor *autor, int anio, int minutos, generos genero)
                : Lectura(titulo, autor, anio, minutos){
    this -> genero = genero;
}

generos Novela::obtener_genero(){
    return genero;
}

void Novela::mostrar_lectura(){

    Lectura::mostrar_lectura();
    cout << "Género: " << obtener_genero() << endl;
}

Novela::~Novela(){}
