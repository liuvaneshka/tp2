#include "lectura.h"

Lectura::Lectura(string titulo, Escritor * escritor, int anio, int minutos){
    this->titulo = titulo;
    this->anio = anio;
    this->minutos = minutos;
    this->escritor = escritor;
}
Lectura::~Lectura(){}

int Lectura::obtener_anio() {
    return anio;
}

int Lectura::obtener_minutos() {
    return minutos;
}

string Lectura::obtener_titulo() {
    return titulo;
}

Escritor *Lectura::obtener_escritor() {
    return escritor;
}

int Lectura::comparar_lecturas(Lectura *_lectura) {
    int valor;

    if(obtener_anio() < _lectura->obtener_anio())
        valor = -1;
    else if(obtener_anio() > _lectura->obtener_anio())
        valor = 1;
    else
        valor = 0;
    cout << "valor " <<valor << endl;
    return valor;
}

void Lectura::mostrar_lectura() {
    cout << "Titulo: " << obtener_titulo() << endl;
    cout << "Minutos: " << obtener_minutos() << endl;
    cout << "Anio: " << obtener_anio() << "\n" << endl;
}
