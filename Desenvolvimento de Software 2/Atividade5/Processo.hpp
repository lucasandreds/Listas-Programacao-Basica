#ifndef PDS2_PROCESSO
#define PDS2_PROCESSO

#include <string>
#include <iostream>

class Processo{
    private:
        int id;
        std::string nome;
        int prioridade;
    public:
        Processo(int id, std::string nome, int prioridade);
        void imprimir_dados();
        int get_prioridade();
        int get_id();
};

#endif