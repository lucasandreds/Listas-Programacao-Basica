#ifndef PDS2_PROVA2_QUADRADO
#define PDS2_PROVA2_QUADRADO

#include "forma2d.h"

class Quadrado: public Forma2D{
private:
    unsigned int _aresta;
public:
    Quadrado(std::string cor, unsigned int aresta);
    double get_area() override;
    double get_perimetro() override;
};

#endif