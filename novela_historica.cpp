#include "novela_historica.h"
#include <iostream>
using namespace std;

Novela_historica::Novela_historica(string titulo, Escritor* autor, int anio, int minutos, string tema)
                                    : Novela (titulo, autor, anio, minutos, HISTORICA){
    char* _tema = new char[tema.size()];
    for (int i = 0; i < tema.size(); i++)
        _tema[i] = tema[i];
    this->tema = _tema;
}
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

