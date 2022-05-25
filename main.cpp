#include <iostream>
#include "cola.h"

using  namespace std;

int main(){
    Cola cola;

    cola.encolar(1);
    cola.encolar(2);
    cola.encolar(3);
    cola.encolar(4);
    cout << "El frente de la cola es: " << cola.consultar() << endl;

    while (! cola.vacia()){
        cola.desencolar();
        cout << "El nuevo frente de la cola es: " << cola.consultar() << endl;
    }
    return 0;
}