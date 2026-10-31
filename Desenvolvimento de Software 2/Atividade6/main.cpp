// NÃO ALTERE ESSA LINHA
#include "avaliacao_basica_alocacao.hpp"
#include "QuadroAlocacao.hpp"

int main() {

    QuadroAlocacao quadro;
    char comando;
    std::string codigo,nome,dia,horario,sala;
    std::vector<Disciplina> disciplinas_mais_ofertadas;

    while(cin >> comando){
        switch (comando){
        case 'a':
            cin >> codigo >> nome >> dia >> horario >> sala;
            quadro.inserir_alocacao(codigo,nome,dia,horario,sala);
            break;
        case 'm':
            disciplinas_mais_ofertadas.clear();
            disciplinas_mais_ofertadas = quadro.recuperar_disciplinas_mais_ofertadas();
            
            for(Disciplina disciplina: disciplinas_mais_ofertadas){
                disciplina.imprimir_alocacao();
            }
            break;
        case 'r':
            cin >> codigo >> horario;
            quadro.remover_alocacao_disciplina(codigo,horario);
            break;
        case 'p':
            quadro.imprimir_alocacao_completa();
            break;
        case 'b':
            avaliacao_basica();
            break;   
        }
    }

    return 0;
}