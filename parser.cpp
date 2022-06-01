#include <iostream>
#include "parser.h"
#include "CONSTANTES.h"

using namespace std;

Lista<Escritor*> Parser::procesar_escritor(string ruta, Lista<Escritor*> &lista_escritores){

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

                if (!lectura.empty()) {
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

Lista<Lectura*> Parser::procesar_lectura(string ruta, Lista<Lectura*> &lista_lecturas, Lista<Escritor*> &lista_escritores){

    Escritor* escritor;
    string dato, titulo, tipo, libro, tema_linea;
    generos genero;
    int minutos, anio, versos;

    Archivo entrada(ruta);

    while (!entrada.final_archivo()){
        dato = entrada.leer_linea();

        if(!dato.empty()){
            cout << "-----------nueva lectura tipo : " << dato << endl;
            tipo = dato;
            titulo = entrada.leer_linea();
            cout << "titulo:  "  << titulo << endl;

            dato = entrada.leer_linea();
            minutos = atoi(dato.c_str());
            cout << "minutos: "  << minutos << endl;

            dato = entrada.leer_linea();
            anio = atoi(dato.c_str());
            cout << "anio: "  << anio << endl;

            dato = entrada.leer_linea();

            if(tipo == POEMA){
                versos = atoi(dato.c_str());
                dato = entrada.leer_linea();
                escritor = obtener_escritor(dato, lista_escritores);
                Poema* poema = new Poema(titulo, escritor, anio, minutos, versos);      // El escritor se pasa sin el & xq ya es un puntero
                almacenar_lectura(poema, lista_lecturas);           // si pongo &lista_lecturas dá error
            }
            else if(tipo == NOVELA){
                genero = obtener_genero(dato);
                cout << "genero: " << genero << endl;
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
                    cout<< "construyo lectura "<< endl;
                    almacenar_lectura(novela, lista_lecturas);
                }

            }
            else if(tipo == CUENTO){
                libro = dato;
                cout << "libro: "  << libro  << endl;
                dato = entrada.leer_linea();
                escritor = obtener_escritor(dato, lista_escritores);
                Cuento* cuento = new Cuento(titulo, escritor, anio, minutos, libro);
                cout<< "construyo"<< endl;
                almacenar_lectura(cuento, lista_lecturas);
            }
        }
    }
    entrada.cerrar_archivo(); // esto o destructor
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

void Parser::almacenar_escritor(Escritor* escritor, Lista<Escritor*> &lista_escritores){
    lista_escritores.alta_al_final(escritor);
}

void Parser::almacenar_lectura(Lectura* lectura, Lista<Lectura*> &lista_lecturas){
    cout << "metodo almacenar lectura " <<endl;
    int posicion_correcta = obtener_posicion_correcta(lectura, lista_lecturas);
    cout << "posicion corrcta      " << posicion_correcta << endl;
    lista_lecturas.alta(lectura, posicion_correcta);
    cout << "********almaceno con exito" <<endl;

}

int Parser::obtener_posicion_correcta(Lectura* lectura, Lista<Lectura*> &lista_lecturas){
    int indice = 1;


    lista_lecturas.inicializar();
    // lo comente xq no continuaba agreganfo lecturas, no se xq me arroja error en obtener sig
    // antes de comentar no agregaba ninguna lectura ni la primera
    // ahora cuando se agrega, el error sale al recorrer lista de escirtores
    // relacinado al metodo obtener_siguiente() dentro de nodo
    // ya que despoues de no tener un sig, explota y arroja un segmentayion fault

/*
    while(lista_lecturas.hay_siguiente() && lectura->comparar_lecturas(lista_lecturas.consultar(indice)) != -1){
        cout << "entro while obtener posicion correcta " << endl;
        indice++;
        lista_lecturas.siguiente();
    }
*/
    cout << lectura << endl;
    return indice;
}

bool Parser::verificar_escritor(string linea_escritor){
    return linea_escritor != "ANONIMO";
}

Escritor* Parser::rastrear_escritor(int codigo, Lista<Escritor*> &lista_escritores){
    return lista_escritores.consultar(codigo);
}

Escritor* Parser::obtener_escritor(string dato, Lista<Escritor*> &lista_escritores){
    int referencia_escritor;
    Escritor* escritor;

    if (verificar_escritor(dato)){
        referencia_escritor = obtener_referencia(dato);
        cout<<"referencia autor: "<<referencia_escritor<<endl;
        escritor = rastrear_escritor(referencia_escritor, lista_escritores);
    }
    else
        escritor = nullptr;
    cout << "escritor: " << escritor << endl;
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
