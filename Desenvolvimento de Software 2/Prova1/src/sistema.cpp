#include "../include/sistema.h"
#include <iostream>

Sistema::Sistema(double preco_corrida) {
    if(preco_corrida <= 0) throw preco_negativo_e();
    _preco_corrida = preco_corrida;
}

Cliente *Sistema::cadastra_cliente(std::string nome) {
    if (_clientes.count(nome) > 0) {
        throw cliente_ja_existe_e();
    }

    Cliente *cliente = new Cliente(nome);
    _clientes.insert({nome,cliente});
    return cliente;
}

void Sistema::adicionar_carro(std::string cor, unsigned int id) {
    _frota.cadastrar_carro(cor, id);
}

Carro *Sistema::busca_uber(std::string nome) {
    
    if (_clientes.count(nome) == 0) {
        throw cliente_nao_existe_e();
    }
    
    Carro *pointer_car = nullptr;
    Cliente *c = _clientes.at(nome);

    if (c->get_saldo() == 0) {
        throw sem_saldo_e();
    }

    if (c->get_saldo() < _preco_corrida) {
        throw sem_saldo_e();
    }

    Carro car = _frota.alocar_carro();

    c->remover_saldo(_preco_corrida);
    
    Carro *carro = new Carro(car.get_cor(),car.get_id());
    _carros_alocados.insert({car.get_id(),carro});
    _carros_alocados.at(car.get_id())->seta_ocupado();
    
    return _carros_alocados.at(car.get_id());
}

Sistema::~Sistema(){
    auto it = _clientes.begin();
    for(it; it != _clientes.end(); it++ ){
        delete it->second;
    }
    
    auto it2 = _carros_alocados.begin();
    for(it2; it2 != _carros_alocados.end(); it2++ ){
        delete it2->second;
    }
}