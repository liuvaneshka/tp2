#ifndef __LISTA_ESCRITORES_H__
#define __LISTA_ESCRITORES_H__
#include "Lista.h"
#include "Escritor.h"
#include "CONSTANTES.h"

class Lista_escritores{

private:
    Lista<Escritor*> lista_escritores;

public:
    Lista_escritores();
    ~Lista_escritores();
    void alta(Escritor* nuevo_escritor);
    void baja(int posicion);
    Escritor* consultar(int posicion);
    bool vacia();
    void listar();
    Escritor* rastrear(string nombre_escritor);
};

#endif // __LISTA_ESCRITORES_H__