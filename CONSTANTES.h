#ifndef __CONSTANTES_H__
#define __CONSTANTES_H__

#include <iostream>
using namespace std;

enum generos {DRAMA = 1, COMEDIA, FICCION, SUSPENSO,
              TERROR, ROMANTICA, HISTORICA};

const std::string POEMA = "P";
const std::string NOVELA = "N";
const std::string CUENTO = "C";

const int DESCONOCIDO = -1;

const string ARCHIVO_LECTURAS = "Lecturas.txt";
const string ARCHIVO_ESCRITORES = "Autores.txt";

string OPCIONES [] = {"Agregar una nueva lectura",
                    "Quitar lectura",
                    "Agregar un escritor",
                    "Actualizar fallecimiento autor",
                    "Listar los escritores",
                    "Sortear una lectura",
                    "Listar lecturas",
                    "Listar lecturas por anio",
                    "Listar lecturas por escritor",
                    "Listar Novelas por genero",
                    "Listar proximas lecturas",
                    "Salir"};

#endif // __CONSTANTES_H__