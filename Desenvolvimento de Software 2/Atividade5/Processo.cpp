#include "Processo.hpp"

Processo::Processo(int id, std::string nome, int prioridade){
    this->id = id;
    this->nome = nome;
    this->prioridade = prioridade;
}

void Processo::imprimir_dados(){
    std::cout << id << " " << nome << " " << prioridade << std::endl;
}

int Processo::get_prioridade(){
    return prioridade;
}

int Processo::get_id(){
    return id;
}