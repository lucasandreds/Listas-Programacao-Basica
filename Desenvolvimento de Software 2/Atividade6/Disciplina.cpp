#include "Disciplina.hpp"


Disciplina::Disciplina(std::string codigo, std::string nome){
    this->codigo = codigo;
    this->nome = nome;
}

void Disciplina::inserir_alocacao(std::string dia, std::string horario, std::string sala){
    alocacao.push_back(Alocacao(dia,horario,sala));
}

void Disciplina::remover_alocacao(std::string horario){
    int posicao = 0;
    bool encontrouPosicao = false;
    while(posicao < alocacao.size() && !encontrouPosicao){
        if(alocacao.at(posicao).get_horario().compare(horario)==0){
            encontrouPosicao = true;
        }else{
            posicao++;
        }
    }

    alocacao.erase(alocacao.begin() + posicao);
}

void Disciplina::imprimir_alocacao(){
    std::set<std::string> horarios;
    bool encontrouPosicao;

    for(int i = 0; i < alocacao.size();i++){
        horarios.insert(alocacao.at(i).get_horario());
    }

    for(std::string horario: horarios){
        encontrouPosicao = false;
        for(int posicao = 0; (posicao < alocacao.size()) && (!encontrouPosicao); posicao++){
            if(alocacao.at(posicao).get_horario().compare(horario) == 0){
                bool encontrouPosicao = true;
                std::cout << codigo << " " << nome << " "; 
                alocacao.at(posicao).imprimir_dados();
            }
        }
    }

}

int Disciplina::get_quantidade_alocacoes(){
    return alocacao.size();
}

std::string Disciplina::get_codigo(){
    return codigo;
}