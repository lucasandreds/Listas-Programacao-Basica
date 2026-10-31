#ifndef PROVA2_PDS2_OVERNIGHTPACKAGE_H
#define PROVA2_PDS2_OVERNIGHTPACKAGE_H

#include "package.h"

class OverNightPackage : public Package{
private:
    unsigned int _taxa_quilo;
public:
    OverNightPackage(unsigned int peso,unsigned int custo,unsigned int taxa_quilo,std::string nome, std::string endereco);
    virtual double calculate_cost() override;
    ~OverNightPackage(){}
};


#endif