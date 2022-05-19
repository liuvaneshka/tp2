//
// Created by Tiago Sandoval on 17/05/2022.
//

#ifndef TP2_ESCRITOR_H
#define TP2_ESCRITOR_H
#include <iostream>

class Escritor {

private:
    std::string nombre_apellido;
    std::string nacionalidad;
    int anio_nacimiento;
    int anio_fallecimiento;

public:
    Escritor(std::string nombre, std::string nac, int an, int af);
    Escritor(std::string nombre, int an, int af);
    ~Escritor(){};
};


#endif //TP2_ESCRITOR_H
