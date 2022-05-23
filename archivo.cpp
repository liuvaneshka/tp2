#include"archivo.h"

using namespace std;
 
Archivo :: Archivo(string ruta){
    this->abierto = true;
    abrir_archivo(ruta);
    this-> linea = linea;
}

Archivo :: ~Archivo(){
    this->cerrar_archivo(); // preguntar
}

void Archivo :: abrir_archivo(string ruta){
    
    if(this->abierto){
        cout << "exito al abrir el archivo" << endl;
        archivo.open(ruta);
        abierto = true;
    }

    if(archivo.fail()){
        cout << "no abrio el archivo" << endl;
        abierto = false;
    }

}
//preguntar eliminar este metodo
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
