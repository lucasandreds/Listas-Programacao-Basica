#ifndef LISTA_PROCESSOS
#define LISTA_PROCESSOS

#include "Processo.hpp"
#include <vector>

class ListaProcessos{
    private:
        std::vector<Processo> processos;
    public:
        void adicionar_processo(Processo proc);
        Processo remover_processo_maior_prioridade();
        Processo remover_processo_menor_prioridade();
        Processo remover_processo_por_id(int id);
        void imprimir_lista();
};


#endif