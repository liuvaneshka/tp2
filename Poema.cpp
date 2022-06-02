#include "Poema.h"

Poema::Poema(std::string titulo, Escritor *escritor, int anio, int minutos, int versos)
    : Lectura(titulo, escritor, anio, minutos){
        this->versos = versos;
}

Poema::~Poema(){}

int Poema::obtener_versos(){
    return versos;
}

void Poema::mostrar_lectura(){
    Lectura::mostrar_lectura();
    cout << "Versos: " << obtener_versos() << "\n" << endl;
}


void Poema::imprimir_novela_genero(generos genero){}
