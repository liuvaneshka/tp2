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

    //PRE: anio > 0.
    //POST: devuelve true si es anio es un entero positivo, false en caso contrario.
    bool validar_entero_positivo(char anio);

public:

    //PRE: anio_nacimiento > 0, anio_fallecimiento > 0, y anio_fallecimeinto > anio_nacimiento.
    //POST: Inicializa un escritor a partir de los atributos dados.
    Escritor(string nombre_apellido, string nacionalidad, int anio_nacimiento, int anio_fallecimiento);

    //PRE: El objeto Escritor debe ser un objeto válido.
    //POST: Destruye un Escritor.
    ~Escritor();

    //PRE: El objeto Escritor debe ser un objeto válido.
    //POST: Devuelve el nombre del escritor.
    string obtener_nombre();

    //PRE: El objeto Escritor debe ser un objeto válido.
    //POST: Devuelve la nacionalidad del escritor.
    string obtener_nacionalidad();

    //PRE: El objeto Escritor debe ser un objeto válido.
    //POST: Devuelve el año de nacimiento del escritor.
    int obtener_anio_nacimiento();

    //PRE: El objeto Escritor debe ser un objeto válido.
    //POST: devuelve el año de fallecimiento del escritor.
    int obtener_anio_fallecimiento();

    //PRE:fallecimiento > 0 y fallecimiento > anio_nacimiento.
    //POST: Modifica el anio de fallecimiento.
    void modificar_fallecimiento(int fallecimiento);

    //PRE: El objeto Escritor debe ser un objeto válido.
    //POST: Imprime los atributos del Escritor.
    void mostrar_escritor();
};

#endif
