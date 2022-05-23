#ifndef TP2_POEMA_H
#define TP2_POEMA_H
#include "lectura.h"

class Poema : public Lectura {

private:
    int versos;

public:
    Poema(string titulo, Escritor *autor, int anio, int minutos, int versos);
    ~Poema(){};

    int obtener_versos();
    void mostrar_lectura();
};

#endif //TP2_POEMA_H