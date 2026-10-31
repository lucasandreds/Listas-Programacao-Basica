#include "overnightpackage.h"

OverNightPackage::OverNightPackage(unsigned int peso,unsigned int custo,unsigned int taxa_quilo,std::string nome, std::string endereco):\
Package(peso,custo,nome,endereco), _taxa_quilo(taxa_quilo) {}

double OverNightPackage::calculate_cost(){
    return ((getCusto() + _taxa_quilo) * getPeso());
}
