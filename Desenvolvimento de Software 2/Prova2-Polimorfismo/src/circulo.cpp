#include "circulo.h"
#include <cmath>

Circulo::Circulo(std::string cor, unsigned int raio): Forma2D("circulo",cor), _raio(raio) {}

double Circulo::get_area(){
    return (M_PI * pow(_raio,2));
}

double Circulo::get_perimetro() {
    return (2 * M_PI * _raio);
}