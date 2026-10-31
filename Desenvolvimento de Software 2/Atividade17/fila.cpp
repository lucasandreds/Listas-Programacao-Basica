#include "fila.h"

struct No {
  int chave;
  No* proximo;
}; 

Fila::Fila() {
  primeiro_ = nullptr;
  ultimo_ = nullptr;
}

Fila::~Fila(){
  if(primeiro_!= nullptr){
    while(primeiro_->proximo!= nullptr){
      RemoverPrimeiro();
    }
    delete primeiro_;
  }
}

void Fila::Inserir(int k) {
  No *novo = new No();
  novo->chave = k;
  novo->proximo = nullptr;
  if(primeiro_ == nullptr){
    primeiro_ = novo;
    ultimo_ = novo;
  }else{
    ultimo_->proximo = novo;
    ultimo_ = novo;
  }
}

void Fila::RemoverPrimeiro() {
  if(primeiro_== nullptr){
    throw ExcecaoFilaVazia();
  }

  if(primeiro_ != nullptr){
    No *atual = primeiro_;

    if (primeiro_->proximo != nullptr){
      primeiro_ = primeiro_->proximo;
    }else{
      primeiro_ = nullptr;
      ultimo_ = nullptr;
    }
    delete atual;
  }
}

int Fila::primeiro() const {
  if(primeiro_==nullptr){
    throw ExcecaoFilaVazia();
  }
  return primeiro_->chave;
}

int Fila::ultimo() const {
  if(ultimo_==nullptr){
    throw ExcecaoFilaVazia();
  }
  return ultimo_->chave;
}

int Fila::tamanho() const {
  int tamanho = 0;
  if(primeiro_!=nullptr){
    No *atual = primeiro_;
    tamanho++;
    while(atual->proximo != nullptr){
      tamanho++;
      atual = atual->proximo;
    }
  }

  return tamanho; // TODO
}