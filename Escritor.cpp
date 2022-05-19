//
// Created by Tiago Sandoval on 17/05/2022.
//

#include "Escritor.h"

Escritor::Escritor(std::string nombre, int an, int af) {
    nombre_apellido = nombre;
    anio_nacimiento = an;
    anio_fallecimiento = af;
}

Escritor::Escritor(std::string nombre, std::string nac, int an, int af) {
    nombre_apellido = nombre;
    nacionalidad = nac;
    anio_nacimiento = an;
    anio_fallecimiento = af;
}
