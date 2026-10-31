#include "esfera.h"
#include <cmath>

Esfera::Esfera(std::string cor,unsigned int raio): Forma3D("esfera",cor), _raio(raio){}

double Esfera::get_volume(){
    double resultado = (4*  M_PI * pow(_raio,3))/3;
    return resultado;
}