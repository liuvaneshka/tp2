#include <iostream>
#include "Menu.h"
#include "Escritor.h"
#include "Cuento.h"
#include "Archivo.h"

using namespace  std;

int main() {

    string archivo_lecturas = "Lecturas.txt";
    string archivo_autores = "Autores.txt";

    Archivo ar_lec(archivo_lecturas), ar_au(archivo_autores);
    //ar_lec.parserdatos();
    cout << "Escritores: " <<  endl;
    ar_lec.mostrar_datos();
    cout << "Autores: " <<  endl;
    ar_au.mostrar_datos();

    return 0;
}
