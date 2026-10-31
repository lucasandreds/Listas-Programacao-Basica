#ifndef PDS2_SISTEMA_H
#define PDS2_SISTEMA_H

#include <map>
#include <string>

#include "cliente.h"
#include "frota.h"

class cliente_ja_existe_e {};
class cliente_nao_existe_e {};
class sem_saldo_e {};
class preco_negativo_e{};

/*
 * A classe sistema está ok de métodos e tads utilizados. Porém, ainda tem
 * tarefas aqui.
 *
 * TODO: 1. Faça um novo construtor que recebe o preco da corrida.
 *          - Crie uma nova exceção e lançe a mesma se o preço for <= 0.
 *       2. Documentar essa classe.
 *       3. Garantir que não tem bugs nem leaks
 */
class Sistema {
    private:
        std::map<std::string, Cliente *> _clientes;
        std::map<unsigned int, Carro*> _carros_alocados;
        Frota _frota;
        double _preco_corrida;
    public:
        /**
         * @brief Destroi o sistema com os clientes dados
        */
        ~Sistema();

        /**
         * @brief Constroi um sistema com o preço de corrida dado
         * @throws Lança uma excessão se o preço da corrida for negativo
        */
        Sistema(double preco_corrida);

        /**
         * @brief Adiciona um carro no sistema com a cor e o
         * ID único dado
         * @throw Lança uma excessão caso já existe um veículo com o ID dado
        */
        void adicionar_carro(std::string cor, unsigned int id);

        /**
         * @brief Cadastra no sistema um cliente com o login dado
         * @throw Lança uma excessão caso o login já existe no sistema
        */
        Cliente *cadastra_cliente(std::string nome);

        /**
         * @brief Busca no sistema um carro disponível para o cliente 
         * com o login dado
         * @throw Lança uma excessão caso o cliente não exista 
         * @throw Lança uma excessão caso o cliente não possua saldo para
         * a viagem
        */
        Carro *busca_uber(std::string nome);
};

#endif