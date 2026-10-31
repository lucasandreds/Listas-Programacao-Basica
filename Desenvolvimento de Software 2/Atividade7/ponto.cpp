#include "ponto.h"

Ponto2D::Ponto2D(int x, int y){
    this->x = x;
    this->y = y;
}

Ponto2D::Ponto2D(){
    x = 0;
    y = 0;
}

double Ponto2D::calcular_distancia(Ponto2D Ponto){

    double resultado = sqrt(pow((Ponto.x - x),2) + pow((Ponto.y-y),2));

    return resultado;
}