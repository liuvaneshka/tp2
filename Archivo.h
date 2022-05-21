//
// Created by liuvaneshka on 19/05/22.
//

#ifndef ARCHIVO_H
#define ARCHIVO_H


class Archivo {
private:

    ifstream archivo;
    bool abierto;

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
    string leer_dato_linea_en_blanco();
    /*post: Lee la sigiente linea del archivo
    */
    void mostrar_datos(); // adentro se puede pasar el template

};


#endif
