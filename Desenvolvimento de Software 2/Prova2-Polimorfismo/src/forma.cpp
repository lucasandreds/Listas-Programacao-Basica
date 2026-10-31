#include "forma.h"

Forma::Forma(std::string nome,std::string cor): _nome(nome), _cor(cor) {}

std::string Forma::get_cor(){
    return _cor;
}

std::string Forma::get_nome(){
    return _nome;
}