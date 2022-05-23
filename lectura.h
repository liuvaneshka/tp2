#ifndef TP2_LECTURA_H
#define TP2_LECTURA_H
#include <iostream>
#include <string>           // Es necesario ??
#include "CONSTANTES.h"
#include "escritor.h"
using namespace std;

class Lectura {

protected:
    int minutos;
    int anio;
    Escritor* autor;
    string titulo;

public:
    // Constructor con autor conocido
    Lectura(string titulo, Escritor *autor, int anio, int minutos);
    // Constructor con autor anonimo
    Lectura(string titulo, int anio, int minutos);
     // Destructor
    ~Lectura(){};
    virtual void mostrar_lectura() = 0;         // Creo que no va un const sino me tira que TODO es abstracto (verificar el resto de los const)

    string obtener_titulo() const;
    int obtener_minutos() const ;
    int obtener_anio() const;
    Escritor *obtener_autor() const;
    int comparar_lecturas(Lectura *_lectura) const;

    string nombre_autor();

};

#endif //TP2_LECTURA_H