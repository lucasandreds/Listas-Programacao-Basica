#include "venda.hpp"

#include <cmath>
#include <iomanip>
#include <iostream>
#include <locale>

void Venda::adicionaCelular(const Celular& celular) {
  // TODO: Implemente este metodo
  m_celulares.push_back (celular);
}

void Venda::ordena() {
  // TODO: Implemente este metodo
  // Preste atencao no exemplo que a descricao utilizada na ordenacao considera
  // a fabricante antes do modelo do celular
  m_celulares.sort([](Celular &celular, const Celular &outro) { 
    return celular.operator<(outro);
    });
}

void Venda::recarregaEstoque(int cod, int qtd) {
  // TODO: Implemente este metodo
    for (auto it = m_celulares.begin(); it!=m_celulares.end(); it++){
        if(it->cod == cod){
            it->quantidade+=qtd;
            break;
        }
    }
}

void Venda::efetuaVenda(int cod, int qtd) {
    for (auto it = m_celulares.begin(); it!=m_celulares.end(); it++){
      if(it->cod == cod){
          if(it->quantidade >= qtd){
              it->quantidade-=qtd;
          }
          break;
      }
  }
  // TODO: Implemente este metodo
  /**
   * Observe na descricao do enunciado que nao e permita a venda de um modelo
   * cuja quantidade seja maior que a quantidade atual em estoque.
   * Ex: Se existirem apenas 5 celulares Motorola Moto G50 em estoque, vendas a
   * partir de 6 unidades devem ser ignoradas.
   */
}

void Venda::aplicaDesconto(const std::string& fabricante, float desconto) {
  // TODO: Implemente este metodo
    for (auto it = m_celulares.begin(); it!=m_celulares.end(); it++){
        if(it->fabricante.compare(fabricante) == 0){
            it->valor_unitario-=(it->valor_unitario * (desconto/100));
        }
    }
}

void Venda::removeModelo(int cod) {
    
    for (auto it = m_celulares.begin(); it!=m_celulares.end(); it++){
        if(it->cod == cod){
            m_celulares.erase(it);
            break;
        }
    }
}

void Venda::imprimeEstoque() const {
    for(Celular celular: m_celulares){
        if(celular.quantidade >= 1){
            celular.modelo.front() = std::toupper(celular.modelo.front());
            celular.fabricante.front() = std::toupper(celular.fabricante.front());
            celular.cor.front() = std::toupper(celular.cor.front());
            std::cout << std::fixed;
            std::cout << std::setprecision(2);
            if (celular.quantidade == 1){
                std::cout << celular.fabricante << " " << celular.modelo << ", ";
                std::cout << celular.armazenamento << "GB, " <<celular.memoria << "GB RAM, ";
                std::cout << (int) (celular.peso * 1000) << " gramas, " << celular.cor << ", " << celular.quantidade;
                std::cout << " restante, R$ " << celular.valor_unitario << std::endl;
            }else{
                std::cout << celular.fabricante << " " << celular.modelo << ", ";
                std::cout << celular.armazenamento << "GB, " <<celular.memoria << "GB RAM, ";
                std::cout << (int) (celular.peso * 1000) << " gramas, " << celular.cor << ", " << celular.quantidade;
                std::cout << " restantes, R$ " << celular.valor_unitario << std::endl;
                
            }
        }
    }  
    
  // TODO: Implemente este metodo.
  /**
   * Aqui voce tera que imprimir a lista de celulares em estoque com as
   * restricoes descritas no enunciado do problema. Notem no exemplo que a
   * primeira letra da cor do celular fica maiuscula. Outra coisa, se houver
   * apenas um item em estoque de determinado modelo de celular, voce tera que
   * imprimir '1 restante' e nao '1 restantes'. Por ultimo, apenas modelos de
   * celulares com pelo menos um item em estoque deverao ser exibidos.
   */
}