#ifndef PDS2_PROVA2_ESFERA
#define PDS2_PROVA2_ESFERA

#include "forma3d.h"

class Esfera: public Forma3D{
private:
    unsigned int _raio;
public:
   Esfera(std::string cor,unsigned int raio);
   double get_volume() override;
};

#endif