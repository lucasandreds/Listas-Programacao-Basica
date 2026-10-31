#include "QuadroAlocacao.hpp"


void QuadroAlocacao::inserir_alocacao(std::string codigo, std::string nome, std::string dia, std::string horario, std::string sala){
    if(quadro.count(codigo) <= 0){
        quadro.insert({codigo,Disciplina(codigo, nome)});
    }
    quadro.at(codigo).inserir_alocacao(dia,horario,sala);
}

void QuadroAlocacao::remover_alocacao_disciplina(std::string codigo, std::string horario){
    if(quadro.count(codigo) > 0){
        quadro.at(codigo).remover_alocacao(horario);
    }
}

std::vector<Disciplina> QuadroAlocacao::recuperar_disciplinas_mais_ofertadas(){

    int maior_disciplina_ofertada = 0;
    std::vector<std::string> codigos_disciplinas_ofertadas;

    auto iterator = quadro.begin();
    while(iterator != quadro.end()){
        int quantidade_alocacoes = iterator->second.get_quantidade_alocacoes();
        if(quantidade_alocacoes > maior_disciplina_ofertada){
            codigos_disciplinas_ofertadas.clear();
            codigos_disciplinas_ofertadas.push_back(iterator->first);
            maior_disciplina_ofertada = quantidade_alocacoes;

        }else if(quantidade_alocacoes == maior_disciplina_ofertada){
            codigos_disciplinas_ofertadas.push_back(iterator->first);
        }
        iterator = next(iterator);
    }

    std::vector<Disciplina> disciplinas_mais_ofertadas;
    for(std::string codigo_maior: codigos_disciplinas_ofertadas){
        disciplinas_mais_ofertadas.push_back(quadro.at(codigo_maior));
    }

    return disciplinas_mais_ofertadas;

}

void QuadroAlocacao::imprimir_alocacao_completa(){
    std::set<std::string> codigos;

    auto iterator = quadro.begin();
    while(iterator != quadro.end()){
        codigos.insert(iterator->first);
        iterator = next(iterator);
    }

    for(std::string codigo_ordenado: codigos){
        quadro.at(codigo_ordenado).imprimir_alocacao();
    }
}