#include <iostream>
#include "lista.h"

using namespace std;

int main(){
    Lista <int> lista;

    lista.alta(5, 1);
    lista.alta(8, 2);
    lista.alta(3, 2);
    lista.alta(9, 1);

    for (int i = 1; i <= lista.obtener_tamanio() - 1; i++){
        cout << lista.consultar(i) << " - ";
    }
    cout << lista.consultar(lista.obtener_tamanio()) << endl;

    lista.baja(4);
    cout << "Luego de la baja en la ultima posicion..." << endl;
    lista.baja(1);
    cout << "Luego de la baja en la primera posicion..." << endl;


    for (int i = 1; i <= lista.obtener_tamanio() - 1; i++){
        cout << lista.consultar(i) << " - ";
    }
    cout << lista.consultar(lista.obtener_tamanio()) << endl;

    cout << '\n';

    Lista <char> lista1;
    lista1.alta('o', 1);
    lista1.alta('l', 2);
    lista1.alta('a', 3);
    lista1.alta('h', 1);

    for (int i = 1; i <= lista1.obtener_tamanio() - 1; i++){
        cout << lista1.consultar(i) << " - ";
    }
    cout << lista1.consultar(lista1.obtener_tamanio()) << endl;

    lista1.baja(1);
    cout << "Luego de la baja en la primera posicion..." << endl;
    lista1.baja(2);
    cout << "Luego de la baja en la nueva segunda posicion..." << endl;


    for (int i = 1; i <= lista1.obtener_tamanio() - 1; i++){
        cout << lista1.consultar(i) << " - ";
    }
    cout << lista1.consultar(lista1.obtener_tamanio()) << endl;

    return 0;
}