#ifndef NAVE_H
#define NAVE_H

#include "ponto.h"
#include <iostream>

struct Nave{
    Ponto2D posicao;
    double forca;
    double energia;

    Nave(Ponto2D posicao, double forca);
    Nave(Ponto2D posicao);
    Nave();
    void mover(double dx, double dy);
    double calcular_distancia(Nave nave);
    int determinar_indice_nave_mais_proxima(Nave naves[], int n);
    void atacar(Nave naves[], int n);
    void imprimir_status();
};


#endif