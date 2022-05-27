#include "novela_historica.h"
#include <iostream>
using namespace std;

Novela_historica::Novela_historica(string titulo, Escritor* autor, int anio, int minutos, char* tema)
                                    : Novela (titulo, autor, anio, minutos, HISTORICA){
    this -> tema = tema;        // CHAR DINAMICO !!!
}

Novela_historica::~Novela_historica(){
    delete tema;    //Libera memoria del char dinámico ???
}

char* Novela_historica::obtener_tema(){
    return tema;
}

void Novela_historica::mostrar_lectura(){
    Lectura::mostrar_lectura();
    cout << "Tema: " << tema << "\n" << endl;
}

