#ifndef __NOVELA_HISTORICA_H__
#define __NOVELA_HISTORICA_H__
#include "novela.h"

class Novela_historica : public Novela{

private:
    char* tema;

    //PRE: recibe un entero positovp contador y dos punteros de arreglos
    //POST: copia el vector dinamico.
    void copiar_vector(int contador, char * aux, char * &arreglo);

    //PRE: recibe el caracter a almacenar
    //POST: almacena el nuevo caracter, incrementa el tamanio del vector dinamico
    void almacenar_caracteres(char caracter, char * &arreglo, int &contador);

    //PRE: recibe el tema
    //POST: Devuelve el tema de la Novela_historica.
    char* recorrer_tema(string tema);

public:
    //PRE: genero y tema deben ser válidos.
    //POST: Construye un objeto Novela_historica.
    Novela_historica(string titulo, Escritor* escritor, int anio, int minutos, string tema);

    //PRE: El objeto Novela_historica debe ser un objero válido.
    //POST: Destruye un objeto Novela_historica.
    ~Novela_historica();

    //PRE: El objeto Novela_historica debe ser un objero válido.
    //POST: Devuelve el tema de la Novela_historica.
    char* obtener_tema();

    //PRE: El objeto Novela_historica debe ser un objeto válido.
    //POST: Muestra por pantalla los atributos de Novela_historica.
    void mostrar_lectura();

};
#endif // __NOVELA_HISTORICA_H__
