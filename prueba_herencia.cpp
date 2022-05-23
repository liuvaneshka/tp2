#include <iostream>
#include <string>
#include "lectura.h"
#include "novela.h"
#include "novela_historica.h"
#include "cuento.h"
#include "poema.h"
using namespace std;

//IMPORTANTE!!!
/* 1) Cuando con una Lectura pongo obtener_autor() eso devuelve un puntero a autor, entonces luego tuve que hacer -> obtener_nombre()...
Sería conveniente agregarle un método a Lectura para obtener el nombre directamente? Ya que creo que el nombre va aser algo que se necesite varias veces
y entonces quizás se puede implemnetra ara al menos hacer mas directos estos llamados que se repiten usualmente*/
/* 2) Cuando llamo con una lectura a obtener_autor() y este es null se muestra 0x0 -> y si con un null llamo como explico en 2),
tira segmentation fault, dado que no puede obtener el nombre de algo que ni es un autor, como manejamos este caso? */
// 3) Puede ser que si implementamos 1) se resuelva 2) ?? Pense algo de este estilo -> lo implementé y FUNCIONA!!:
/*string Lectura::nombre_autor(){
    string nombre;
    if (obtener_autor())
        nombre = obtener_autor() -> obtener_nombre();
    else
        nombre = "Desconocido";
    return nombre
}
*/  // Sin embargo, estaba pensando y se debería hacer con cada atributo de Autor... Como se les ocurre sino solucionarlo?



int main(){

    // Creo algunos escritores
    Escritor autor1("José Martinez", "Argentino", 1920, 2000);
    Escritor autor2("Julia Rossenwasser", "Alemana", 1995, -1);
    Escritor autor3("Donato Di Santis ", "Italiano", -1, 2000);
    Escritor autor4("Tamara Sosa ", "¿?", 1890, 1940);

    //Muestro los escritores
    autor1.mostrar_escritor();
    cout << "\n";
    autor2.mostrar_escritor();
    cout << "\n";
    autor3.mostrar_escritor();
    cout << "\n";
    autor4.mostrar_escritor();
    cout << "\n";

    //Pruebo métodos de escritor
    cout << "Busco nombre de autor1: " << autor1.obtener_nombre() << endl;
    cout << "\n";
    cout << "Busco nacionalidad de autor2: " << autor2.obtener_nacionalidad() << endl;
    cout << "\n";
    cout << "Busco nacionalidad de autor4 sin nacionalidad: " << autor4.obtener_nacionalidad() << endl;
    cout << "\n";
    cout << "Busco nacimiento de autor1: " << autor1.obtener_anio_nacimiento() << endl;
    cout << "Busco nacimiento de autor3 sin nacimiento: " << autor3.obtener_anio_nacimiento() << endl;
    cout << "\n";
    cout << "Busco fallecimiento de autor2: " << autor2.obtener_anio_fallecimiento() << endl;
    cout << "Busco fallecimiento de autor4: " << autor4.obtener_anio_fallecimiento() << endl;
    cout << "\n";

    // Modifico el fallecimiento de un escritor y lo imprimo
    autor1.modificar_fallecimiento(2010);
    cout << "El nuevo fallecimiento del autor1 es: " << autor1.obtener_anio_fallecimiento() << endl;
    cout << "\n";
    autor1.mostrar_escritor();
    cout << "\n\n";

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


    //Pruebo los metodos de Novela_historicas y los heredados
    cout << "Muestro la novela llamada: " << nh1.obtener_titulo() << " escrita por: " << nh1.nombre_autor() << " cuyo tema es: " << nh1.obtener_tema() << endl;
    cout << "Muestro la novela de: " << nh2.obtener_autor() << " cuyo tema es: " << nh1.obtener_tema() << endl;
    cout << "Muestro la novela del: " << nh3.obtener_anio() << " escrita por alguien de nacionalidad: " << nh3.obtener_autor()->obtener_nacionalidad() << " cuyo tema es: " << nh1.obtener_tema() << endl;
    cout << "Muestro la novela de: " << nh4.obtener_autor() << " cuyo tema es: " << nh1.obtener_tema() << endl;
    cout << "\n\n";


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
    cout << " El genero de la novela2 de " << novela2.obtener_autor() << " (NULL) es " << novela2.obtener_genero() << endl;
    cout << " El genero de la novela3 es " << novela3.obtener_genero() << endl;
    cout << " El genero de la novela4 es " << novela4.obtener_genero() << endl;
    cout << " El genero de la novela6 de " << novela6.obtener_autor() << " (NULL) es " << novela6.obtener_genero() << endl;

    cout << "\n";


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
    cout << "\n\n";


    // Creo poemas
    Poema p1("el gran amor", nullptr, 2000, 3, 10);
    Poema p2("mañana", &autor2, 2002, 1, 6);
    Poema p3("memorias del pasado", &autor4, 1900, 2, 8);
    Poema p4("azul", nullptr, 1999, 5, 25);
    Poema p5("el atardecer", &autor1, 1950, 3, 9);

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

    // Imprimo la cant de versos que posee cada uno probandi tambien otros metodos heredados
    cout << "el poema "<< p1.obtener_titulo() << " escrito por: " << p1.nombre_autor() << "(NULL) posee " << p1.obtener_versos() << " versos" << endl;
    cout << "el poema "<< p2.obtener_titulo() << " escrito en: " << p2.obtener_anio() << " posee " << p2.obtener_versos() << " versos" << endl;
    cout << "el poema "<< p3.obtener_titulo() << " cuyos minutos de lectura es : " << p3.obtener_minutos() << " posee " << p3.obtener_versos() << " versos" << endl;
    cout << "Los ultimos dos poemas poseen: " << p4.obtener_versos() << " y " << p5.obtener_versos() << " respectivamente" << endl;
    cout << "\n";

    return 0;
}