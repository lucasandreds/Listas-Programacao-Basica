#ifndef PONTO_H
#define PONTO_H

#include <cmath>

struct Ponto2D{
    double x,y;
    Ponto2D(int x, int y);
    Ponto2D();
    double calcular_distancia(Ponto2D ponto);
};


#endif