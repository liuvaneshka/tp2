#include "novela_historica.h"
#include <iostream>
using namespace std;

Novela_historica::Novela_historica(string titulo, Escritor* autor, int anio, int minutos, generos genero, char* tema)
                                    : Novela (titulo, autor, anio, minutos, genero){
    this -> tema = tema;

}

char* Novela_historica::obtener_tema(){
    return tema;
}

void Novela_historica::mostrar_lectura(){
    Lectura::mostrar_lectura();
    cout << "Tema: " << tema << endl;
}

Novela_historica::~Novela_historica(){}
