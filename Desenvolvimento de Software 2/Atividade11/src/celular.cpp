#include "celular.hpp"

// TODO: Inicialize aqui sua variavel estatica. Caso tenha optado por essa
// solucao.
int Celular::fix_cod = 0;

Celular::Celular(std::string modelo,
                 std::string fabricante,
                 int armazenamento,
                 int memoria,
                 double peso,
                 std::string cor,
                 int qtd,
                 float valor) {
  // TODO: Implemente este metodo
  fix_cod++;
  cod = fix_cod;
  this->modelo = modelo;
  this->fabricante = fabricante;
  this->armazenamento = armazenamento;
  this->memoria = memoria;
  this->peso = peso;
  this->cor = cor;
  this->quantidade = qtd;
  this->valor_unitario = valor;
}

bool Celular::operator<(const Celular& other) {
  // TODO: Implemente este metodo. 
  // Preste atencao no exemplo que a descricao utilizada na ordenacao considera
  // a fabricante antes do modelo do celular
    for(unsigned int i=0; ((i < (this->fabricante.size())) && (i < other.fabricante.size())); i++){
        if(std::toupper(this->fabricante.at(i)) < std::toupper(other.fabricante.at(i))){
            return true;
        }else if(std::toupper(this->fabricante.at(i)) > std::toupper(other.fabricante.at(i))){
            return false;
        }
    }
    
    for(unsigned int i=0; ((i< (this->modelo.size())) && (i < other.modelo.size())); i++){
        if(std::toupper(this->modelo.at(i)) < std::toupper(other.modelo.at(i))){
            return true;
        }else if(std::toupper(this->modelo.at(i)) > std::toupper(other.modelo.at(i))){
            return false;
        }
    }   
    
  return false;
}
    