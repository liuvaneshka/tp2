//
// Created by Tiago Sandoval on 17/05/2022.
//

#ifndef TP2_LECTURA_H
#define TP2_LECTURA_H
#include <iostream>
#include "Escritor.h"

using namespace std;

class Lectura {

protected:
    int minutos;
    int anio;
    Escritor *autor;
    string titulo;

public:
    // Constructor con autor conocido
    Lectura(string titulo, Escritor *autor, int anio, int minutos);
    // Constructor con autor anonimo
    Lectura(string titulo, int anio, int minutos);
     // Destructor
    ~Lectura(){};
    virtual void mostrar_lectura() const = 0;

    string obtener_titulo() const;
    int obtener_minutos() const ;
    int obtener_anio() const;
    Escritor *obtener_autor() const;
    int comparar_lecturas(Lectura *_lectura) const;

};


#endif //TP2_LECTURA_H
