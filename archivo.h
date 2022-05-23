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

    /*post: Crea el objeto.
    */
    Archivo(string ruta);

    /*post: destruye el archivo.
    */
    ~Archivo();

    /*post: Abre el archivo de la ruta en modo lectura
    */
    void abrir_archivo(string ruta);

    /*pre: El archivo debe estar abierto
      post: Cierra el archivo
    */
    void cerrar_archivo();

    /*post: Si el archivo esta abierto devuelve true, de lo contrario   false
    */
    bool esta_abierto();

    /*pre: : El archivo debe estar abierto
     post: Si se llegó al final del archivo devuelve true, de lo contraro false
    */
    bool final_archivo();
    /*pre: El archivo debe estar abierto
      post: Lee la sigiente linea del archivo
    */
    string leer_linea();
};
#endif // ARCHIVOS_H