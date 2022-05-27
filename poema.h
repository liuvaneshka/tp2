#ifndef TP2_POEMA_H
#define TP2_POEMA_H
#include "lectura.h"

class Poema : public Lectura {

private:
    int versos;

public:

    //PRE:
    //POST:
    Poema(std::string titulo, Escritor *escritor, int anio, int minutos, int versos);

    //PRE:
    //POST:
    ~Poema();

    //PRE:
    //POST:
    int obtener_versos();

    //PRE:
    //POST:
    void mostrar_lectura();
};

#endif //TP2_POEMA_H