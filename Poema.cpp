//
// Created by Tiago Sandoval on 17/05/2022.
//

#include "Poema.h"

Poema::Poema(std::string titulo, Escritor *autor, int anio, int minutos, int versos)
    : Lectura(titulo, autor, anio, minutos){
        this->versos = versos;
}

Poema::Poema(std::string titulo, int anio, int minutos, int versos)
        : Lectura(titulo, anio, minutos){
    this->versos = versos;
}

int Poema::obtener_versos() const {
    return versos;
}

void Poema::mostrar_lectura() const{
    /*
    cout << "Titulo: " << obtener_titulo() << endl;
    cout << "Minutos: " << obtener_minutos() << endl;
    cout << "Anio: " << obtener_anio() << endl;
     */
    Lectura::mostrar_lectura();
    cout << "Versos: " << obtener_versos() << endl;
}