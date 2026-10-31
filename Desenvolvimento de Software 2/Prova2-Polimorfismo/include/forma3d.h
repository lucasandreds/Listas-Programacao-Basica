#ifndef PDS2_PROVA2_FORMA3D
#define PDS2_PROVA2_FORMA3D

#include "forma.h"

class Forma3D: public Forma {
private:
public:
    Forma3D(std::string nome,std::string cor);
    virtual double get_volume() = 0;
};

#endif