#include "ListaProcessos.hpp"

void ListaProcessos::adicionar_processo(Processo proc){
    int posicao = 0;
    bool encontrouPosicao = false;
    while(posicao < processos.size() && !encontrouPosicao){
        if(proc.get_prioridade() > processos.at(posicao).get_prioridade()){
            encontrouPosicao = true;
        }else{
            posicao++;            
        }
    }

    processos.insert(processos.begin() + posicao,proc);
}

Processo ListaProcessos::remover_processo_maior_prioridade(){
    Processo excluido = processos.at(0);
    processos.erase(processos.begin());
    return excluido;
}
Processo ListaProcessos::remover_processo_menor_prioridade(){
    Processo excluido = processos.back();
    processos.pop_back();
    return excluido;
}

Processo ListaProcessos::remover_processo_por_id(int id){
    int posicao = 0;
    for (Processo processo : processos){
        if(processo.get_id() == id){
            Processo excluido = processo;;
            processos.erase(processos.begin() + posicao);
            return processo;
        }
        posicao++;
    }
    return Processo(0,"",0);
}

void ListaProcessos::imprimir_lista(){
    for (Processo processo : processos){
        processo.imprimir_dados();
    }
}