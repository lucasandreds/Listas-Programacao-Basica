#include "pedido.hpp"


Pedido::~Pedido() {
  // TODO: Implemente este metodo.
  /**
   * Aqui voce deve deletar os ponteiros contidos na lista m_produtos
   */
  for (auto it = m_produtos.begin(); it!=m_produtos.end(); it++){
    delete (*it);
  }
}

void Pedido::setEndereco(const std::string& endereco) {
  // TODO: Implemente este metodo.
  m_endereco = endereco;
}

float Pedido::calculaTotal() const {
  // TODO: Implemente este metodo.
  float valor_total = 0;
  for (auto it = m_produtos.begin(); it!=m_produtos.end(); it++){
    valor_total += ((*it)->getValor() * (*it)->getQtd());
  }

  return valor_total;
}

void Pedido::adicionaProduto(Produto* p) {
  // TODO: Implemente este metodo.
  m_produtos.push_back(p);
}

std::string Pedido::resumo() const {
  // TODO: Implemente este metodo.
  /**
   * Aqui voce deve percorrer a lista de produtos para criar um resumo completo
   * do pedido. A cada iteracao, utilize o metodo descricao de cada produto para
   * montar o resumo do pedido. Por fim, adicione o endereco de entrega.
   *
   */

  std::string pedido;

  for (auto it = m_produtos.begin(); it!=m_produtos.end(); it++){
    pedido.append((*it)->descricao());
    pedido.append("\n");
  }
  pedido.append("Endereco: " + m_endereco);
  pedido.append("\n");

  return pedido;
}