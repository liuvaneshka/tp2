#ifndef ARCHIVOS_H
#define ARCHIVOS_H
#include<iostream>
//#include<string>
#include<fstream>

using namespace std;

class Archivo{

private:

    ifstream archivo;
    bool abierto;
    string linea;

public:


    //PRE: ruta es una ruta válida.
    //POST: Crea un Archivo.
    Archivo(string ruta);

    //PRE: El objeto Archivo es un objeto válido.
    //POST: destruye el archivo.
    ~Archivo();

    //PRE: El objeto Archivo es un objeto válido.
    //POST: Abre el archivo de la ruta en modo lectura.
    void abrir_archivo(string ruta);

    //PRE: El objeto Archivo es un objeto válido y el mismo debe estar abierto.
    //POST: Cierra el archivo.
    void cerrar_archivo();

    //PRE: El objeto Archivo es un objeto válido.
    //POST: Si el archivo esta abierto devuelve true, false en caso contrario.
    bool esta_abierto();

    //PRE: El objeto Archivo es un objeto válido y el mismo debe estar abierto.
    //POST: Si se llegó al final del archivo devuelve true, de lo contraro false
    bool final_archivo();

    //PRE: El objeto Archivo es un objeto válido y el mismo debe estar abierto.
    //POST: Lee la sigiente linea del archivo.
    string leer_linea();

};
#endif // ARCHIVOS_H
