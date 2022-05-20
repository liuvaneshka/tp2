#include <iostream>
#include <string>
#include "lectura.h"
#include "novela.h"
#include "novela_historica.h"
#include "cuento.h"
#include "poema.h"
using namespace std;

int main(){

    // Creo algunos escritores
    Escritor autor1("José Martinez", "Argentino", 1920, 2000);
    Escritor autor2("Julia Rossenwasser", "Alemana", 1995, -1);
    Escritor autor3("Donato Di Santis ", "Italiano", -1, 2000);
    Escritor autor4("Tamara Sosa ", "¿?", 1890, 1940);

    //Muestro los escritores
    autor1.mostrar_escritor();
    autor2.mostrar_escritor();
    autor3.mostrar_escritor();
    autor4.mostrar_escritor();
    cout << "\n";

    //Pruebo métodos de escritor
    cout << "Busco nombre de autor1: " << autor1.obtener_nombre() << endl;
    cout << "\n";
    cout << "Busco nacionalidad de autor2: " << autor3.obtener_nacionalidad() << endl;
    cout << "Busco nacionalidad de autor4 sin nacionalidad: " << autor4.obtener_nacionalidad() << endl;
    cout << "\n";
    cout << "Busco nacimiento de autor1: " << autor1.obtener_anio_nacimiento() << endl;
    cout << "Busco nacimiento de autor3 sin nacimiento: " << autor3.obtener_anio_nacimiento() << endl;
    cout << "\n";
    cout << "Busco fallecimiento de autor2: " << autor2.obtener_anio_fallecimiento() << endl;
    cout << "Busco fallecimiento de autor4: " << autor4.obtener_anio_fallecimiento() << endl;
    cout << "\n";

    // MOdifico el fallecimiento de un escritor y lo imprimo
    autor1.modificar_fallecimiento(2010);
    cout << "El nuevo fallecimiento del autor1 es: " << autor1.obtener_anio_fallecimiento() << endl;
    cout << "\n";
    autor1.mostrar_escritor();
    cout << "\n";

    // Creo novelas historicas
    Novela_historica nh1("El cruce", &autor1, 1950, 3000, "El cruce de los andes de San Martin");
    Novela_historica nh2("LA HISTORIA", nullptr, 1920, 4000, "La hist argentina desde 1800 al 2000");
    Novela_historica nh3("El camino", &autor1, 1962, 3500, "Biografia de Manuel Belgrano");
    Novela_historica nh4("Al Peru", nullptr, 1970, 2000, "Histroia de San Martin con Bolivar durante la liberacion");

    // Muestro las novelas historicas
    nh1.mostrar_lectura();
    cout << "\n";
    nh2.mostrar_lectura();
    cout << "\n";
    nh3.mostrar_lectura();
    cout << "\n";
    nh4.mostrar_lectura();
    cout << "\n";


    //Pruebo lops metdoos de Novela_historicas y los heredados
    cout << "Muestro la novela llamada: " << nh1.obtener_titulo() << " cuyo tema es: " << nh1.obtener_tema() << endl;
    cout << "Muestro la novela de: " << nh2.obtener_autor()->obtener_nombre() << " cuyo tema es: " << nh1.obtener_tema() << endl;
    cout << "Muestro la novela del: " << nh3.obtener_anio() << " cuyo tema es: " << nh1.obtener_tema() << endl;
    cout << "Muestro la novela de: " << nh4.obtener_autor()->obtener_nombre() << " cuyo tema es: " << nh1.obtener_tema() << endl;       // ERROR!!!!
    cout << "\n";


    // Creo novelas
    Novela novela1("el fantasma", &autor1, 1960, 1000, TERROR);
    Novela novela2("El amor", nullptr, 2000, 2500, DRAMA);
    Novela novela3("SuperHeroe", &autor4, 1930, 500, FICCION);
    Novela novela4("Desues de ti", &autor3, 1980, 2300, ROMANTICA);
    Novela novela5("La casa", &autor2, 2010, 2300, SUSPENSO);
    Novela novela6("reir y reir", nullptr, 2010, 1200, COMEDIA);

    //Las muestro
    novela1.mostrar_lectura();
    cout << "\n";
    novela2.mostrar_lectura();
    cout << "\n";
    novela3.mostrar_lectura();
    cout << "\n";
    novela4.mostrar_lectura();
    cout << "\n";
    novela5.mostrar_lectura();
    cout << "\n";
    novela6.mostrar_lectura();
    cout << "\n";

    // Pruebo metodods de NOvela y metodos heredados de Lectura
    cout << " El genero de la novela1 llamada " << novela1.obtener_titulo() << " es " << novela1.obtener_genero() << endl;
    cout << " El genero de la novela2 del anio " << novela2.obtener_anio() << " es " << novela2.obtener_genero() << endl;
    cout << " El genero de la novela3 es " << novela3.obtener_genero() << endl;
    cout << " El genero de la novela4 es " << novela4.obtener_genero() << endl;


    // Creo cuentos
    Cuento c1("el flautista", &autor1, 1989, 1000, "libro de cuentos");
    Cuento c2("los tres chanchitos", nullptr, 1970, 500, "cuento para niños");
    Cuento c3("dracula", &autor3, 1970, 1200, "cuentos de miedo");
    Cuento c4("blancanieves", nullptr, 1960, 1500, "princesas y otros");

    // Muestro los cuentos
    c1.mostrar_lectura();
    cout << "\n";
    c2.mostrar_lectura();
    cout << "\n";
    c3.mostrar_lectura();
    cout << "\n";
    c4.mostrar_lectura();
    cout << "\n";

    //Pruebo métodos de Cuento y metodo heredado obtener_titulo()
    cout << "El libro donde esta " << c1.obtener_titulo() << "es: " << c1.obtener_libro() << endl;
    cout << "El libro donde esta " << c2.obtener_titulo() << "es: " << c2.obtener_libro() << endl;
    cout << "El libro donde esta " << c3.obtener_titulo() << "es: " << c3.obtener_libro() << endl;
    cout << "El libro donde esta " << c4.obtener_titulo() << "es: " << c4.obtener_libro() << endl;
    cout << "\n";


    // Creo poemas
    Poema p1("el gran amor", nullptr, 2000, 3, 10);
    Poema p2("mañana", autor2, 2002, 1, 6);
    Poema p3("memorias del pasado", autor4, 1900, 2, 8);
    Poema p4("azul", nullptr, 1999, 5, 25);
    Poema p5("el atardecer", autor1, 1950, 3, 9);

    // Muestro los poemas
    p1.mostrar_lectura();
    cout << "\n";
    p2.mostrar_lectura();
    cout << "\n";
    p3.mostrar_lectura();
    cout << "\n";
    p4.mostrar_lectura();
    cout << "\n";
    p5.mostrar_lectura();
    cout << "\n";

    // Imprimo la cant de versos que posee cada uno probandi tambien otros metdoso heredados
    cout << "el poema "<< p1.obtener_titulo() << " escrito por: " << p1.obtener_autor().obtener_nombre() << " posee " << p1.obtener_versos() << " versos" << endl;
    cout << "el poema "<< p2.obtener_titulo() << " escrito en: " << p2.obtener_anio() << " posee " << p2.obtener_versos() << " versos" << endl;
    cout << "el poema "<< p3.obtener_titulo() << " cuyos minutos de lectura es : " << p1.obtener_minutos() << " posee " << p3.obtener_versos() << " versos" << endl;
    cout << "Los ultimos dos poemas poseen: " << p4.obtener_versos() << " y " << p5.obtener_versos() << " respectivamente" << endl;
    cout << "\n";


    return 0;
}