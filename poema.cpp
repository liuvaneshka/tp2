#include "poema.h"

Poema::Poema(std::string titulo, Escritor *autor, int anio, int minutos, int versos)
    : Lectura(titulo, autor, anio, minutos){
        this->versos = versos;
}
// Acá de nuevo comenté el segundo constructor, hay q verificar si no es necesario tenerlo

/*Poema::Poema(std::string titulo, int anio, int minutos, int versos)
        : Lectura(titulo, anio, minutos){
    this->versos = versos;
}*/

int Poema::obtener_versos(){
    return versos;
}

void Poema::mostrar_lectura(){

    Lectura::mostrar_lectura();
    cout << "Versos: " << obtener_versos() << endl;
}