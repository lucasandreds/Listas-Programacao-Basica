#ifndef DISCIPLINA_H
#define DISCIPLINA_H

#include <vector>
#include <set>
#include "Alocacao.hpp"

class Disciplina{
    private:
        std::string codigo,nome;
        std::vector<Alocacao> alocacao;
    public:
        Disciplina(std::string codigo, std::string nome);
        void inserir_alocacao(std::string dia, std::string horario, std::string sala);
        void remover_alocacao(std::string horario);
        void imprimir_alocacao();
        int get_quantidade_alocacoes();
        std::string get_codigo();
};


#endif