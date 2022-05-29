#ifndef ARCHIVOS_H
#define ARCHIVOS_H
#include<iostream>
#include<string>       
#include<fstream>

using namespace std;

class Archivo{
private:

    ifstream archivo;
    bool abierto;
    string linea;

public:

    //PRE:
    //POST: Crea el objeto.
    Archivo(string ruta);

    //PRE:
    //POST: destruye el archivo.
    ~Archivo();

    //PRE:
    //POST: Abre el archivo de la ruta en modo lectura
    void abrir_archivo(string ruta);

    //PRE: El archivo debe estar abierto
    //POST: Cierra el archivo
    void cerrar_archivo();

    //PRE:
    //POST: Si el archivo esta abierto devuelve true, de lo contrario   false
    bool esta_abierto();

    //PRE: El archivo debe estar abierto
    //POST: Si se llegó al final del archivo devuelve true, de lo contraro false
    bool final_archivo();

    //PRE: El archivo debe estar abierto
    //POST: Lee la sigiente linea del archivo
    string leer_linea();
};
#endif // ARCHIVOS_H
