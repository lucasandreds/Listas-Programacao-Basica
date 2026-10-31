#include "quadrado.h"

Quadrado::Quadrado(std::string cor, unsigned int aresta): Forma2D("quadrado",cor), _aresta(aresta) {}

double Quadrado::get_area(){
    return (_aresta * _aresta);
}

double Quadrado::get_perimetro(){
    return (4 * _aresta);
}