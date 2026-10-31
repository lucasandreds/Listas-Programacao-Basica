#include "venda.hpp"

#include <iomanip>

Venda::~Venda() {
  // TODO: Implemente este metodo
  /**
   * Aqui voce deve deletar os ponteiros contidos na lista m_pedidos
   */
  for (auto it = m_pedidos.begin(); it!=m_pedidos.end(); it++){
    delete (*it);
  }
}

void Venda::adicionaPedido(Pedido* p) {
  // TODO: Implemente este metodo
  m_pedidos.push_back(p);
}

void Venda::imprimeRelatorio() const {
  // TODO: Implemente este metodo
  /**
   * Aqui voce tem que percorrer a lista de todos os pedidos e imprimir o resumo
   * de cada um. Por ultimo, devera ser exibido o total de venda e a quantidade
   * de pedidos processados.
   */
  int numero_pedidos = 0;
  float total_vendas = 0;

  for (auto it = m_pedidos.begin(); it!=m_pedidos.end(); it++){
    numero_pedidos ++;
    std::cout << "Pedido " << numero_pedidos << std::endl;
    std::cout << (*it)->resumo();
    total_vendas += (*it)->calculaTotal();
  }
  std::cout << std::fixed;
  std::cout << std::setprecision(2);
  std::cout << "Relatorio de Vendas" << std::endl;
  std::cout << "Total de vendas: R$ " << total_vendas <<  std::endl;
  std::cout << "Total de pedidos: " << numero_pedidos << std::endl;

}