#include "novela_historica.h"

Novela_historica::Novela_historica(string titulo, Escritor* autor, int anio, int minutos, char* tema)
                                    : Novela (titulo, autor, anio, minutos, HISTORICA){
    this -> tema = tema;
// Esto deberia ser un puntero dinámico, el cual no entiendo como usar

}

char* Novela_historica::obtener_tema(){
    return tema;
}

void Novela_historica::mostrar_lectura(){
    Lectura::mostrar_lectura();
    cout << "Tema: " << tema << endl;
}

Novela_historica::~Novela_historica(){} // Con el puntero dinámico, supongo que acá deberia eliminarse
