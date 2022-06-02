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


//colores
const string NEGRO = "\e[1;30m";
const string ROJO = "\e[1;31m";
const string AZUL = "\e[1;34m";
const string VERDE = "\e[1;32m";
const string AMARILLO = "\e[1;33m";
const string VIOLETA = "\e[1;35m";

#endif // __CONSTANTES_H__
