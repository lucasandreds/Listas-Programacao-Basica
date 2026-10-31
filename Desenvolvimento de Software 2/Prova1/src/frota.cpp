#include "../include/frota.h"
#include <iostream>

void Frota::cadastrar_carro(std::string cor, unsigned int id) {
    for(Carro carro: _carros){
        if(carro.get_id() == id){
            throw id_ja_existe_e();
        }
    }
    Carro c = Carro(cor,id);
    _carros.push_back(c);
}

Carro Frota::alocar_carro() {
    if (_carros.empty()) {
        throw zero_carros_disponiveis_e();
    }
    
    int posicao = 0;
    Carro *alocado = nullptr;
    
    Carro car = _carros.at(posicao);
    alocado = &car;

    while(alocado->ocupado()){
        posicao++;
        if(posicao >= _carros.size()){
            throw zero_carros_disponiveis_e();
        }
        alocado = &(_carros.at(posicao));
    }
    
    _carros.at(posicao).seta_ocupado();
    Carro carro_alocado =  _carros.at(posicao);
    return carro_alocado;
}