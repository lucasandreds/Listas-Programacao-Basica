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
        FILE *arquivoEscritaPrimos = fopen("primos.txt","w + t");
        if(arquivoEscritaPrimos !=NULL){
            FILE *arquivoEscritaOutros = fopen("outros.txt","w + t");
            if(arquivoEscritaOutros !=NULL){
                while(!feof(arquivoLeitura)){
                    fscanf(arquivoLeitura,"%d",&valorLido);
                    if(primo(valorLido)) fprintf(arquivoEscritaPrimos,"%d\n",valorLido);
                    else fprintf(arquivoEscritaOutros,"%d\n",valorLido);
                }
                fclose(arquivoEscritaOutros);
            }else printf("Erro ao tentar abrir o arquivo de escrita dos outros\n");
            fclose(arquivoEscritaPrimos);
        }else printf("Erro ao tentar abrir o arquivo de escrita dos primos\n");
        fclose(arquivoLeitura);
    }else printf("Erro ao tentar abrir o arquivo de leitura\n");

    return 0;
}