#ifndef PDS2_PROVA2_FORMA2D
#define PDS2_PROVA2_FORMA2D

#include "forma.h"

class Forma2D: public Forma {
private:
public:
    Forma2D(std::string nome,std::string cor);
    virtual double get_area() = 0;
    virtual double get_perimetro() = 0;
};

#endif