#include <stdio.h>

bool primo(int x){
    if(x > 1){
        for (int i = x - 1; i > 1; i--)
            if (x % i == 0) return false;
        return true;
    } else return false;
}

int main(){
    int valorLido;
    FILE *arquivoLeitura = fopen("numerosNaturais.txt","r + t");
    if(arquivoLeitura !=NULL){
        FILE *arquivoEscrita = fopen("ehPrimo.txt","w + t");
        if(arquivoEscrita !=NULL){
            while(!feof(arquivoLeitura)){
                fscanf(arquivoLeitura,"%d",&valorLido);
                fprintf(arquivoEscrita,"%d - %d \n",valorLido,primo(valorLido));
            }
            fclose(arquivoEscrita);
        }else printf("Erro ao tentar abrir o arquivo de escrita\n");
        fclose(arquivoLeitura);
    }else printf("Erro ao tentar abrir o arquivo de leitura\n");

    return 0;
}