#ifndef PDS2_PROVA2_CUBO
#define PDS2_PROVA2_CUBO

#include "forma3d.h"

class Cubo: public Forma3D{
private:
   unsigned int _aresta;
public:
   Cubo(std::string cor,unsigned int aresta);
   double get_volume() override;
};

#endif