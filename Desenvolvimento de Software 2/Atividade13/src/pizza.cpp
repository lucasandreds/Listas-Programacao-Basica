#include "pizza.hpp"

std::string Pizza::descricao() const {
  // TODO: Implemente este metodo.
  /*
   * Note que aqui voce deve retornar uma descricao detalhada da pizza.
   *
   * Exemplos:
   * 2X Pizza Calabresa, 4 pedacos e borda recheada.
   * 2X Pizza Calabresa, 4 pedacos sem borda recheada.
   */

  std::string pedido = "";
  pedido.append(std::to_string(m_qtd));
  pedido.append("X Pizza " + sabor + ", ");
  pedido.append(std::to_string(pedacos) + " pedacos e "); 
  if(borda_recheada){
    pedido.append("borda recheada.");
    return pedido;
  }

  pedido.append("sem borda recheada.");
  return pedido;
}

Pizza::Pizza(const std::string& sabor,
             int pedacos,
             bool borda_recheada,
             int qtd,
             float valor_unitario) {
  this->sabor = sabor;
  this->pedacos = pedacos;
  this->borda_recheada = borda_recheada;
  this->m_qtd = qtd; 
  this->m_valor_unitario = valor_unitario;
  // TODO: Implemente este metodo.
}