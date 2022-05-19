//
// Created by liuvaneshka on 16/05/22.
//
#ifndef ESCRITOR_H
#define ESCRITOR_H
#include <string>

using namespace std;

class Escritor{
private:
    string nombre_apellido;
    string nacionalidad;
    int anio_nacimiento;
    int anio_fallecimiento;

public:
    /* pre: nombre_apellido y nacionalidad son cadenas
     *      anio_nacimiento y  anio_fallecimiento son enteros positivos
     * post: Inicializa un escritor a partir de los atributos dados
     */
    Escritor(string nombre_apellido, string nacionalidad, int anio_nacimiento, int anio_fallecimiento);
    /*
     * post: destruye Escritor
     * */
    ~Escritor();
    /* post : devuelve el nombre del escritor
    */
    string obtener_nombre();
    /* post : devuelve la nacionalidad del escritor
    */
    string obtener_nacionalidad();
    /* post : devuelve el anio de nacimiento del escritor
    */
    int obtener_anio_nacimiento();
    /* post : devuelve el anio de fallecimiento del escritor
    */
    int obtener_anio_fallecimiento();
    /* pre : anio esun entero positivo
    * post : devuelve true si es enetero positivo, de lo contrario false
    */
    bool validar_entero_positivo(char anio);
    /*post : ingresar datos del escritor
    */
    void ingresar_escritor();
    /* pre : fallecimiento es un entero positivo mayor al
     *      nacimiento que es un enetero positivo
    * post : modifica el anio de fallecimiento
    */
    void modificar_fallecimiento(int nacimiento, int fallecimiento);
    /*
    * post : imprime los atributos del escritor
    */
    void mostrar_escritor();
};

#endif
