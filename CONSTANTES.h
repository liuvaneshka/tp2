#ifndef __CONSTANTES_H__
#define __CONSTANTES_H__

#include <iostream>
using namespace std;

// Programa
enum generos {DRAMA = 1, COMEDIA, FICCION, SUSPENSO,
              TERROR, ROMANTICA, HISTORICA};

const std::string POEMA = "P";
const std::string NOVELA = "N";
const std::string CUENTO = "C";

const int DESCONOCIDO = -1;

//Nombres archivos
const string ARCHIVO_LECTURAS = "Lecturas.txt";
const string ARCHIVO_ESCRITORES = "Autores.txt";

//Opciones
const string OPCIONES [] = {"Agregar una nueva lectura",
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

const int CANT_OPCIONES = 12;

//colores
const string NEGRO = "\e[1;30m";
const string ROJO = "\e[1;31m";
const string AZUL = "\e[1;34m";
const string VERDE = "\e[1;32m";
const string AMARILLO = "\e[1;33m";
const string VIOLETA = "\e[1;35m";

#endif // __CONSTANTES_H__
