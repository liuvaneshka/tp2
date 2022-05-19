//
// Created by Tiago Sandoval on 17/05/2022.
//

#include "Lectura.h"

Lectura::Lectura(string titulo, Escritor * _autor, int anio, int minutos) : autor(_autor){
    this->titulo = titulo;
    this->autor = _autor;
    this->anio = anio;
    this->minutos = minutos;
}

Lectura::Lectura(string titulo, int anio, int minutos) : autor(nullptr){
    this->titulo = titulo;
    this->anio = anio;
    this->minutos = minutos;
}


int Lectura::obtener_anio() const {
    return anio;
}

int Lectura::obtener_minutos() const {
    return minutos;
}

string Lectura::obtener_titulo() const {
    return titulo;
}

Escritor *Lectura::obtener_autor() const {
    return autor;
}

int Lectura::comparar_lecturas(Lectura *_lectura) const {
    int valor;

    if(obtener_anio() < _lectura->obtener_anio())
        valor = -1;
    else if(obtener_anio() > _lectura->obtener_anio())
        valor = 1;
    else //if(obtener_anio() == _lectura->obtener_anio())
        valor = 0;

    return valor;
}

void Lectura::mostrar_lectura() const {
    cout << "Titulo: " << obtener_titulo() << endl;
    cout << "Minutos: " << obtener_minutos() << endl;
    cout << "Anio: " << obtener_anio() << endl;
}
