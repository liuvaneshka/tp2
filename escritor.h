#ifndef ESCRITOR_H
#define ESCRITOR_H
#include <string>
#include <iostream>

using namespace std;

class Escritor{
private:
    string nombre_apellido;
    string nacionalidad;
    int anio_nacimiento;
    int anio_fallecimiento;

    /* pre : anio esun entero positivo
    post : devuelve true si es enetero positivo, de lo contrario false
    */
    bool validar_entero_positivo(char anio);

public:

    /*PRE: nombre_apellido y nacionalidad son cadenas,
           anio_nacimiento y anio_fallecimiento son enteros positivos */
    //POST: Inicializa un escritor a partir de los atributos dados.
    Escritor(string nombre_apellido, string nacionalidad, int anio_nacimiento, int anio_fallecimiento);
    Escritor(); // TEMPLATE!!

    //PRE:
    //POST: destruye Escritor.
    ~Escritor();

    //PRE:
    //POST: devuelve el nombre del escritor
    string obtener_nombre();

    //PRE:
    //POST: devuelve la nacionalidad del escritor
    string obtener_nacionalidad();

    //PRE:
    //POST: devuelve el anio de nacimiento del escritor
    int obtener_anio_nacimiento();

    //PRE:
    //POST: devuelve el anio de fallecimiento del escritor
    int obtener_anio_fallecimiento();

    /*PRE:fallecimiento es un entero positivo mayor al
        nacimiento que es un enetero positivo */
    // POST: modifica el anio de fallecimiento
    void modificar_fallecimiento(int fallecimiento);

    //PRE:
    //POST: imprime los atributos del escritor
    void mostrar_escritor();
};

#endif