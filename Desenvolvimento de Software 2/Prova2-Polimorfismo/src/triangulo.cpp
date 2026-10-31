#include "triangulo.h"
#include <cmath>

Triangulo::Triangulo(std::string cor, unsigned int aresta1, unsigned int aresta2, unsigned int aresta3): \
Forma2D("triangulo",cor), _aresta1(aresta1), _aresta2(aresta2), _aresta3(aresta3) {}

double Triangulo::get_area() {
    double semiPerimetro = get_perimetro()/2;
    double resultado = sqrt(semiPerimetro * (semiPerimetro - _aresta1) * (semiPerimetro - _aresta2) * (semiPerimetro - _aresta3));
    return resultado;
}

double Triangulo::get_perimetro(){
    return (_aresta1+_aresta2+_aresta3);
}




