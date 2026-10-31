#include "cubo.h"

Cubo::Cubo(std::string cor,unsigned int aresta): Forma3D("cubo",cor), _aresta(aresta){}

double Cubo::get_volume(){
    return (_aresta * _aresta * _aresta);
}