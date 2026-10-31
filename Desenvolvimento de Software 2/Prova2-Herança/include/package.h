#ifndef PROVA2_PDS2_PACKAGE_H
#define PROVA2_PDS2_PACKAGE_H

#include <string>

class Package{
private:
    std::string _nome;
    std::string _endereco;
    unsigned int _peso;
    unsigned int _custo;
public:
    Package(unsigned int peso,unsigned int custo,std::string nome, std::string endereco);
    virtual double calculate_cost();
    unsigned int getPeso();
    unsigned int getCusto();
    std::string getNome();
    std::string getEndereco();
    virtual ~Package(){}
};


#endif