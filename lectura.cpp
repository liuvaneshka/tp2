#include "lectura.h"

Lectura::Lectura(string titulo, Escritor * autor, int anio, int minutos){
    this->titulo = titulo;
    this->anio = anio;
    this->minutos = minutos;
    this->autor = autor;
}

// Habria que verificar si efectivamnete con un solo constructor la implementacion es posible
// Funciona si en el parametro Escrtitor* _autor le paso nullptr ???

/*Lectura::Lectura(string titulo, int anio, int minutos){
    this->titulo = titulo;
    this->anio = anio;
    this->minutos = minutos;
    this->autor = 0;
}*/

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
    if (autor)
        return autor;
    return nullptr;
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

void Lectura::mostrar_lectura() {
    cout << "Titulo: " << obtener_titulo() << endl;
    cout << "Minutos: " << obtener_minutos() << endl;
    cout << "Anio: " << obtener_anio() << endl;
}

// Metodo para cuando el autor de la lectura sea null -> Qué otras maneras hay para solucionarlo ?
string Lectura::nombre_autor(){
    string nombre;
    if (obtener_autor())
        nombre = obtener_autor() -> obtener_nombre();
    else
        nombre = "Desconocido";
    return nombre;
}