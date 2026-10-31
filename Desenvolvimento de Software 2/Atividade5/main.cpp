// NÃO ALTERE ESSA LINHA
#include "avaliacao basica escalonador.hpp"
#include "ListaProcessos.hpp"

int main() {

    ListaProcessos lista;
    char comando;
    int id, prioridade;
    std::string nome;

    while(cin >> comando){
        switch (comando){
        case 'a':
            cin >> id >> nome >> prioridade;
            lista.adicionar_processo(Processo(id, nome, prioridade));
            break;
        case 'm':
            lista.remover_processo_maior_prioridade();
            break;
        case 'n':
            lista.remover_processo_menor_prioridade();
            break;
        case 'r':
            cin >> id;
            lista.remover_processo_por_id(id);
            break;
        case 'p':
            lista.imprimir_lista();
            break;
        case 'b':
            avaliacao_basica();
            break;   
        }
    }
    return 0;
}