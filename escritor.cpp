#include "escritor.h"

Escritor :: Escritor(string nombre_apellido, string nacionalidad, int anio_nacimiento, int anio_fallecimiento){
    this->nombre_apellido = nombre_apellido;
    this->nacionalidad = nacionalidad;
    this->anio_nacimiento = anio_nacimiento;
    this->anio_fallecimiento = anio_fallecimiento;
}

Escritor :: ~Escritor (){};

bool Escritor :: validar_entero_positivo(char anio){
    /*bool numero;
    if(isdigit(anio) && int(anio)>0){
        numero = true;
    }
    else
        numero = false;
    return numero;*/
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


void Escritor :: modificar_fallecimiento(int fallecimiento){    // Al final habiamos comentado que no era necesario validar, al menos por ahora
    //if(validar_entero_positivo(fallecimiento) && (anio_nacimiento < fallecimiento)){
        //cout << "Ingrese el año de fallecimiento: " << endl;
        //cin >> fallecimiento;
        // Creo que se pasaria por pàrámetro ya que otra clase sería la q se encarga de interactuar con el usuario
    anio_fallecimiento = fallecimiento;
    }
//}

void Escritor :: mostrar_escritor(){
    cout << "Nombre: " << nombre_apellido << endl;
    cout << "Nacionalidad: " << nacionalidad << endl;

    string nac;
    if (anio_nacimiento == -1)      // Modifique esto para que al impirmirse imprima "Desconocido" :)
        cout << "Año de nacimiento: Desconocido" << endl;
    else
        cout << "Año de nacimiento: " << anio_nacimiento << endl;

    if (anio_fallecimiento == -1)
        cout << "Año de fallecimiento: Desconocido" << endl;
    else
        cout << "Año de fallecimiento: " << anio_fallecimiento << endl;

}

// Estos ultimos dos metodos tambien los comenté dado que para la prueba de los metodos basicos y herencia no los ibamos a usar

/*void Escritor :: ingresar_anios_escritor(){

    string respuesta = " ";

    cout<<"Sabe anio de nacimiento? S/s de ser asi, caso contrario presione enter: " << endl;
    if( (respuesta == "S") || (respuesta == "s")){
        cout << "introduzca anio nacimiento: ";
        cin >> anio_nacimiento;
    }
    else
        anio_nacimiento = -1;

    cout<<"Sabe anio de fallecimieto? S/s de ser asi, caso contrario presione enter: " << endl;
    if( (respuesta == "S") || (respuesta == "s")){
        cout << "Introduzca anio fallecimiento: ";
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
        cout << "Ingrese nacionalidad: " << endl;
        cin >> nacionalidad;
    }
}*/


/*void Escritor :: ingresar_nombre_apellido(){
    cout << "Ingrese el nombre y apellido: " << endl;
    cin >> nombre_apellido;
}*/
