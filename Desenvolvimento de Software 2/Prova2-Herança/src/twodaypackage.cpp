#include "twodaypackage.h"

TwoDayPackage::TwoDayPackage(unsigned int peso,unsigned int custo,unsigned int taxa_fixa,std::string nome, std::string endereco): \
Package(peso,custo,nome,endereco), _taxa_fixa(taxa_fixa) {}

double TwoDayPackage::calculate_cost(){
    return (_taxa_fixa + Package::calculate_cost());
}
