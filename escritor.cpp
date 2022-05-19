#include <string>
#include "escritor.h"

using namespace std;

Escritor :: Escritor(string nombre_apellido, string nacionalidad, int anio_nacimiento, int anio_fallecimiento){
    this->nombre_apellido = nombre_apellido;
    this->nacionalidad = nacionalidad;
    this->anio_nacimiento = anio_nacimiento;
    this->anio_fallecimiento = anio_fallecimiento;
}

Escritor :: ~Escritor ()= default;

string Escritor :: obtener_nombre(){
    return nombre_apellido;
}

string Escritor :: obtener_nacionalidad(){
    return nacionalidad;
}

int Escritor :: obtener_anio_nacimiento(){
    return anio_nacimiento;
}

int Escritor :: obtener_anio_fallecimiento(){
    return anio_fallecimiento;
}

bool Escritor :: validar_entero_positivo(char anio){
    bool numero;
    if(isdigit(anio) && int(anio)>0){
        numero = true;
    }
    else
        numero = false;
    return numero;
}

void Escritor :: modificar_fallecimiento(int nacimiento,int fallecimiento){
    if(validar_entero_positivo(fallecimiento) && (nacimiento < fallecimiento))){
        anio_fallecimiento = fallecimiento;
    }
}

void Escritor :: mostrar_escritor(){
    cout << "Nombre: " << nombre_apellido << endl;
    cout << "Nacionalidad: " << nacionalidad<< endl;
    cout << "Anio de nacimiento: " << nacimiento << endl;
    cout << "Anio de fallecimiento: " << anio_fallecimiento << endl;
}
