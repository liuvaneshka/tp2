#ifndef __LISTA_LECTURAS_H__
#define __LISTA_LECTURAS_H__
#include "Lista.h"
#include "Lectura.h"
#include "CONSTANTES.h"

class Lista_lecturas{

private:
    Lista<Lectura*> lista_lecturas;

    int posicion_segun_anio(Lectura* lectura);

public:
    Lista_lecturas();
    ~Lista_lecturas();

    void inicializar();
    bool hay_actual();
    void siguiente();
    Lectura* obtener_dato_cursor();

    void alta(Lectura* lectura);
    void baja(int posicion);
    bool vacia();
    Lectura* consultar(int posicion);

    int rastrear(string titulo);
    void sortear();

    void listar();
    void listar_entre_anios(int desde, int hasta);
    void listar_por_escritor(string nombre_escritor);
    void listar_por_genero(generos genero);
};

#endif // __LISTA_LECTURAS_H__