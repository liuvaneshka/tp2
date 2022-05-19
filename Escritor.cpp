#include <string>
#include "Escritor.h"

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

void Escritor :: ingresar_anios_escritor(){

    string respuesta = " ";

    cout<<"Sabe anio de nacimiento? S/s de ser asi, caso contrario presione enter: " << endl;
    if( (respuesta == "S") || (respuesta == "s")){
        cout << "introduzca anio nacimiento: ":
        cin >> anio_nacimiento;
    }
    else
        anio_nacimiento = -1;

    cout<<"Sabe anio de fallecimieto? S/s de ser asi, caso contrario presione enter: " << endl;
    if( (respuesta == "S") || (respuesta == "s")){
        cout << "introduzca anio fallecimiento: ":
        cin >> anio_fallecimiento;
    }
}

char* Escritor :: ingresar_escritor(){
    string anonimo = "";
    char* arreglo_autor = nullptr;
    cout<<"El autor es anonimo? S/s de ser asi, caso contrario presione enter: " << endl;
    if( (anonimo == "S") || (anonimo == "s")){
        arreglo_autor = nullptr;
    }
    else{
        cout << "Ingrese el nombre y apellido: " << endl;
        cin >> nombre_apellido;
        cout << "Ingrese nacionaliad: " << endl;
        cin >> nacionalidad;
    }
}

void Escritor :: modificar_fallecimiento(int nacimiento,int fallecimiento){
    if(validar_entero_positivo(fallecimiento) && (nacimiento < fallecimiento))){
        cout << "ingrese el anio de fallecimiento" << endl;
        cin >> fallecimiento;
        anio_fallecimiento = fallecimiento;
    }
}

void Escritor :: mostrar_escritor(){
    cout << "Nombre: " << nombre_apellido << endl;
    cout << "Nacionalidad: " << nacionalidad<< endl;
    cout << "Anio de nacimiento: " << nacimiento << endl;
    cout << "Anio de fallecimiento: " << anio_fallecimiento << endl;
}
