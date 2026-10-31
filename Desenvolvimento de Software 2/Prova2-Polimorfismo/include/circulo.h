#ifndef PDS2_PROVA2_CIRCULO
#define PDS2_PROVA2_CIRCULO

#include "forma2d.h"

class Circulo: public Forma2D{
private:
    unsigned int _raio;
public:
    Circulo(std::string cor, unsigned int raio);
    double get_area() override;
    double get_perimetro() override;
};

#endif