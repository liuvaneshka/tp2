#ifndef __PARSER_H__
#define __PARSER_H__
#include "Lista.h"
#include "Lectura.h"
#include "Escritor.h"
#include "Archivo.h"
#include "Novela.h"
#include "Novela_historica.h"
#include "Cuento.h"
#include "Poema.h"

#include <sstream>
using namespace std;

class Parser{

private:

    //PRE: linea_genero es una linea leida del archivo de Lecturas.
    //POST: Devuelve el genero del enumerado asociado.
    generos obtener_genero(string linea_genero);

    //PRE: escritor debe ser un objeto válido.
    //POST: Almacena al final de la lista_escritores el escritor.
    void almacenar_escritor(Escritor* escritor, Lista<Escritor*> *lista_escritores);

    //PRE: lectura debe ser un objeto válido.
    //POST: Almacena en la lista_lecturas la lectura en orden según el año de publicacion, de manera creciente.
    void almacenar_lectura(Lectura* lectura, Lista<Lectura*> *lista_lecturas);

    //PRE: linea es una linea leida del archivo de Lecturas.
    //POST: Devuelve true si se conoce al escritor de la lectura, false en caso contrario.
    bool verificar_escritor(string linea_escritor);

    //PRE: linea es una linea leida del archivo de Lecturas.
    //POST: Devuelve el escritor, de no existir, devueleve nullptr.
    Escritor* obtener_escritor(string linea, Lista<Escritor*> *lista_escritores);

    //PRE: codigo > 0
    //POST: Devuelve el Escritor que corresponde en base a la referencia de la Lectura.
    Escritor* rastrear_escritor(int codigo, Lista<Escritor*> *lista_escritores);

    //PRE: lectura debe ser un objeto válido.
    //POST: Devuelve el indice de la lista_lecturas donde se debe almacenar la lectura para mantener la lista en orden.
    int obtener_posicion_correcta(Lectura* lectura, Lista<Lectura*> *lista_lecturas);

    //PRE: linea es una linea leida del archivo de Lecturas.
    //POS: Devuelve la referencia al Escritor que le corresponde a la Lectura.
    int obtener_referencia(string linea);

public:

    //PRE: ruta debe ser una ruta válida.
    //POST: Lee el archivo de escritores, crea los objetos y los almacena en lista_escritores.
    Lista <Escritor*>* procesar_escritor(string ruta, Lista<Escritor*> *lista_escritores);

    //PRE: ruta debe ser una ruta válida.
    //POST: Lee el archivo de lecturas, crea los objetos y los almacena en lista_lecturas.
    Lista <Lectura*>* procesar_lectura(string ruta, Lista<Lectura*> *lista_lectura,Lista<Escritor*> *lista_escritores);
};
#endif // __PARSER_H__
