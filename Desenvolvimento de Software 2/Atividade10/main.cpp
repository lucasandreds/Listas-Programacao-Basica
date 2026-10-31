#include <iostream>
#include <string>
#include "fila_de_prioridade.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main() {
  FilaDePrioridade fila;
  // Lê os dados e insere na fila de prioridade.
  string nome;
  int idade;

  /*
  while (cin >> nome >> idade) {
    fila.Inserir(idade, nome);
  }
  */
 fila.Inserir(10,"Pizza");
 fila.Inserir(11, "Hamburguer");
  fila.Inserir(12, "Antonieta");
  // Imprime os nomes em ordem de prioridade.
  while (!fila.vazia()) {
    cout << fila.primeiro() << endl;
    fila.RemoverPrimeiro();
  } 
  return 0;
}

