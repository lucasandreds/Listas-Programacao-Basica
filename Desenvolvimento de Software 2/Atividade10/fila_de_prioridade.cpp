#include "fila_de_prioridade.h"

struct No{
    No *proximo;
    No *anterior;
    int idade;
    string nome;
};

FilaDePrioridade::FilaDePrioridade(){
    tamanho_ = 0;
    primeiro_ = nullptr;
}

string FilaDePrioridade::primeiro() const{
    return primeiro_->nome;
}

int FilaDePrioridade::tamanho() const{
    return tamanho_;
}

bool FilaDePrioridade::vazia() const{
    return (tamanho_ == 0);
}  

void FilaDePrioridade::RemoverPrimeiro(){
    if(primeiro_ != nullptr){
        No *atual = primeiro_;
        if((primeiro_->proximo != nullptr) ){
            primeiro_ = primeiro_->proximo;
            primeiro_->anterior = nullptr;
        }
        delete atual;
    }
    tamanho_ --;
}

void FilaDePrioridade::Inserir(int p, string s){
    No *novo = new No();
    novo->idade = p;
    novo->nome = s;
    if(tamanho_ == 0){
        novo->anterior = nullptr;
        novo->proximo = nullptr;
        primeiro_ = novo;
    }else{
        No *rodar = primeiro_;
        while((rodar->idade >= p) && (rodar->proximo != nullptr)){
            rodar = rodar->proximo;
        }

        if((rodar->anterior == nullptr) && (rodar->idade < p)){
            novo->anterior = nullptr;
            rodar->anterior = novo;
            novo->proximo = rodar;
            primeiro_ = novo;
        }else if((rodar->proximo == nullptr && (rodar->idade >= p))){
            novo->anterior = rodar;
            rodar->proximo = novo;
            novo->proximo = nullptr;
        }else{
            novo->anterior = rodar->anterior;
            rodar->anterior->proximo = novo;
            rodar->anterior = novo;
            novo->proximo = rodar;
        }
/*
26 prox:nullptr ant:54 

54 ant:nullptr prox: 26 primeiro

35 

João 26 Marcos 54 Maria 35 Ana 65 Bia 35

*/
    }
    tamanho_++;
}

void FilaDePrioridade::Limpar(){
    No *atual = primeiro_;
    while(atual->proximo != nullptr){
        atual = atual->proximo;
        delete (atual->anterior);
    }
    delete atual;
    tamanho_ = 0;
}