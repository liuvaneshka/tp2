#include "poema.h"

Poema::Poema(std::string titulo, Escritor *autor, int anio, int minutos, int versos)
    : Lectura(titulo, autor, anio, minutos){
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