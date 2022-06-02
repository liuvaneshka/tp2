#include "Escritor.h"
using namespace std;

Escritor :: Escritor(string nombre_apellido, string nacionalidad, int anio_nacimiento, int anio_fallecimiento){
    this->nombre_apellido = nombre_apellido;
    this->nacionalidad = nacionalidad;
    this->anio_nacimiento = anio_nacimiento;
    this->anio_fallecimiento = anio_fallecimiento;
}

Escritor :: ~Escritor (){
    cout << "*****Destructor escritor : " << endl;

};

bool Escritor :: validar_entero_positivo(char anio){
    return (isdigit(anio) && int(anio) > 0);
}

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

void Escritor :: modificar_fallecimiento(int fallecimiento){
    anio_fallecimiento = fallecimiento;
}

void Escritor :: mostrar_escritor(){
    cout << "Nombre: " << nombre_apellido << endl;
    cout << "Nacionalidad: " << nacionalidad << endl;

    if (anio_nacimiento == -1)
        cout << "Año de nacimiento: Desconocido" << endl;
    else
        cout << "Año de nacimiento: " << anio_nacimiento << endl;

    if (anio_fallecimiento == -1)
        cout << "Año de fallecimiento: Desconocido" << endl;
    else
        cout << "Año de fallecimiento: " << anio_fallecimiento << endl;
    cout << "\n" << endl;
}
