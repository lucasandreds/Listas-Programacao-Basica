#ifndef PDS2_PROVA2_TRIANGULO
#define PDS2_PROVA2_TRIANGULO

#include "forma2d.h"

class Triangulo: public Forma2D{
private:
    unsigned int _aresta1;
    unsigned int _aresta2;
    unsigned int _aresta3;
public:
    Triangulo(std::string cor, unsigned int aresta1, unsigned int aresta2, unsigned int aresta3);
    double get_area() override;
    double get_perimetro() override;
};

#endif