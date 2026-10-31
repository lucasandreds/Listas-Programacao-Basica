#include <exception>
#include <iostream>

#include "../include/sistema.h"

int main() {
    Sistema sistema_uber = Sistema(5);
    try{
        sistema_uber = Sistema(-7);
    }catch(preco_negativo_e &e){
        //std::cout << "Impossível uma corrida com preço negativo" << std::endl ;
        //Teste para a exceção quando tenta inserir um valor negativo
    }

    sistema_uber.adicionar_carro("branco", 0);
    sistema_uber.adicionar_carro("verde", 2);
    sistema_uber.adicionar_carro("verde", 1);
    sistema_uber.adicionar_carro("vermelho", 10);

    try{
        sistema_uber.adicionar_carro("verde", 1);
    }catch(id_ja_existe_e &e){
        std::cout << "ID do carro já existe!" << std::endl;
    }

    Cliente *flavio = sistema_uber.cadastra_cliente("flavio@dcc");
    Cliente *ana = sistema_uber.cadastra_cliente("ana@dcc");
    Cliente *pedro = sistema_uber.cadastra_cliente("pedro@dcc");

    try {
        sistema_uber.cadastra_cliente("flavio@dcc");
    } catch (cliente_ja_existe_e &e) {
        std::cout << "O cliente já existe!" << std::endl;
    }

    try {
        flavio->adicionar_saldo(-2);
    } catch (impossivel_adicionar_saldo_negativo_e &e) {
        std::cout << "Não podemos adicionar saldo negativo" << std::endl;
    }

    flavio->adicionar_saldo(50);
    ana->adicionar_saldo(20);

    try {
        ana->remover_saldo(50);
    } catch (saldo_insuficiente_para_remocao_e &e) {
        std::cout << "Não posso remover saldo de valor 50 de ana" << std::endl;
    }
    Carro *cf = sistema_uber.busca_uber("flavio@dcc");
    std::cout << "Carro de placa " << cf->get_id();
    std::cout << " está ocupado? " << cf->ocupado() << std::endl;
    Carro *cf2 = sistema_uber.busca_uber("ana@dcc");
    std::cout << "Carro de placa " << cf2->get_id();
    std::cout << " está ocupado? " << cf2->ocupado() << std::endl;
    try{
        sistema_uber.busca_uber("pedro@dcc");
    }catch(sem_saldo_e &e){
        std::cout << "Não posso alocar um carro para pedro!" << std::endl;
        //Teste para a exceção quando não possui saldo para pagar o carro
    }
    try{
        sistema_uber.busca_uber("maria@dcc");
    }catch(cliente_nao_existe_e &e){
        //std::cout << "O usuário selecionado não existe no sistema" << std::endl;
        //Teste para a exceção quando o usuário não existe no sistema
    }

     Cliente *maria = sistema_uber.cadastra_cliente("teste@dcc");
     Cliente *ingrid = sistema_uber.cadastra_cliente("teste2@dcc");
     pedro->adicionar_saldo(10);
     maria->adicionar_saldo(5);
     ingrid->adicionar_saldo(30);

    Carro *cf3= sistema_uber.busca_uber("teste@dcc");
    Carro *cf4 = sistema_uber.busca_uber("pedro@dcc");
    
    try{
        Carro *cf5 = sistema_uber.busca_uber("teste2@dcc");
    }catch(zero_carros_disponiveis_e){
        //std::cout << "Não há carros disponiveis" << std::endl;
        //Teste para quando náo há carros disponiveis
    }

}