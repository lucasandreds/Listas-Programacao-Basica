#include <stdio.h>

int main(){
    float valorLido;
    FILE *arquivoLeitura = fopen("numerosReais.txt","r + t");
    if(arquivoLeitura !=NULL){
        FILE *arquivoEscrita = fopen("funcaoValoresPadroes.txt","w + t");
        if(arquivoEscrita !=NULL){
            while(!feof(arquivoLeitura)){
                fscanf(arquivoLeitura,"%f",&valorLido);
                fprintf(arquivoEscrita,"x = %.2f: x² - 5x + 1 = %.2f \n",valorLido,((valorLido*valorLido) - (5 * valorLido) + 1));
            }
            fclose(arquivoEscrita);
        }else printf("Erro ao tentar abrir o arquivo de escrita\n");
        fclose(arquivoLeitura);
    }else printf("Erro ao tentar abrir o arquivo de leitura\n");

    return 0;
}