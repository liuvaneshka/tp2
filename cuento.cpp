//
// Created by liuvaneshka on 17/05/22.
//
#include "cuento.h"

Cuento :: Cuento(string libro){
    this->libro = libro;
}

Cuento :: ~Cuento()= default;

Cuento :: string obtener_libro(){
    return libro;
}

Cuento :: void mostrar_lectura(){
    cout << "Titulo del libro donde esta el cuento: " << libro << endl;
}