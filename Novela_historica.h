#ifndef __NOVELA_HISTORICA_H__
#define __NOVELA_HISTORICA_H__
#include "Novela.h"

class Novela_historica : public Novela{

private:
    char* tema;

    //PRE: contador > 0, dos punteros a arreglos.
    //POST: copia el vector dinamico.
    void copiar_vector(int contador, char * aux, char * &arreglo);

    //PRE: recibe el caracter a almacenar
    //POST: almacena el nuevo caracter e incrementa el tamanio del vector dinamico.
    void almacenar_caracteres(char caracter, char * &arreglo, int &contador);

    //PRE: recibe el tema en formato string.
    //POST: devuelve el tema de la Novela_historica.
    char* recorrer_tema(string tema);

public:
    //PRE: anio > 0, minutos >0, escritor es un objeto válido.
    //POST: Construye un objeto Novela_historica.
    Novela_historica(string titulo, Escritor* escritor, int anio, int minutos, string tema);

    //PRE: El objeto Novela_historica debe ser un objero válido.
    //POST: Destruye un objeto Novela_historica.
    ~Novela_historica();

    //PRE: El objeto Novela_historica debe ser un objero válido.
    //POST: Devuelve el tema de la Novela_historica.
    char* obtener_tema();

    //PRE: El objeto Novela_historica debe ser un objeto válido.
    //POST: Imprime los atributos de la Novela_historica.
    void mostrar_lectura();

    //PRE: El objeto Novela_historica debe ser un objeto válido.
    //POST: Imprime por pantalla la NOvela, si genero es HISTORICA.
    void imprimir_novela_genero(generos genero);

};
#endif // __NOVELA_HISTORICA_H__
