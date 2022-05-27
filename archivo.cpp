#include "archivo.h"

using namespace std;    // Esto despues habría que sacarlo

Archivo :: Archivo(string ruta){
    this->abierto = true;
    abrir_archivo(ruta);
    this-> linea = linea;   // No entiendo para que sirve este tributo ??
}

Archivo :: ~Archivo(){
    this->cerrar_archivo(); // preguntar
}

void Archivo :: abrir_archivo(string ruta){

    if(this->abierto){
        archivo.open(ruta);
        cout << "Exito al abrir el archivo" << endl;
        abierto = true;
    }

    if(archivo.fail()){
        cout << "No abrio el archivo" << endl;
        abierto = false;
    }
}

void Archivo :: cerrar_archivo(){
    archivo.close();
    abierto = false;
}

bool Archivo :: esta_abierto(){
    return abierto;
}

bool Archivo :: final_archivo(){
    return archivo.eof();
}

string Archivo :: leer_linea(){

    getline(archivo, linea);
    return linea;
}