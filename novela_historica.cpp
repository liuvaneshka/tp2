#include "novela_historica.h"
#include <iostream>
using namespace std;

Novela_historica::Novela_historica(string titulo, Escritor* autor, int anio, int minutos, string _tema)
                                    : Novela (titulo, autor, anio, minutos, HISTORICA){
    this->tema = recorrer_tema(_tema);
}

Novela_historica::~Novela_historica(){
    delete tema;    //Libera memoria del char dinámico ???
}

char* Novela_historica::obtener_tema(){
    return tema;
}

void Novela_historica::copiar_vector(int contador, char* aux, char* &arreglo){

    for(int i =0; i < contador; i++){
        aux[i] = arreglo[i];
    }

    delete[]arreglo;
    arreglo = aux;
}

void Novela_historica::almacenar_caracteres(char caracter, char * &arreglo, int &contador){

    if(arreglo == nullptr){
        contador++;
        arreglo = new char[contador];
        arreglo[0] = caracter;
    }

    else{

        char* aux = nullptr;
        aux = new char[contador + 1];
        copiar_vector(contador, aux, arreglo);
        aux[contador] = caracter;
        contador++;
    }
}

char* Novela_historica::recorrer_tema(string tema){

    char* arreglo = nullptr;

    int i = 0, contador = 0;
    char caracter;

    while(tema[i] != '\0'){
        caracter = tema[i];
        almacenar_caracteres(caracter, arreglo, contador);
        i++;
    }

    if(contador > 0){
        char caracter = '\0';
        almacenar_caracteres(caracter, arreglo, contador);
    }

    return arreglo;
}

void Novela_historica::mostrar_lectura(){
    Lectura::mostrar_lectura();
    cout << "Tema: " << tema << "\n" << endl;

    if(this->tema == nullptr){
        cout << "tema vacio." << endl;
    }
    else{
        int i = 0;
        while(tema[i] != '\0'){
            cout << tema[i] ;
            i++;
        }
        cout << endl;
    }
}

