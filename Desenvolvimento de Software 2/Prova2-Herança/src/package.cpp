#include "package.h"

Package::Package(unsigned int peso,unsigned int custo,std::string nome, std::string endereco):\
_nome(nome),_endereco(endereco),_peso(peso),_custo(custo) {
}

double Package::calculate_cost(){
    return (_peso*_custo);
}

unsigned int Package::getPeso(){
    return _peso;
}

unsigned int Package::getCusto(){
    return _custo;
}

std::string Package::getNome(){
    return _nome;
}

std::string Package::getEndereco(){
    return _endereco;
}