//
// Created by Tiago Sandoval on 17/05/2022.
//

#ifndef TP2_POEMA_H
#define TP2_POEMA_H

#include "Lectura.h"

class Poema : public Lectura {       // es public Lectura o protected Lectura?
private:
    int versos;

public:
    Poema(std::string titulo, Escritor *autor, int anio, int minutos, int versos);
    Poema(std::string titulo, int anio, int minutos, int versos);
    ~Poema(){};
    int obtener_versos() const;
    void mostrar_lectura() const;
};


#endif //TP2_POEMA_H
