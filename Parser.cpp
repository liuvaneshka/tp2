#include <iostream>
#include "Parser.h"
#include "CONSTANTES.h"

using namespace std;

Lista<Escritor*>* Parser::procesar_escritor(string ruta, Lista<Escritor*> *lista_escritores){

    string nombre, nacionalidad, lectura;
    int nacimiento, fallecimiento;

    Archivo entrada(ruta);

    while (!entrada.final_archivo()){
        lectura = entrada.leer_linea();
        if(!lectura.empty()){
            nombre = entrada.leer_linea();
            nacionalidad = entrada.leer_linea();
            lectura = entrada.leer_linea();

            if(!lectura.empty()) {

                nacimiento = atoi(lectura.c_str());
                lectura = entrada.leer_linea();

                if (!lectura.empty() && (!entrada.final_archivo())) {
                    fallecimiento = atoi(lectura.c_str());
                }
                else
                    fallecimiento = DESCONOCIDO;
            }
            else{
                nacimiento = DESCONOCIDO;
                fallecimiento = DESCONOCIDO;
            }
            Escritor* escritor = new Escritor(nombre, nacionalidad, nacimiento, fallecimiento);
            almacenar_escritor(escritor, lista_escritores);
        }
    }
    entrada.cerrar_archivo();
    return lista_escritores;
}

Lista<Lectura*>* Parser::procesar_lectura(string ruta, Lista<Lectura*> *lista_lecturas, Lista<Escritor*> *lista_escritores){

    Escritor* escritor;
    string dato, titulo, tipo, libro, tema_linea;
    generos genero;
    int minutos, anio, versos;

    Archivo entrada(ruta);

    while (!entrada.final_archivo()){
        dato = entrada.leer_linea();

        if(!dato.empty()){
            tipo = dato;
            titulo = entrada.leer_linea();

            dato = entrada.leer_linea();
            minutos = atoi(dato.c_str());

            dato = entrada.leer_linea();
            anio = atoi(dato.c_str());

            dato = entrada.leer_linea();

            if(tipo == POEMA){
                versos = atoi(dato.c_str());

                dato = entrada.leer_linea();
                escritor = obtener_escritor(dato, lista_escritores);

                Poema* poema = new Poema(titulo, escritor, anio, minutos, versos);
                almacenar_lectura(poema, lista_lecturas);
            }
            else if(tipo == NOVELA){
                genero = obtener_genero(dato);

                if (genero == HISTORICA) {
                    tema_linea = entrada.leer_linea();

                    dato = entrada.leer_linea();
                    escritor = obtener_escritor(dato, lista_escritores);

                    Novela_historica* historica = new Novela_historica(titulo, escritor, anio, minutos, tema_linea);
                    almacenar_lectura(historica, lista_lecturas);
                }
                else{
                    dato = entrada.leer_linea();
                    escritor = obtener_escritor(dato, lista_escritores);

                    Novela* novela = new Novela(titulo, escritor, anio, minutos, genero);
                    almacenar_lectura(novela, lista_lecturas);
                }

            }
            else if(tipo == CUENTO){
                libro = dato;

                dato = entrada.leer_linea();
                escritor = obtener_escritor(dato, lista_escritores);

                Cuento* cuento = new Cuento(titulo, escritor, anio, minutos, libro);
                almacenar_lectura(cuento, lista_lecturas);
            }
        }
    }
    entrada.cerrar_archivo(); // Probar si es necesario esto o si funciona con el destructor de Archivo
    return lista_lecturas;
}


generos Parser::obtener_genero(string genero) {
    generos numero_genero;

    if (genero == "DRAMA")
        numero_genero = DRAMA;
    else if (genero == "COMEDIA")
        numero_genero = COMEDIA;
    else if (genero == "FICCION")
        numero_genero = FICCION;
    else if (genero == "SUSPENSO")
        numero_genero = SUSPENSO;
    else if (genero == "TERROR")
        numero_genero = TERROR;
    else if (genero == "ROMANTICA")
        numero_genero = ROMANTICA;
    else if (genero == "HISTORICA")
        numero_genero = HISTORICA;

    return numero_genero;
}

void Parser::almacenar_escritor(Escritor* escritor, Lista<Escritor*> *lista_escritores){
    lista_escritores->alta(escritor);
}

void Parser::almacenar_lectura(Lectura* lectura, Lista<Lectura*> *lista_lecturas){
    int posicion_correcta = obtener_posicion_correcta(lectura, lista_lecturas);
    lista_lecturas->alta(lectura, posicion_correcta);
}

int Parser::obtener_posicion_correcta(Lectura* lectura, Lista<Lectura*> *lista_lecturas){
    int indice = 1;

    if (!lista_lecturas->vacia()){
        lista_lecturas->inicializar();

        while(lista_lecturas->hay_actual() && lectura->comparar_lecturas(lista_lecturas->consultar(indice)) != -1){
            indice++;
            lista_lecturas->siguiente();
        }
    }
    return indice;
}

bool Parser::verificar_escritor(string linea_escritor){
    return linea_escritor != "ANONIMO";
}

Escritor* Parser::rastrear_escritor(int codigo, Lista<Escritor*> *lista_escritores){
    return lista_escritores->consultar(codigo);
}

Escritor* Parser::obtener_escritor(string linea, Lista<Escritor*> *lista_escritores){
    int referencia_escritor;
    Escritor* escritor;

    if (verificar_escritor(linea)){
        referencia_escritor = obtener_referencia(linea);
        escritor = rastrear_escritor(referencia_escritor, lista_escritores);
    }
    else
        escritor = nullptr;
    return escritor;
}

int Parser::obtener_referencia(string linea) {
    string numero;
    int i = 0;

    while(linea[i] != ')'){
        if(linea[i] != '(')
            numero += linea[i];
        i++;
    }
    return (int) atoi(numero.c_str());
}
